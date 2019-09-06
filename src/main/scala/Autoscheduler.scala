package sepia

trait Autoscheduler extends PipelineForCompiler
                    with AstAutoOps with CompilerFuncOps
                    with CompilerImageOps {

  val maxTiling: Int = 64

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
  private def consumerOf[T:Typ:Numeric:SepiaNum](producer: Int): Int = {
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

    tilings
  }

  //tiling options for consumer including no tiling and splits
  private def tilingOptionsFor[T:Typ:Numeric:SepiaNum](consumer: Func[T]): Array[(Int, Int)] = {
    consumerOf[T](consumer.id) match {
      case c if c != -1 => {
        var cons: Func[T] = toFunc(c)
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




  override def generateOptSchedule[T:Typ:Numeric:SepiaNum, U:Typ:Numeric:SepiaNum](sched: Schedule, f: Func[T], f2: Func[U]): Schedule = {

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

      pendingSchedules = scheduleList
      scheduleList = Array[Schedule]()

      for (s <- pendingSchedules) {
        scheduleList = scheduleList ++ generateNextOptionsFrom(s, toFunc[T](stage), toFunc[T](producerOf(stage)))
      }

      stage = nextStage(stage)
    }

    println(scheduleList(3).asInstanceOf[RootNode].children(0))
    println(f"\n Sched: ${scheduleList(3)}")

    scheduleList(3)
  }

  // generate options for computing producer
  def generateNextOptionsFrom[T:Typ:Numeric:SepiaNum, U:Typ:Numeric:SepiaNum](s: Schedule, consumer: Func[T], producer: Func[U]): Array[Schedule] = {

    var pendingSchedules: Array[Schedule] = Array()
    var numberOfOptionsCreated = 0;

    // compute and store granularity
    // + inline
    // + compute Root
    // + realize and compute in loopnest

    println(f"Schedule: $s")
    //1) inline
    println(f"inline $producer\n")
    pendingSchedules = pendingSchedules :+ s.copy()

    //2) computeRoot
    println(f"compute at root $producer\n")
    var procop = producer.copy()
    pendingSchedules = pendingSchedules :+ computeAtRoot(swapFunction(s.copy(), procop), procop)

    //2) tile and realize somewhere
    println(f"tile & realize $producer in $consumer\n")
    if (!consumer.inlined)
      pendingSchedules = pendingSchedules ++ tileAndRealize(s, consumer, producer)


    for (s <- pendingSchedules) {
      println(s)
    }

    pendingSchedules
  }

  private def tileAndRealize[T:Typ:Numeric:SepiaNum, U:Typ:Numeric:SepiaNum](s: Schedule, cons: Func[T], prod: Func[U]) = {
    assert(!cons.inlined)

    var scheduleList: Array[Schedule] = Array()

    tilingOptionsFor(cons).foreach({
      case (sfx, sfy) => scheduleList = scheduleList ++ realizeInTiles(s, cons, prod, sfx, sfy)
    })

    scheduleList
  }

  private def realizeInTiles[T:Typ:Numeric:SepiaNum, U:Typ:Numeric:SepiaNum](s: Schedule, cons: Func[T], prod: Func[U], sfx: Int, sfy: Int): Array[Schedule] = {

    println(f"...tiling ($sfx, $sfy)")

    var scheduleList: Array[Schedule] = Array()

    cons = cons.copy()

    // tile/split consumer
    s = autoTile(swapFunction(s.copy(), cons), cons, "x", "y", "xo", "yo", "xi", "yi", sfx, sfy)

    // deInlineProducer
    s = deInlineProducer(prod, cons, s)

    // realize and compute somewhere
    storeAtOptions(prod, s).foreach({
      case (sf, sDimList) => {
        sDimList.foreach({
          case sDim => {
            var prodcop = prod.copy()
            var conscop = cons.copy()

            println(f"......store at function $sf, dim $sDim")
            var tempSched = storefAtX(swapFunction(swapFunction(s.copy(), conscop), prodcop), prodcop, conscop, sDim)

            computeAtOptions(prodcop, tempSched, sf, sDim).foreach({
              case (cf, cDimList) => {
                cDimList.foreach({
                  case cDim => {
                    var prodcop2 = prodcop.copy()
                    var conscop2 = conscop.copy()

                    println(f".........compute at function $cf,  dim $cDim")
                    scheduleList = scheduleList :+ computefAtX(swapFunction(swapFunction(tempSched.copy(), conscop2), prodcop2), prodcop2, conscop2, cDim)

                  }
                })
              }
            })
          }
        })
      }
    })
    scheduleList

    //    generateRealizationOptions.foreach({
    //      case (storeDim, computeDim) => {
    //        var prodcop = prod.copy()
    //        var conscop = cons.copy()
    //
    //        println(f"......realization ($storeDim, $computeDim)")
    //
    //        var sched = computefAtX(swapFunction(swapFunction(s.copy(), conscop), prodcop), prodcop, conscop, computeDim)
    //        sched = storefAtX(sched, prodcop, conscop, storeDim)
    //
    //        scheduleList = scheduleList :+
    //
    //        sched
    //      }
    //    })
  }
}

