//package sepia
//
//trait Autoscheduler extends PipelineForCompiler
//                    with AstAutoOps with CompilerFuncOps
//                    with CompilerImageOps {
//
//  val maxTiling: Int = 64
//  val testmode = true
//
//  //TODO: move into callGraph
//  private def producerOf(consumer: Int): Int = {
//    idToFunc.filter({
//      case (id, f) => callGraph.isProducerConsumer(id, consumer)
//    }).toList match {
//      case x::Nil => x._1
//      case Nil => -1
//      case _ => throw new InvalidSchedule("Come back later")
//    }
//  }
//
//  //TODO: move into callGraph
//  private def consumerOf(producer: Int): Int = {
//    idToFunc.filter({
//      case (id, f) => callGraph.isProducerConsumer(producer, id)
//    }).toList match {
//      case x::Nil => x._1
//      case Nil => -1
//      case _ => throw new InvalidSchedule("Come back later")
//    }
//  }
//
//  private def toFunc[T:Typ:Numeric:SepiaNum](stage: Int): Func[T] = {
//    idToFunc(stage).asInstanceOf[Func[T]]
//  }
//
//  private def nextStage(stage: Int) : Int = {
//    producerOf(stage)
//  }
//
//  private def isFirstDecision(dec: Int): Boolean = {
//    dec % 2 == 0
//  }
//
//  //generate tiling options with powers of two
//  //considering only multiples of vectorWidth if vectorized
//  private def generateTilingOptions(sfx: Int, sfy: Int, vectorWidth: Int): Array[(Int, Int)] = {
//
//    def log2(num: Int): Int = {
//      (math.log(num) / math.log(2)).floor.toInt
//    }
//
//    var tilings : Array[(Int,Int)] = Array()
//    for {
//      x <- log2(vectorWidth) to log2(sfx) by math.max(1, log2(vectorWidth))
//      y <- 0 to log2(sfy)
//    } tilings = tilings :+ (math.pow(2,x).toInt, math.pow(2,y).toInt)
//
//    if (testmode) Array(tilings(tilings.length/2)) else tilings
//  }
//
//  //tiling options for consumer including no tiling and splits
//  private def tilingOptionsFor[T:Typ:Numeric:SepiaNum](consumer: Func[T], vectorWidth: Int): Array[(Int, Int)] = {
//    consumerOf(consumer.id) match {
//      case c if c != -1 => {
//        var cons: Func[_] = idToFunc(c)
//        var sfx = cons.vars("x") match {
//          case dim if dim.isInstanceOf[SplitDim] => dim.asInstanceOf[SplitDim].splitFactor
//          case _ => 64
//        }
//        var sfy = cons.vars("y") match {
//          case dim if dim.isInstanceOf[SplitDim] => dim.asInstanceOf[SplitDim].splitFactor
//          case _ => 64
//        }
//        generateTilingOptions(sfx, sfy, vectorWidth)
//      }
//      case _ => generateTilingOptions(64, 64, vectorWidth)
//    }
//  }
//
//  private def tileAndVectorize[T:Typ:Numeric:SepiaNum](sched: Schedule, consumer: Func[T], x: String, y: String,
//               xOuter: String, yOuter: String, xInner: String,
//               yInner: String, xSplit: Int, ySplit: Int, vectorWidth: Int): Schedule = {
//
//    (xSplit, ySplit) match {
//      case (1, 1) => {
//        autoVectorize(sched, consumer, x, vectorWidth);
//      }
//      case (xSplit, 1) => {
//        consumer.split(x, xOuter, xInner, xSplit)
//        sched = splitLoopNode(sched, consumer.vars(x), consumer.vars(xOuter), consumer.vars(xInner))
//
//        autoVectorize(sched, consumer, xInner, vectorWidth);
//      }
//      case (1, ySplit) => {
//        consumer.split(y, yOuter, yInner, ySplit)
//        sched = splitLoopNode(sched, consumer.vars(y), consumer.vars(yOuter), consumer.vars(yInner))
//
//        autoVectorize(sched, consumer, x, vectorWidth);
//      }
//      case (xSplit, ySplit) => {
//        consumer.split(x, xOuter, xInner, xSplit)
//        sched = splitLoopNode(sched, consumer.vars(x), consumer.vars(xOuter), consumer.vars(xInner))
//
//        consumer.split(y, yOuter, yInner, ySplit)
//        sched = splitLoopNode(sched, consumer.vars(y), consumer.vars(yOuter), consumer.vars(yInner))
//
//        sched = swapLoopNodes(sched, consumer.vars(yInner), consumer.vars(xOuter))
//        autoVectorize(sched, consumer, xInner, vectorWidth);
//      }
//    }
//  }
//
//  private def autoVectorize[T:Typ:Numeric:SepiaNum](sched: Schedule, consumer: Func[T], x: String, vectorWidth: Int) = {
//    vectorWidth match {
//      case 1 => sched
//      case width => {
//        consumer.split(x, x + "_outer", x + "_inner", width)
//        sched = splitLoopNode(sched, consumer.vars(x), consumer.vars(x + "_outer"), consumer.vars(x + "_inner"))
//        vectorizeLoop(sched, consumer.vars(x + "_inner"), width)
//      }
//    }
//  }
//
//  private def vectorizationOptionsFor[T:Typ:Numeric:SepiaNum](consumer: Func[T]): List[Int] = {
//    val extent = consumer.vars("x") match {
//      case dim => dim.max - dim.min + 1
//    }
//
//    List(1, 4) //++ (4 to 16 by 4).filter(_ < extent)
//  }
//
//  def updateStoreAtDim(sched: Schedule, prod: Func[_], sf: Func[_]) = {
//    prod.storeAt = prod.storeAt match {
//      case Some(dim) => Some(sf.dim(dim.name))
//      case None => throw new InvalidSchedule("No store at defined for Producer")
//    }
//
//    swapFunction(sched.copy(), sf)
//  }
//
//
//  private def initPrint(sched: Schedule): Unit = {
//    println(f"----------------------------------\n " +
//      f"Autoschedule\n" +
//      f"...initial sched: $sched\n" +
//      f"----------------------------------\n")
//  }
//
//  private def pickFrom(scheduleList: Array[Schedule]): Schedule = {
//    println(f"----------------------------------\n " +
//      f"${scheduleList.length} schedules generated\n\n" +
//      f"Pick your poison:")
//
//    scheduleList(Console.readInt())
//  }
//
//
//  override def generateOptSchedule[T:Typ:Numeric:SepiaNum, U:Typ:Numeric:SepiaNum](sched: Schedule, f: Func[T], f2: Func[U]): (Schedule, Func[T]) = {
//    initPrint(sched)
//
//    //pendingSchedules  - list of schedules to be processed in stage
//    //scheduleList      - result of processing schedules in stage
//    var pendingSchedules: Array[Schedule] = Array()
//    var scheduleList: Array[Schedule] = Array()
//
//    //stage currently processed(producer)
//    var stage: Int = f.id
//    var numberOfDecisions = 0
//
//
//    //-----------------------------------------------------------
//    // GENERATE OPTIONS
//    //-----------------------------------------------------------
//
//    scheduleList = scheduleList :+ sched.copy
//
//    while(nextStage(stage) != -1) {
//
//      println(f"\n\nIn stage(producer) $stage")
//      stage = nextStage(stage)
//
//      pendingSchedules = scheduleList
//      scheduleList = Array[Schedule]()
//
//      for (s <- pendingSchedules) {
//        println(f"...processing schedule ${pendingSchedules.indexOf(s, 0)}")
//        scheduleList = scheduleList ++ generateChildrenFor[T, U](s, stage)
//      }
//
//    }
//
//    val optimalSchedule = pickFrom(scheduleList)
//    val scheduledFinal = scheduledFunctionFor(f.id, optimalSchedule, true)
//      .getOrElse(throw new InvalidSchedule("We lost the final func along the way"))
//      .asInstanceOf[Func[T]]
//
////    println(s"FunctionCheck: ${sameFuncs(optimalSchedule, scheduledFunctionFor(f.id, optimalSchedule, false).get)}")
////    println(s"FunctionCheck: ${sameFuncs(optimalSchedule, scheduledFunctionFor(f2.id, optimalSchedule, false).get)}")
//    (optimalSchedule, scheduledFinal)
//  }
//
//  // generate options for computing producer
//  private def generateChildrenFor[T:Typ:Numeric:SepiaNum, U:Typ:Numeric:SepiaNum](s: Schedule, stage: Int): Array[Schedule] = {
//
//    var scheduleList: Array[Schedule] = Array()
//    var numberOfChildrenCreated = 0;
//
//    //original func from CallGraph
//    var producer: Func[U] = toFunc[U](stage)
//
//    //scheduled consumer for this specific schedule
//    var scheduledConsumer: Option[Func[_]] = scheduledFunctionFor(consumerOf(stage), s, false)
//
//
//    // compute and store granularity
//    // + inline
//    // + compute Root
//    // + realize and compute in loopnest
//
//    //1) inline
//    println(f"......inline $producer")
//    scheduleList = scheduleList :+ s.copy()
//
//    //2) computeRoot
//    println(f"......compute at root $producer")
//    var procop = producer.copy()
//    scheduleList = scheduleList :+ computeAtRoot(swapFunction(s.copy(), procop), procop)
//
//    //2) tile and realize somewhere
//    println(f"......tile & realize $producer")
//    scheduleList = scheduledConsumer match {
//      case Some(consumer) => scheduleList ++ tileAndRealize(s, consumer.asInstanceOf[Func[T]], producer)
//      case None => scheduleList
//    }
//
//    scheduleList
//  }
//
//  private def tileAndRealize[T:Typ:Numeric:SepiaNum, U:Typ:Numeric:SepiaNum](s: Schedule, consumer: Func[T], producer: Func[U]) = {
//    assert(!consumer.inlined)
//
//    var scheduleList: Array[Schedule] = Array()
//
//    vectorizationOptionsFor(consumer).foreach({
//      case vectorWidth => {
//        tilingOptionsFor(consumer, vectorWidth).foreach({
//          case (sfx, sfy) => {
//            scheduleList = scheduleList ++ realizeInTiles(s, consumer, producer, sfx, sfy, vectorWidth)
//          }
//        })
//      }
//    })
//
//    scheduleList
//  }
//
//  private def realizeInTiles[T:Typ:Numeric:SepiaNum, U:Typ:Numeric:SepiaNum](s: Schedule, consumer: Func[T], producer: Func[U],
//                                                                             sfx: Int, sfy: Int, vectorWidth: Int): Array[Schedule] = {
//
//    println(f"...tiling ($sfx, $sfy) with vectorization $vectorWidth")
//
//    var scheduleList: Array[Schedule] = Array()
//
//    // tile/split consumer
//    var cons = consumer.copy()
//    s = tileAndVectorize(swapFunction(s.copy(), cons), cons, "x", "y", "xo", "yo", "xi", "yi", sfx, sfy, vectorWidth)
//
//    println(s)
//    // deInlineProducer
//    var prod = producer.copy()
//    s = deInlineProducer(prod, cons, swapFunction(s, prod))
//
//    //realize and compute somewhere
//    println(storeAtOptions(prod, s))
//    storeAtOptions(prod, s).foreach({
//      case (sf, sDimList) => {
//        sDimList.foreach({
//          case sDim => {
//            var prodcop = prod.copy()
//            var sfcp = sf.copy().asInstanceOf[Func[T]]
//
//            println(f"......store at function $sf, dim $sDim")
//            var tempSched = storefAtX(swapFunction(swapFunction(s.copy(), sfcp), prodcop), prodcop, sfcp, sDim)
//
//            computeAtOptions(prodcop, tempSched, sfcp, sDim).foreach({
//              case (cf, cDimList) => {
//                cDimList.foreach({
//                  case cDim => {
//                    var prodcop2 = prodcop.copy()
//                    var sfcp2 = sfcp.copy()
//                    var cfcp = cf.copy().asInstanceOf[Func[T]]
//
//                    var tempSched2 = updateStoreAtDim(tempSched, prodcop2, sfcp2)
//
//                    println(f".........compute at function $cf,  dim $cDim")
//                    tempSched2 = computefAtX(swapFunction(swapFunction(tempSched2.copy(), cfcp), prodcop2), prodcop2, cfcp, cDim)
//
//                    scheduleList = scheduleList :+ tempSched2
//
////                    println(f"......storeSchedule - producer occurs: ${functionOccursIn(tempSched, prod)}")
////                    println(f"......storeSchedule - storefunctions occurs: ${functionOccursIn(tempSched, sf)}")
////                    println(f"......computeSchedule - producer occurs: ${functionOccursIn(tempSched2, prod)}")
////                    println(f"......computeSchedule - prodcop occurs: ${functionOccursIn(tempSched2, prodcop)}")
////                    println(f"......computeSchedule - computefunction occurs: ${functionOccursIn(tempSched2, cf)}")
////                    println(f"......computeSchedule - storefunctions occurs: ${functionOccursIn(tempSched2, sf)}")
//
//                  }
//                })
//              }
//            })
//          }
//        })
//      }
//    })
//    scheduleList
//  }
//
//  //sanity check for copying
//  def functionOccursIn(sched: Schedule, func: Func[_]): Boolean = {
//
//    def occursInNodeFunction(f: Func[_]): Boolean = {
//      if (f == func)
//        true
//      else if (f.vars.exists({ case (k,v) => occursInDimension(Some(v)) }))
//        true
//      else if (occursInDimension(f.storeAt))
//        true
//      else if (occursInDimension(f.computeAt))
//        true
//      else false
//    }
//
//    def occursInDimension(dim: Option[Dim]): Boolean = {
//      dim match {
//        case Some(dim) if dim.isInstanceOf[OuterDim] => {
//          var d = dim.asInstanceOf[OuterDim]
//          if (d.f == func) true
//          else if (d.old == func) true
//          else false
//        }
//        case Some(dim) if dim.isInstanceOf[SplitDim] => {
//          var d = dim.asInstanceOf[SplitDim]
//          if (d.f == func) true
//          else if (d.outer.f == func) true
//          else if (d.inner.f == func) true
//          else false
//        }
//        case Some(dim) =>  dim.f == func
//        case None => false
//      }
//    }
//
//    def containsFunc(node: Schedule, func: Func[_]): Boolean = {
//      node match {
//        case r@RootNode(otherChildren) => {
//          r.getChildren.exists(_.exists(containsFunc(_, func)))
//        }
//        case c@ComputeNode(s, otherChildren) => {
//          if (occursInNodeFunction(s)) true
//          else c.getChildren.exists(_.exists(containsFunc(_, func)))
//        }
//        case st@StorageNode(s, otherChildren) => {
//          if (occursInNodeFunction(s)) true
//          else st.getChildren.exists(_.exists(containsFunc(_, func)))
//        }
//        case l@LoopNode(v, s, loopType,  otherChildren) => {
//          if (occursInDimension(Some(v))) true
//          else if (occursInNodeFunction(s)) true
//          else l.getChildren.exists(_.exists(containsFunc(_, func)))
//        }
//      }
//    }
//    containsFunc(sched, func)
//  }
//
//  def sameFuncs(sched: Schedule, func: Func[_]): Boolean = {
//    sched match {
//      case r@RootNode(otherChildren) => {
//        !r.getChildren.exists(_.exists(!sameFuncs(_, func)))
//      }
//      case c@ComputeNode(s, otherChildren) => {
//        if (s != func && s.id == func.id) false
//        else !c.getChildren.exists(_.exists(!sameFuncs(_, func)))
//      }
//      case st@StorageNode(s, otherChildren) => {
//        if (s != func && s.id == func.id) false
//        else !st.getChildren.exists(_.exists(!sameFuncs(_, func)))
//      }
//      case l@LoopNode(v, s, loopType,  otherChildren) => {
//        if (s != func && s.id == func.id) false
//        else !l.getChildren.exists(_.exists(!sameFuncs(_, func)))
//      }
//    }
//  }
//}