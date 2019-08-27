import sepia._
import org.scalatest.FlatSpec

trait Blur extends TestPipeline {
  override def prog(in: Input, w: Rep[Int], h: Rep[Int]): Rep[Unit] = {
    val g = func[Short] {
      (x: Rep[Int], y: Rep[Int]) => in(x, y) / 1.toShort
    }
    val i = final_func[Short] {
      (x: Rep[Int], y: Rep[Int]) => g(x, y)
    }

    i.tile("x", "y", "x_outer", "y_outer", "x_inner", "y_inner", 4, 4)
    g.computeAt(i, "y_inner")

    registerFunction("g", g)
    registerFunction("i", i)


//    g.tile("x", "y", "x_outer", "y_outer", "x_inner", "y_inner", 4, 4)
//    //g.split("y", "y_outer", "y_inner", 4)
//    //g.split("y_inner", "y_inner1", "y_inner2", 2)
//    f.computeAt(g, "x_inner")
//    f.storeAt(g, "x_outer")

//    registerFunction("g", g)
//    registerFunction("f", f)

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

