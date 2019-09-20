package sepia

//  todo: remove this class

class Edge(val bounds: Map[String, Bound])

class CallGraph(a: Map[Int, List[Int]], ws: Map[(Int, Int), Edge], c: Map[Int, Int]) {
  private val adjList: Map[Int, List[Int]] = a
  private val weights: Map[(Int, Int), Edge] = ws
  private val costs: Map[Int, Int] = c

  def getCost(func: Int) = {
    costs(func)
  }

  def getCosts() = {
    costs
  }

  def getBound(producer: Int, consumer: Int, v: String) = {
    weights((consumer, producer)).bounds(v)
  }

  def printBounds(): Unit = {
    println("Bounds:")
    weights.foreach({case(p,e) =>
      println(f"Funcs(p -> c): ${p._2} -> ${p._1}")
      e.bounds.foreach({case (x, b) =>
        print(f"var $x with bound lower:")
        print(b.lb)
        print(", upper:")
        println(b.ub)
      })
    })
  }

  def isProducerConsumer(producer: Int, consumer: Int) = {
    weights.contains((consumer, producer))
  }

  def producersOf(f: Int) = adjList.getOrElse(f, List())

  def consumersOf(f: Int) = {
    adjList.foldLeft(List[Int]()) {
      case (a, (k, v)) => if (v.contains(f)) a :+ k else a
    }
  }

  def getBoundWithDefault(producer: Int, consumer: Int,
                          v: String, default: Bound) = {
    weights((consumer, producer)).bounds.getOrElse(v, default)
  }

  override def toString(): String = {
    adjList.toString
  }
}

object CallGraph {
  def buildWeights(m: Map[Int, Map[Int, Map[String, Bound]]]) = {
    m.flatMap({
      case (k1, v1) => v1.map({
        case (k2, v2) => (k1, k2) -> new Edge(v2)
      })
    })
  }

  def buildAdj(m: Map[Int, Map[Int, Map[String, Bound]]],
               src: Int): Map[Int, List[Int]] = {
    //println(f"found src $src")
    if (src == -1 || m(src).isEmpty) {  // src doesn't call anything (or is in)
      Map(src -> List())
    } else {
      val adjList = m(src).flatMap({
        case (k, v) => buildAdj(m, k)
      })

      adjList + (src -> m(src).keys.toList)
    }
  }

  def graphFromMap(m: Map[Int, Map[Int, Map[String, Bound]]], node: Int, c: Map[Int, Int]): CallGraph = {
    val weights = buildWeights(m)
    val adjList = buildAdj(m, node)
    new CallGraph(adjList, weights, c)
  }

}
