import sepia._
import org.scalatest.FlatSpec

trait Blur extends TestPipeline {
  override def prog(in: Input, w: Rep[Int], h: Rep[Int]): Rep[Unit] = {
    val g = func[Short] {
      (x: Rep[Int], y: Rep[Int]) => in(x, y) / 1.toShort
    }

    val f = final_func {
      (x: Rep[Int], y: Rep[Int]) => g(x, y)
    }

        //f.split("y", "y_outer", "y_inner", 4)

//        f.tile("x", "y", "x_outer", "y_outer", "x_inner", "y_inner", 4, 4)
//        g.storeAt(f, "y_outer")
//        g.computeAt(f, "x_outer")
//        g.split("y", "y_outer", "y_inner", 2)

    // f.autoschedule(g, f)

    f.dummyAuto(g)

    //g.computeRoot()
    //g.storeAt(f, "y")
//    g.storeAt(f, "x")
//    g.computeAt(f, "x")
    //g.storeAt(f, "y")

    registerFunction("g", g)
    registerFunction("f", f)
  }
}

class BlurEx extends FlatSpec {
  "Blur" should "should make a blurry boi" in {
    println("BlurEx")

    val blur = new Blur with CompilerInstance with Autoscheduler with TestAstOps
    val blurAnalysis = new Blur with TestPipelineAnalysis
    blur.compile(blurAnalysis.getBoundsGraph, "blurry")
  }
}