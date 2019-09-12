import sepia._
import org.scalatest.FlatSpec
import scala.math._
import collection.mutable.ListBuffer

trait GradB extends TestPipeline {
  override def prog(in: Input, w: Rep[Int], h: Rep[Int]): Rep[Unit] = {

    val h = func[Int] {
      (x: Rep[Int], y: Rep[Int]) => x + y
    }
    val g = func[Int] {
      (x: Rep[Int], y: Rep[Int]) => (h(x, y) + h(x+1, y) + h(x-1, y)) / 3.toInt
    }
    val i = final_func[Int] {
      (x: Rep[Int], y: Rep[Int]) => (g(x, y) + g(x, y+1) + g(x, y-1)) / 3.toInt
    }

//    i.tile("x", "y", "x_outer", "y_outer", "x_inner", "y_inner", 8, 8)
//    //i.split("y_inner", "y_inner1", "y_inner2", 4)
//    g.computeAt(i, "y_inner")
//    g.storeAt(i, "y_outer")
//    //g.split("y", "y_outer", "y_inner", 2)
//    h.computeAt(g, "y")

    i.dummyAuto(g)


    registerFunction("g", g)
    registerFunction("h", h)
    registerFunction("i", i)
  }
}

class GradBlur extends FlatSpec {
  "GradBlur" should "make a blurry boi" in {
    println("five by five blur")
    val blurProg =
      new GradB with CompilerInstance with Autoscheduler with TestAstOps
    val blurProgAnalysis = new GradB with TestPipelineAnalysis
    blurProg.compile(blurProgAnalysis.getBoundsGraph, "grad_blur")
  }
}

