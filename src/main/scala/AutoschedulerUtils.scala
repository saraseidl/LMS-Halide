package sepia

trait AutoschedulerUtils extends PipelineForCompiler with AstAutoOps {

  def printScheduledConsumers(funcId: Int, sched: Schedule): Unit = {
    print(f"......function $funcId is consumed by: ")
    println(consumersOf(funcId))

    print("......scheduled are: ")
    println(scheduledConsumersFor(funcId, sched))
  }

  def printScheduledAncestors(funcId: Int, sched: Schedule): Unit = {
    print(f"......function $funcId is consumed by: ")
    println(consumersOf(funcId))

    print("......scheduled ancestors are: ")
    println(scheduledAncestorFor(funcId, sched))
  }

  def toFunc[T:Typ:Numeric:SepiaNum](stage: Int): Func[T] = {
    idToFunc(stage).asInstanceOf[Func[T]]
  }

  def consumersOf(func: Int): List[Int] = {
    callGraph.consumersOf(func)
  }

  def scheduledConsumersFor(funcId: Int, sched: Schedule): List[Func[_]] = {
    consumersOf(funcId).collect{ case consId if (isScheduled(consId, sched)) =>
    scheduledFunctionFor(consId, sched, false)
    .getOrElse(throw new UnexpectedBehavior(f"scheduled function $consId not found"))}
  }

  def scheduledAncestorFor(funcId: Int, sched: Schedule): List[Func[_]] = {
    scheduledConsumersFor (funcId, sched) match {
      case list if list.nonEmpty => list
      case List () => consumersOf (funcId).map (scheduledAncestorFor (_, sched) ).flatten
    }
  }

  def hasScheduledConsumer(funcId: Int, sched: Schedule): Boolean = {
    scheduledConsumersFor(funcId, sched).length > 0
  }

  def hasMultipleScheduledConsumers(funcId: Int, sched: Schedule): Boolean = {
    scheduledConsumersFor(funcId, sched).length > 1
  }

  def hasScheduledAncestor(funcId: Int, sched: Schedule): Boolean = {
    scheduledAncestorFor(funcId, sched).length > 0
  }

  def hasMultipleScheduledAncestors(funcId: Int, sched: Schedule): Boolean = {
    scheduledAncestorFor(funcId, sched).length > 1
  }

  def getBounds(f1: Int, f2: Int) = {
    val prod = math.min(f1, f2)
    val cons = math.max(f1, f2)

    val boundX = BoundsAnalysis
      .boundsForProdInCon(callGraph, prod, cons, "x")
      .getOrElse(throw new InvalidSchedule(f"No bounds for x found"))

    val boundY = BoundsAnalysis
      .boundsForProdInCon(callGraph, prod, cons, "y")
      .getOrElse(throw new InvalidSchedule(f"No bounds for y found"))

    (boundX, boundY)
  }
}