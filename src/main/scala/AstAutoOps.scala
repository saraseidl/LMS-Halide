package sepia

import sun.jvm.hotspot.opto.RootNode

import scala.collection.mutable.{Map => MMap}

trait AstAutoOps extends AstOps with ScheduleCompiler {
  this: CompilerFuncOps =>

  // TODO: handle storeAt, computeAt
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

  //find scheduledFunction for a given id
  def scheduledFunctionFor(funcId: Int, sched: Schedule): Option[Func[_]] = {
    sched match {
      case RootNode(children) => {
        children.map(scheduledFunctionFor(funcId, _)).headOption.getOrElse(None)
      }
      case StorageNode(stage, children) => {
        children.map(scheduledFunctionFor(funcId, _)).headOption.getOrElse(None)
      }
      case LoopNode(_, stage, _, children) => {
        children.map(scheduledFunctionFor(funcId, _)).headOption.getOrElse(None)
      }
      case ComputeNode(stage, children) =>
      if (stage.id == funcId) Some(stage)
      else children.map(scheduledFunctionFor(funcId, _)).headOption.getOrElse(None)
    }
  }

  //map of functions of enclosing loops to their dimension
  def getEnclosingFunctions[T:Typ:Numeric:SepiaNum](func: Func[T], sched: Schedule): Map[Func[_], List[String]] = {
    getEnclosingLoops(func, sched).keySet.groupBy(_._1).filter(_._1 != func).map({
      case (f, set) => (f, set.map(_._2).toList)
    }).toMap
  }

  //map of possible store at options (functions -> dimensions)
  def storeAtOptions[T:Typ:Numeric:SepiaNum](func: Func[T], sched: Schedule): Map[Func[_], List[String]] = {
    getEnclosingFunctions(func, sched)
  }

  //map of possible compute at options (functions after SN for func -> dimensions)
  //TODO: less hacky way to get storeAt dim into this map
  def computeAtOptions[T:Typ:Numeric:SepiaNum](func: Func[T], sched: Schedule, sf: Func[_], sDim: String): Map[Func[_], List[String]] = {
    getLoopsAfterSN(func, sched) match {
      case map if map.isEmpty => Map(sf -> List(sDim))
      case map => { map.keySet.groupBy(_._1).filter(_._1 != func).map({
          case (f, set) if (f.id == sf.id) => (f, set.map(_._2).toList :+ sDim)
          case (f, set) => (f, set.map(_._2).toList)
        }).toMap
      }
    }
  }

  def deInlineProducer[T:Typ:Numeric:SepiaNum, U:Typ:Numeric:SepiaNum](producer: Func[T], consumer: Func[U], sched: Schedule): Schedule = {

      producer.inlined = false
      deInline(producer, consumer, sched)

  }

}
