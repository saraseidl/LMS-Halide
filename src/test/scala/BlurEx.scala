import sepia._
import org.scalatest.FlatSpec

trait Blur extends TestPipeline {
  override def prog(in: Input, w: Rep[Int], h: Rep[Int]): Rep[Unit] = {
    val f = func[Short] {
      (x: Rep[Int], y: Rep[Int]) => in(x, y) / 1.toShort
    }
    val g = final_func[Short] {
      (x: Rep[Int], y: Rep[Int]) => f(x, y)
    }

    g.split("y", "y_outer", "y_inner", 4)
    f.computeAt(g, "y_outer")
    //f.storeAt(g, "y_outer")

    registerFunction("g", g)
    registerFunction("f", f)

  }
}

class BlurEx extends FlatSpec {
  "Blur" should "should make a blurry boi" in {
    println("BlurEx")

    val blur = new Blur with CompilerInstance with TestAstOps
    val blurAnalysis = new Blur with TestPipelineAnalysis
    blur.compile(blurAnalysis.getBoundsGraph, "blurry")
  }
}
