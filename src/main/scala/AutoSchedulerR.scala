package sepia

import scala.collection.mutable.{Map => MMap}
import scala.io.StdIn.readChar
import scala.io.StdIn.readInt

trait AutoSchedulerR extends PipelineForCompiler with AutoschedulerUtils
  with AstAutoOps with CompilerFuncOps
  with CompilerImageOps with CostModel{

  val maxTiling: Int = 64
  val xExtent = 32
  val yExtent = 32
  val testmode = true
  var picky: Boolean = true

  private def printInfo(sched: Schedule): Unit = {
    println(f"----------------------------------\n " +
      f"Autoschedule\n" +
      f"...initial sched: $sched\n" +
      f"...function costs: ${callGraph.getCosts()}\n" +
      f"----------------------------------\n")

    println("Choose???(y/n): ")
    picky = readChar() match {
      case 'y' => true
      case _ => false
    }
  }

  //simple for now
  //highest producer?
  private def nextStage(stage: Int) : Int = {
    stage - 1
  }

  override def generateOptSchedule[T:Typ:Numeric:SepiaNum, U:Typ:Numeric:SepiaNum](sched: Schedule, f: Func[T], expX: Int, expY: Int, cost: String): (Schedule, Func[T]) = {
    printInfo(sched)

    initCostModel(expX, expY, "cCost")

    //pendingSchedules  - list of schedules to be processed in stage
    //scheduleList      - result of processing schedules in stage
    var pendingSchedules: Array[Schedule] = Array()
    var scheduleList: Array[Schedule] = Array()

    //stage currently processed
    var stage: Int = f.id

    scheduleList = scheduleList :+ sched.copy

    while(stage != -1) {

      pendingSchedules = scheduleList
      scheduleList = Array[Schedule]()

      println(f"\n\nIn stage $stage, ${pendingSchedules.length} schedules will be processed")

      for (s <- pendingSchedules) {
        println(f"...processing schedule ${pendingSchedules.indexOf(s, 0)}")
        scheduleList = scheduleList ++ generateChildrenFor[T, U](s, stage)
      }

      stage = nextStage(stage)
    }

    val optimalSchedule = if (picky) pickFrom(scheduleList)
                          else bestFrom(scheduleList)

    val scheduledFinal = scheduledFunctionFor(f.id, optimalSchedule, true)
      .getOrElse(throw new InvalidSchedule("We lost the final func along the way"))
      .asInstanceOf[Func[T]]

    (optimalSchedule, scheduledFinal)
  }

  //generate options for computing producer
  private def generateChildrenFor[T:Typ:Numeric:SepiaNum, U:Typ:Numeric:SepiaNum](sched: Schedule, stage: Int): Array[Schedule] = {

    var scheduleList: Array[Schedule] = Array()
    var numberOfChildrenCreated = 0;

    //original func from CallGraph
    var producer: Func[U] = toFunc[U](stage)
    //inline
    println(f"......inline $producer")
    scheduleList = scheduleList :+ sched.copy()

    //tile and realize somewhere
    println(f"......tile & realize $producer")
    scheduleList = scheduleList ++ tileAndRealize(producer, sched)

    scheduleList
  }

  private def tileAndRealize[T:Typ:Numeric:SepiaNum](producer: Func[T], sched: Schedule) = {

    var scheduleList: Array[Schedule] = Array()
    var realizations: Array[Schedule] = Array()

    printScheduledConsumers(producer.id, sched)
    printScheduledAncestors(producer.id, sched)

    //multiple consumers/ancestors, finalFunc
    if (hasMultipleScheduledAncestors(producer.id, sched) || producer.finalFunc) {
      realizations = realizations :+ realizeRoot(sched, producer)

    //single or no consumer/ancestor
    } else if (!hasScheduledAncestor(producer.id, sched)) {
      realizations = Array()

    } else {
      var scheduledAncestor: Func[T] = scheduledAncestorFor(producer.id, sched)
        .headOption.getOrElse(throw new UnexpectedBehavior("No consumer found")).asInstanceOf[Func[T]]

      realizations = realizations ++ realize(sched, producer, scheduledAncestor)
    }

    for (r <- realizations) {
      var scheduledProducer: Func[T] = scheduledFunctionFor(producer.id, r, false)
        .getOrElse(throw new UnexpectedBehavior("Producer not scheduled")).asInstanceOf[Func[T]]

      vectorizationOptionsFor(scheduledProducer).foreach({
        case vectorWidth => {
          tilingOptionsFor(scheduledProducer, vectorWidth, r).foreach({
            case (sfx, sfy) => {
              scheduleList = scheduleList :+ tile(r, scheduledProducer, sfx, sfy, vectorWidth)
            }
          })
        }
      })
    }

    scheduleList
  }

  private def realizeRoot[T:Typ:Numeric:SepiaNum](sched: Schedule, producer: Func[T]): Schedule = {
    var prod = producer.copy()
    computeAtRoot(swapFunction(sched.copy(), prod), prod)
  }

  private def realize[T:Typ:Numeric:SepiaNum, U:Typ:Numeric:SepiaNum](sched: Schedule, producer: Func[T], consumer: Func[U]):  Array[Schedule] = {

    var scheduleList: Array[Schedule] = Array()

    //computeRoot
    scheduleList = scheduleList :+ realizeRoot(sched, producer)

    // deInlineProducer
    var prod = producer.copy()
    var s = deInlineProducer(prod, consumer, swapFunction(sched.copy(), prod))

    //realize and compute somewhere
    //println(storeAtOptions(prod, s))
    storeAtOptions(prod, s).foreach({
      case (sf, sDimList) => {
        sDimList.foreach({
          case sDim => {
            var prodcop = prod.copy()
            var sfcp = sf.copy().asInstanceOf[Func[T]]

            println(f"......store at function $sf, dim $sDim")
            var tempSched = storefAtX(swapFunction(swapFunction(s.copy(), sfcp), prodcop), prodcop, sfcp, sDim)

            computeAtOptions(prodcop, tempSched, sfcp, sDim).foreach({
              case (cf, cDimList) => {
                cDimList.foreach({
                  case cDim => {
                    var prodcop2 = prodcop.copy()
                    var sfcp2 = sfcp.copy()
                    var cfcp = cf.copy().asInstanceOf[Func[T]]

                    var tempSched2 = updateStoreAtDim(tempSched, prodcop2, sfcp2)

                    println(f".........compute at function $cf,  dim $cDim")
                    tempSched2 = computefAtX(swapFunction(swapFunction(tempSched2.copy(), cfcp), prodcop2), prodcop2, cfcp, cDim)

                    scheduleList = scheduleList :+ tempSched2

                    //                    println(f"......storeSchedule - producer occurs: ${functionOccursIn(tempSched, prod)}")
                    //                    println(f"......storeSchedule - storefunctions occurs: ${functionOccursIn(tempSched, sf)}")
                    //                    println(f"......computeSchedule - producer occurs: ${functionOccursIn(tempSched2, prod)}")
                    //                    println(f"......computeSchedule - prodcop occurs: ${functionOccursIn(tempSched2, prodcop)}")
                    //                    println(f"......computeSchedule - computefunction occurs: ${functionOccursIn(tempSched2, cf)}")
                    //                    println(f"......computeSchedule - storefunctions occurs: ${functionOccursIn(tempSched2, sf)}")

                  }
                })
              }
            })
          }
        })
      }
    })

    scheduleList
  }

  //tiling options for consumer including no tiling and splits
  //considering only multiples of vectorWidth if vectorized
  private def tilingOptionsFor[T:Typ:Numeric:SepiaNum](func: Func[T], vectorWidth: Int, sched: Schedule): Array[(Int, Int)] = {

    def log2(num: Int): Int = {
      (math.log(num) / math.log(2)).floor.toInt
    }

    var sfx: Int = math.min(maxTiling, getEnclosingSplitFactor(func, sched, "x"))
    var sfy: Int = math.min(maxTiling, getEnclosingSplitFactor(func, sched, "y"))

    var tilings : Array[(Int,Int)] = Array()

    for {
      x <- log2(vectorWidth) to log2(sfx) by math.max(1, log2(vectorWidth))
      y <- 0 to log2(sfy)
    } tilings = tilings :+ (math.pow(2,x).toInt, math.pow(2,y).toInt)

    //like halide add tiling for sf*3
    if (testmode && tilings.nonEmpty) Array(tilings(tilings.length/2)) else tilings
  }

  private def vectorizationOptionsFor[T:Typ:Numeric:SepiaNum](func: Func[T]): List[Int] = {
    val extent = getEnclosingSplitFactor(func, sched, "x")

    List(1) //++ (4 to 16 by 4).filter(_ < extent)
  }

  private def tile[T:Typ:Numeric:SepiaNum](sched: Schedule, producer: Func[T],
                                           sfx: Int, sfy: Int, vectorWidth: Int): Schedule = {
    // tile/split consumer
    var prod = producer.copy()
    tileAndVectorize(swapFunction(sched.copy(), prod), prod, "x", "y", "xo", "yo", "xi", "yi", sfx, sfy, vectorWidth)
  }

  private def tileAndVectorize[T:Typ:Numeric:SepiaNum](sched: Schedule, func: Func[T], x: String, y: String,
                                                       xOuter: String, yOuter: String, xInner: String,
                                                       yInner: String, xSplit: Int, ySplit: Int, vectorWidth: Int): Schedule = {
    (xSplit, ySplit) match {
      case (1, 1) => {
        autoVectorize(sched, func, x, vectorWidth);
      }
      case (xSplit, 1) => {
        func.split(x, xOuter, xInner, xSplit)
        sched = splitLoopNode(sched, func.vars(x), func.vars(xOuter), func.vars(xInner))

        autoVectorize(sched, func, xInner, vectorWidth);
      }
      case (1, ySplit) => {
        func.split(y, yOuter, yInner, ySplit)
        sched = splitLoopNode(sched, func.vars(y), func.vars(yOuter), func.vars(yInner))

        autoVectorize(sched, func, x, vectorWidth);
      }
      case (xSplit, ySplit) => {
        func.split(x, xOuter, xInner, xSplit)
        sched = splitLoopNode(sched, func.vars(x), func.vars(xOuter), func.vars(xInner))

        func.split(y, yOuter, yInner, ySplit)
        sched = splitLoopNode(sched, func.vars(y), func.vars(yOuter), func.vars(yInner))

        sched = swapLoopNodes(sched, func.vars(yInner), func.vars(xOuter))
        autoVectorize(sched, func, xInner, vectorWidth);
      }
    }
  }

  private def autoVectorize[T:Typ:Numeric:SepiaNum](sched: Schedule, func: Func[T], x: String, vectorWidth: Int) = {
    vectorWidth match {
      case 1 => sched
      case width => {
        func.split(x, x + "_outer", x + "_inner", width)
        sched = splitLoopNode(sched, func.vars(x), func.vars(x + "_outer"), func.vars(x + "_inner"))
        vectorizeLoop(sched, func.vars(x + "_inner"), width)
      }
    }
  }

  private def pickFrom(scheduleList: Array[Schedule]): Schedule = {
    val topTen = pickNBest(10, scheduleList)
    println(f"----------------------------------\n" +
      f"${scheduleList.length} schedules generated\n\n" +
      f"Best 10 schedules:")
    topTen.foreach(println)

    print(f"Pick your poison:")
    topTen(readInt())._2
  }

  private def bestFrom(scheduleList: Array[Schedule]): Schedule = {
    val best = pickBest(scheduleList)
    println(f"Returning best Schedule with cost ${best._1} is: \n${best._2}")
    best._2
  }







  //sanity check for copying
  def functionOccursIn(sched: Schedule, func: Func[_]): Boolean = {

    def occursInNodeFunction(f: Func[_]): Boolean = {
      if (f == func) true
      else if (f.vars.exists({ case (k,v) => occursInDimension(Some(v)) })) true
      else if (occursInDimension(f.storeAt)) true
      else if (occursInDimension(f.computeAt)) true
      else false
    }

    def occursInDimension(dim: Option[Dim]): Boolean = {
      dim match {
        case Some(dim) if dim.isInstanceOf[OuterDim] => {
          var d = dim.asInstanceOf[OuterDim]
          if (d.f == func) true
          else if (d.old == func) true
          else false
        }
        case Some(dim) if dim.isInstanceOf[SplitDim] => {
          var d = dim.asInstanceOf[SplitDim]
          if (d.f == func) true
          else if (d.outer.f == func) true
          else if (d.inner.f == func) true
          else false
        }
        case Some(dim) =>  dim.f == func
        case None => false
      }
    }

    def containsFunc(node: Schedule, func: Func[_]): Boolean = {
      node match {
        case r@RootNode(otherChildren) => {
          r.getChildren.exists(_.exists(containsFunc(_, func)))
        }
        case c@ComputeNode(s, otherChildren) => {
          if (occursInNodeFunction(s)) true
          else c.getChildren.exists(_.exists(containsFunc(_, func)))
        }
        case st@StorageNode(s, otherChildren) => {
          if (occursInNodeFunction(s)) true
          else st.getChildren.exists(_.exists(containsFunc(_, func)))
        }
        case l@LoopNode(v, s, loopType,  otherChildren) => {
          if (occursInDimension(Some(v))) true
          else if (occursInNodeFunction(s)) true
          else l.getChildren.exists(_.exists(containsFunc(_, func)))
        }
      }
    }
    containsFunc(sched, func)
  }

  def sameFuncs(sched: Schedule, func: Func[_]): Boolean = {
    sched match {
      case r@RootNode(otherChildren) => {
        !r.getChildren.exists(_.exists(!sameFuncs(_, func)))
      }
      case c@ComputeNode(s, otherChildren) => {
        if (s != func && s.id == func.id) false
        else !c.getChildren.exists(_.exists(!sameFuncs(_, func)))
      }
      case st@StorageNode(s, otherChildren) => {
        if (s != func && s.id == func.id) false
        else !st.getChildren.exists(_.exists(!sameFuncs(_, func)))
      }
      case l@LoopNode(v, s, loopType,  otherChildren) => {
        if (s != func && s.id == func.id) false
        else !l.getChildren.exists(_.exists(!sameFuncs(_, func)))
      }
    }
  }
}
