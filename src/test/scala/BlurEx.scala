import sepia._
import org.scalatest.FlatSpec

trait Blur extends TestPipeline {
  override def prog(in: Input, w: Rep[Int], h: Rep[Int]): Rep[Unit] = {
    val g = func[Short] {
      (x: Rep[Int], y: Rep[Int]) => in(x, y) / 1.toShort
    }
    val f = final_func[Short] {
      (x: Rep[Int], y: Rep[Int]) => g(x, y)
    }

    //f.split("y", "y_outer", "y_inner", 4)

    f.tile("x", "y", "x_outer", "y_outer", "x_inner", "y_inner", 4, 4)
    g.computeAt(f, "y_inner")

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