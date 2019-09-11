package sepia

trait Autoscheduler extends PipelineForCompiler
                    with AstAutoOps with CompilerFuncOps
                    with CompilerImageOps {

  val maxTiling: Int = 64
  val testmode = true

  //TODO: move into callGraph
  private def producerOf(consumer: Int): Int = {
    idToFunc.filter({
      case (id, f) => callGraph.isProducerConsumer(id, consumer)
    }).toList match {
      case x::Nil => x._1
      case Nil => -1
      case _ => throw new InvalidSchedule("Come back later")
    }
  }

  //TODO: move into callGraph
  private def consumerOf(producer: Int): Int = {
    idToFunc.filter({
      case (id, f) => callGraph.isProducerConsumer(producer, id)
    }).toList match {
      case x::Nil => x._1
      case Nil => -1
      case _ => throw new InvalidSchedule("Come back later")
    }
  }

  private def toFunc[T:Typ:Numeric:SepiaNum](stage: Int): Func[T] = {
    idToFunc(stage).asInstanceOf[Func[T]]
  }

  private def nextStage(stage: Int) : Int = {
    producerOf(stage)
  }

  private def isFirstDecision(dec: Int): Boolean = {
    dec % 2 == 0
  }

  //generate tiling options with powers of two
  private def generateTilingOptions(sfx: Int, sfy: Int): Array[(Int, Int)] = {

    def log2(num: Int): Int = {
      (math.log(num) / math.log(2)).floor.toInt
    }

    var tilings : Array[(Int,Int)] = Array()
    for {
      x <- 0 to log2(sfx)
      y <- 0 to log2(sfy)
    } tilings = tilings :+ (math.pow(2,x).toInt, math.pow(2,y).toInt)

    if (testmode) Array(tilings(tilings.length/2)) else tilings
  }

  //tiling options for consumer including no tiling and splits
  private def tilingOptionsFor[T:Typ:Numeric:SepiaNum](consumer: Func[T]): Array[(Int, Int)] = {
    consumerOf(consumer.id) match {
      case c if c != -1 => {
        var cons: Func[_] = idToFunc(c)
        var sfx = cons.vars("x") match {
          case dim if dim.isInstanceOf[SplitDim] => dim.asInstanceOf[SplitDim].splitFactor
          case _ => 64
        }
        var sfy = cons.vars("y") match {
          case dim if dim.isInstanceOf[SplitDim] => dim.asInstanceOf[SplitDim].splitFactor
          case _ => 64
        }
        generateTilingOptions(sfx, sfy)
      }
      case _ => generateTilingOptions(64, 64)
    }
  }

  private def autoTile[T:Typ:Numeric:SepiaNum](sched: Schedule, consumer: Func[T], x: String, y: String,
               xOuter: String, yOuter: String, xInner: String,
               yInner: String, xSplit: Int, ySplit: Int): Schedule = {

    (xSplit, ySplit) match {
      case (1, 1) => {
        sched
      }
      case (xSplit, 1) => {
        consumer.split(x, xOuter, xInner, xSplit)
        splitLoopNode(sched, consumer.vars(x), consumer.vars(xOuter), consumer.vars(xInner))
      }
      case (1, ySplit) => {
        consumer.split(y, yOuter, yInner, ySplit)
        splitLoopNode(sched, consumer.vars(y), consumer.vars(yOuter), consumer.vars(yInner))
      }
      case (xSplit, ySplit) => {
        consumer.split(x, xOuter, xInner, xSplit)
        sched = splitLoopNode(sched, consumer.vars(x), consumer.vars(xOuter), consumer.vars(xInner))

        consumer.split(y, yOuter, yInner, ySplit)
        sched = splitLoopNode(sched, consumer.vars(y), consumer.vars(yOuter), consumer.vars(yInner))

        swapLoopNodes(sched, consumer.vars(yInner), consumer.vars(xOuter))
      }
    }
  }

  def updateStoreAtDim(sched: Schedule, prod: Func[_], sf: Func[_]) = {
    prod.storeAt = prod.storeAt match {
      case Some(dim) => Some(sf.dim(dim.name))
      case None => throw new InvalidSchedule("No store at defined for Producer")
    }

    swapFunction(sched.copy(), sf)
  }


  override def generateOptSchedule[T:Typ:Numeric:SepiaNum, U:Typ:Numeric:SepiaNum](sched: Schedule, f: Func[T], f2: Func[U]): (Schedule, Func[T]) = {

    var stage: Int = f.id

    var scheduleList: Array[Schedule] = Array()
    var pendingSchedules: Array[Schedule] = Array()

    var numberOfDecisions = 0

    //--------------------------------------------------------------------------------------------

    println(f"----------------------------------\n " +
            f"Autoschedule\n" +
            f"...initial sched: $sched\n" +
            f"----------------------------------\n")

    sched match {
      case RootNode(_) => sched
      case _ => throw new InvalidSchedule("Root Node expected but not found")
    }

    //-----------------------------------------------------------
    // GENERATE OPTIONS
    //-----------------------------------------------------------
    scheduleList = scheduleList :+ sched.copy()

    while(nextStage(stage) != -1) {

      stage = nextStage(stage)
      println(f"\n\nIn stage(producer) $stage")

      pendingSchedules = scheduleList
      scheduleList = Array[Schedule]()

      for (s <- pendingSchedules) {
        println(f"...processing schedule ${pendingSchedules.indexOf(s, 0)}")
        scheduleList = scheduleList ++ generateNextOptionsFor[T, U](s, stage)
      }
    }



    println(f"----------------------------------\n " +
      f"${scheduleList.length} schedules generated\n\n" +
      f"Pick your poison:")


    val optimalSchedule = scheduleList(Console.readInt())


    println(f"Poison: $optimalSchedule\n" +
      f"----------------------------------\n")


    val scheduledFinal = scheduledFunctionFor(f.id, optimalSchedule, true)
      .getOrElse(throw new InvalidSchedule("We lost the final func along the way"))
      .asInstanceOf[Func[T]]

//    println(s"FunctionCheck: ${sameFuncs(optimalSchedule, scheduledFunctionFor(f.id, optimalSchedule, false).get)}")
//    println(s"FunctionCheck: ${sameFuncs(optimalSchedule, scheduledFunctionFor(f2.id, optimalSchedule, false).get)}")
    (optimalSchedule, scheduledFinal)
  }

  // generate options for computing producer
  def generateNextOptionsFor[T:Typ:Numeric:SepiaNum, U:Typ:Numeric:SepiaNum](s: Schedule, stage: Int): Array[Schedule] = {

    var pendingSchedules: Array[Schedule] = Array()
    var numberOfOptionsCreated = 0;

    var producer: Func[U] = toFunc[U](stage)
    var scheduledConsumer: Option[Func[_]] = scheduledFunctionFor(consumerOf(stage), s, false)


    // compute and store granularity
    // + inline
    // + compute Root
    // + realize and compute in loopnest

    //1) inline
    println(f"......inline $producer")
    pendingSchedules = pendingSchedules :+ s.copy()

    //2) computeRoot
    println(f"......compute at root $producer")
    var procop = producer.copy()
    pendingSchedules = pendingSchedules :+ computeAtRoot(swapFunction(s.copy(), procop), procop)

    //2) tile and realize somewhere
    println(f"......tile & realize $producer")
    pendingSchedules = scheduledConsumer match {
      case Some(consumer) => pendingSchedules ++ tileAndRealize(s, consumer.asInstanceOf[Func[T]], producer)
      case None => pendingSchedules
    }

    pendingSchedules
  }

  private def tileAndRealize[T:Typ:Numeric:SepiaNum, U:Typ:Numeric:SepiaNum](s: Schedule, consumer: Func[T], producer: Func[U]) = {
    assert(!consumer.inlined)

    var scheduleList: Array[Schedule] = Array()

    tilingOptionsFor(consumer).foreach({
      case (sfx, sfy) => {
        scheduleList = scheduleList ++ realizeInTiles(s, consumer, producer, sfx, sfy)
      }
    })

    scheduleList
  }

  private def realizeInTiles[T:Typ:Numeric:SepiaNum, U:Typ:Numeric:SepiaNum](s: Schedule, consumer: Func[T], producer: Func[U], sfx: Int, sfy: Int): Array[Schedule] = {

    println(f"...tiling ($sfx, $sfy)")

    var scheduleList: Array[Schedule] = Array()

    // tile/split consumer
    var cons = consumer.copy()
    s = autoTile(swapFunction(s.copy(), cons), cons, "x", "y", "xo", "yo", "xi", "yi", sfx, sfy)

    // deInlineProducer
    var prod = producer.copy()
    s = deInlineProducer(prod, cons, swapFunction(s, prod))

    // realize and compute somewhere
    storeAtOptions(prod, s).foreach({
      case (sf, sDimList) => {
        println("in")
        sDimList.foreach({
          case sDim => {
            var prodcop = prod.copy()
            var sfcp = sf.copy().asInstanceOf[Func[T]]

            println(f"......store at function $sf, dim $sDim")
            var tempSched = storefAtX(swapFunction(swapFunction(s.copy(), sfcp), prodcop), prodcop, sfcp, sDim)
            println(f"......s: producer occurs: ${functionOccursIn(tempSched, prod)}")
            println(f"......storefunctions occurs: ${functionOccursIn(tempSched, sf)}")

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
                    println(f"......c: producer occurs: ${functionOccursIn(tempSched2, prod)}")
                    println(f"......prodcop occurs: ${functionOccursIn(tempSched2, prodcop)}")
                    println(f"......computefunction occurs: ${functionOccursIn(tempSched2, cf)}")
                    println(f"......s: producer occurs: ${functionOccursIn(tempSched2, prod)}")
                    println(f"......storefunctions occurs: ${functionOccursIn(tempSched2, sf)}")

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


  //sanity check for copying
  def functionOccursIn(sched: Schedule, func: Func[_]): Boolean = {

    def occursInNodeFunction(f: Func[_]): Boolean = {
      if (f == func)  {
        println("1")
        true}
      else if (f.vars.exists({ case (k,v) => occursInDimension(Some(v)) }))  {
        println("2")
        true}
      else if (occursInDimension(f.storeAt))  {
        println("3")
        true}
      else if (occursInDimension(f.computeAt))  {
        println("4")
        true}
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