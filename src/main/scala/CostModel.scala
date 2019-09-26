package sepia

import scala.io.StdIn.readChar
import scala.io.StdIn.readInt

trait CostModel extends PipelineForCompiler with AutoschedulerUtils {

  var outX: Int = 64
  var outY: Int = 64
  var costFunction: (Schedule => Int) = nestingDepth

  def initCostModel(expX: Int, expY: Int, func: String) = {
    outX = expX
    outY = expY

    costFunction = func match {
      case "depth" => nestingDepth _
      case "cCost" => computationCost _
      case "sCost" => storeCost _
      case _ => nestingDepth _
    }
  }

  def evaluateCost(scheduleList: Array[Schedule]): List[(Int, Schedule)] = {
    scheduleList.foldLeft(List[(Int, Schedule)]())({
      case (list, s) => list :+ (costFunction(s), s)
    })
  }

  def pickBest(scheduleList: Array[Schedule]): (Int, Schedule) = {
    pickNBest(1, scheduleList).head
  }

  def pickNBest(n: Int, scheduleList: Array[Schedule]): List[(Int, Schedule)] = {
    evaluateCost(scheduleList).filter(_._1 > 0).sortBy(_._1).take(n)
  }

  def nestingDepth(sched: Schedule): Int = {
    sched match {
      case LoopNode(_, _, _, children) => 1 + children.map(nestingDepth(_)).max
      case ComputeNode(_, children) => 0
      case RootNode(children) => children.map(nestingDepth(_)).max
      case StorageNode(_, children) => children.map(nestingDepth(_)).max
    }
  }

  def computationCost(sched: Schedule): Int = {

    val f = finalFunc.getOrElse(throw new UnexpectedBehavior("No final func")).id

    val output: Box = new Box(outX, outY, f, 1, 1)
    val boxes: Map[Int, Box] = pushBox(sched, output, Map())

    val cost = boxes.foldLeft(0)({ case (acc, (f, box)) => acc + box.cost })

    boxes.foreach({case (f, b) => println(b)})
    println(cost)

    cost
  }

  def storeCost(sched: Schedule): Int = {

    val f = finalFunc.getOrElse(throw new UnexpectedBehavior("No final func")).id

    val output: Box = new Box(outX, outY, f, 1, 1)
    val boxes: Map[Int, Box] = pushBox(sched, output, Map())

    boxes.foldLeft(0)({ case (acc, (f, box)) => acc + box.size })

  }

  class Box(val x: Int, val y: Int, val f: Int,  val t: Int, val w: Int) {

    //some kind of locality factor
    def cost() = x * y * t * w * (x+y)
    def size() = x * y

    def adapt(stage: Int): Box = {
      if (f != stage) {
        val (bX, bY) = getBounds(stage, f)
        //shrink
        if (stage > f)
          new Box(x - (bX.width - 1), y - (bY.width - 1), stage, t, w)
        //widen
        else
          new Box(x + (bX.width - 1), y + (bY.width - 1), stage, t, w)

      } else this
    }

    def split(dim: String, factor: Int, stage: Int): Box = {
      if (dim == "x") new Box(factor, y, stage, t * ((x - factor) / factor + 1), w)
      else new Box(x, factor, stage, t * ((y + factor) / factor + 1), w)
    }

    def makeHeavy(weight: Int, stage: Int): Box = {
      new Box(x, y, stage, t, w * weight)
    }

    override def toString(): String = {
      s"(x:$x, y:$y, f:$f, t:$t, w: $w)"
    }
  }

  def pushBox(sched: Schedule, box: Box, boxes: Map[Int, Box]): Map[Int, Box] = {

    sched match {
      case RootNode(children) => children.map(pushBox(_, box, boxes)).foldLeft(boxes)(_ ++ _)
      case StorageNode(stage, children) => {
        val newBox = box.adapt(stage.id)

        boxes = boxes + (stage.id -> newBox)
        children.foldLeft(boxes)({
          case (b, child) => b ++ pushBox(child, newBox, b)
        })
      }
      //vectorized Loops
      case LoopNode(variable, stage, loopType, children) => {
        var newBox = box.adapt(stage.id)

        if (variable.isInstanceOf[OuterDim])
          newBox = newBox.split(variable.shadowingName, variable.asInstanceOf[OuterDim].splitFactor, stage.id)
        else
          newBox = newBox.split(variable.shadowingName, 1, stage.id)

        children.foldLeft(boxes)({
          case (b, child) => b ++ pushBox(child, newBox, b)
        })
      }

      case ComputeNode(stage, children) => {
        val newBox = box.adapt(stage.id)

        boxes = boxes + (stage.id -> boxes(stage.id).makeHeavy(computeNodeCost(stage.id, boxes), stage.id))
        children.foldLeft(boxes)({
          case (b, child) => b ++ pushBox(child, newBox, b)
        })
      }
    }
  }

  def computeNodeCost(stage: Int, boxes: Map[Int, Box]): Int = {
    //assuming each node with storage node has compute node

    def hasBeenComputed(prod: Int): Boolean = {
      boxes.filter({ case (f, box) => f == prod}).nonEmpty
    }

    def costOfProducer(prod: Int, stage: Int): Int = {
      val weight = computeNodeCost(prod, boxes)

      val (boundX, boundY) = getBounds(prod, stage)
      weight * boundX.width * boundY.width
    }

    callGraph.producersOf(stage).filter(!hasBeenComputed(_))
      .map(costOfProducer(_, stage)).foldLeft(0)(_ + _) + callGraph.getCost(stage)
  }


  //  def computeNodeCost(stage: Int, boxes: Map[Int, Box]): Int = {
//    //assuming each node with storage node has compute node
//
//    def hasBeenComputed(prod: Int): Boolean = {
//      boxes.filter({ case (f, box) => f == prod}).nonEmpty
//    }
//
//    def costOfProducer(prod: Int, stage: Int): Int = {
//      val weight = if (hasBeenComputed(prod) || prod == -1) 1
//                   else computeNodeCost(prod, boxes)
//
//      val (boundX, boundY) = getBounds(prod, stage)
//      weight * boundX.width * boundY.width
//    }
//
//    callGraph.producersOf(stage).map(costOfProducer(_, stage)).foldLeft(0)(_ + _) + 10
//  }

}