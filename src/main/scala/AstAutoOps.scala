package sepia

import sun.jvm.hotspot.opto.RootNode

import scala.collection.mutable.{Map => MMap}

trait AstAutoOps extends AstOps with ScheduleCompiler {
  this: CompilerFuncOps =>

  // handle storeAt, computeAt?
  // swap function in schedule based on unique id (copied functions)
  def swapFunction(sched: Schedule, func: Func[_]): ScheduleNode = {
    sched match {
      case LoopNode(d, f, ltype, children)
        if f.id == func.id => {
          LoopNode(func.vars(d.name), func, ltype, children.map(swapFunction(_, func)))
      }
      case ComputeNode(f, children)
        if f.id == func.id => {
          ComputeNode(func, children.map(swapFunction(_, func)))
      }
      case StorageNode(f, children)
        if f.id == func.id => {
          StorageNode(func, children.map(swapFunction(_, func)))
      }
      case RootNode(children) => {
        RootNode(children.map(swapFunction(_, func)))
      }
      case _ => sched.mapChildren(swapFunction(_, func))
    }
  }

  def updateStoreAtDim(sched: Schedule, prod: Func[_], sf: Func[_]) = {
    prod.storeAt = prod.storeAt match {
      case Some(dim) => Some(sf.dim(dim.name))
      case None => throw new InvalidSchedule("No store at defined for Producer")
    }

    swapFunction(sched.copy(), sf)
  }

  //true if function is scheduled
  def isScheduled(funcId: Int, sched: Schedule): Boolean = {
    scheduledFunctionFor(funcId, sched, false).isDefined
  }

  //find scheduled function for a given function id
  def scheduledFunctionFor(funcId: Int, sched: Schedule, store: Boolean): Option[Func[_]] = {
    sched match {
      case RootNode(children) => {
        children.map(scheduledFunctionFor(funcId, _, store)).filter(_.isDefined).headOption.getOrElse(None)
      }
      case StorageNode(stage, children) if store => {
        if (stage.id == funcId) Some(stage)
        else children.map(scheduledFunctionFor(funcId, _, store)).filter(_.isDefined).headOption.getOrElse(None)
      }
      case StorageNode(stage, children) => {
        children.map(scheduledFunctionFor(funcId, _, store)).filter(_.isDefined).headOption.getOrElse(None)
      }
      case LoopNode(_, stage, _, children) => {
        children.map(scheduledFunctionFor(funcId, _, store)).filter(_.isDefined).headOption.getOrElse(None)
      }
      case ComputeNode(stage, children) =>
        if (stage.id == funcId) Some(stage)
        else children.map(scheduledFunctionFor(funcId, _, store)).filter(_.isDefined).headOption.getOrElse(None)
    }
  }

  //map of functions of enclosing loops to their dimension
  def getEnclosingFunctions[T:Typ:Numeric:SepiaNum](func: Func[T], sched: Schedule): Map[Func[_], List[String]] = {
    getEnclosingLoops(func, sched).keySet.groupBy(_._1).filter(_._1 != func).map({
      case (f, set) => (f, set.map(_._2).toList)
    }).toMap
  }

  //TODO: rename, consider bounds when vectorizing (inner loop with bounds big enough)
  def getEnclosingSplitFactor[T:Typ:Numeric:SepiaNum](func: Func[T], sched: Schedule, dim: String): Int = {
    val enclosingDims = getEnclosingLoops(func, sched).collect{
      case ((f, name), d) if (f != func && (name contains dim)) => d
    }

    if (enclosingDims.isEmpty)
      64
    else if (enclosingDims.exists(!_.isInstanceOf[OuterDim]))
      1
    else
      enclosingDims.minBy(_.asInstanceOf[OuterDim].splitFactor).asInstanceOf[OuterDim].splitFactor
  }

  def removeVectorizedDimension(func: Func[_], dims: List[String]) = {
    func.vectorizeAt match {
      case Some(vecDim) => {
        println(f".........removing vectorized dimension ${vecDim} from list of options $dims")
        dims.filter(_ != vecDim.name)
      }
      case None => dims
    }
  }

  //map of possible store at options (functions -> dimensions)
  //last map removes vectorized dimensions from options
  def storeAtOptions[T:Typ:Numeric:SepiaNum](func: Func[T], sched: Schedule): Map[Func[_], List[String]] = {
    getEnclosingFunctions(func, sched).map({
      case (k, v) => (k -> removeVectorizedDimension(k, v))
    }).toMap
  }


  /* for scheduling producer with multiple consumers
  def commonEnclosingLoops[T:Typ:Numeric:SepiaNum, U:Typ:Numeric:SepiaNum](func: Func[T], sched: Schedule, consumers: List[Int]) = {

    val lastInPipeline = consumers.max

    val allEnclosingLoops = consumers.foldLeft(List[(Func[_], List[String])]]) {
      case (a, cons) => {
        var c = scheduledFunctionFor(cons, sched)
        a ++ getEnclosingFunctions(c, sched).toList
      }
    }

    val someCons = consumers.find(_ != lastInPipeline)

    var commonEnclosingLoops = Map[Func[_], List[String]]()

    //find common loops/functions
    getEnclosingFunctions(scheduledFunctionFor(someCons)).foreach({
      case (eFunc, funcDims) => {
        var count = enclosingLoops.count({ case (f, _) => f == eFunc })

        //candidate functions
        if (count == consumers.length || count == (consumers.length - 1) && eFunc == lastInPipeline) {

          var intersection = allEnclosingLoops.filter(_._1 == eFunc).foldLeft(funcDims.toSet) {
            case (a, (f, li)) => a & li.toSet
          }

          if (intersection.nonEmpty)
            commonEnclosingLoops(eFunc) = intersection.toList
        }
      }
    })

    commonEnclosingLoops
  }

  */

  //map of possible compute at options (functions after SN for func -> dimensions)
  //last map removes vectorized dimensions from options
  //TODO: less hacky way to get storeAt dim into this map
  def computeAtOptions[T:Typ:Numeric:SepiaNum](func: Func[T], sched: Schedule, sf: Func[_], sDim: String): Map[Func[_], List[String]] = {
    getLoopsAfterSN(func, sched) match {
      case map if map.keySet.groupBy(_._1).filter(_._1 != func).isEmpty => Map(sf -> List(sDim))
      case map => { map.keySet.groupBy(_._1).filter(_._1 != func).map({
          case (f, set) if (f.id == sf.id) => (f, set.map(_._2).toList :+ sDim)
          case (f, set) => (f, set.map(_._2).toList)
        }).map({
          case (k, v) => (k -> removeVectorizedDimension(k, v))
        }).toMap
      }
    }
  }

  def deInlineProducer[T:Typ:Numeric:SepiaNum, U:Typ:Numeric:SepiaNum](producer: Func[T], consumer: Func[U], sched: Schedule): Schedule = {
    if (producer.inlined) {
      producer.inlined = false
      deInline(producer, consumer, sched)
    } else sched
  }

}