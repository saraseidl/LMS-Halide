import sepia._
import org.scalatest.FlatSpec

trait TileIng extends TestPipeline {
  override def prog(in: Input, w: Rep[Int], h: Rep[Int]): Rep[Unit] = {

    val f = func[Int] {
      (x: Rep[Int], y: Rep[Int]) => in(x, y) * 2
    }
    val g = final_func[Int] {
      (x: Rep[Int], y: Rep[Int]) => f(x, y) / 2
    }

    g.split("y", "y_outer", "y_inner", 2)
    f.computeAt(g, "y_inner")
    f.storeAt(g, "y_outer")

    registerFunction("g", g)
    registerFunction("f", f)

  }
}

class TestTile extends FlatSpec {
  "TestTile" should "storeAt and computeAt" in {
    println("where !I! want it to...")

    val test = new TileIng with CompilerInstance with TestAstOps
    val testAnalysis = new TileIng with TestPipelineAnalysis
    test.compile(testAnalysis.getBoundsGraph, "very_testy")
  }
}
