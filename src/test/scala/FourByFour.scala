import sepia._
import org.scalatest.FlatSpec
import scala.math._
import collection.mutable.ListBuffer

trait FiveByFive extends TestPipeline {
	override def prog(in: Input, w: Rep[Int], h: Rep[Int]): Rep[Unit] = {

		val h = func[Int] {
			(x: Rep[Int], y: Rep[Int]) => (in(x+1, y) + in(x-1, y) + in(x, y) + in(x, y+1) + in(x, y-1)) / 5
		}
		val g = func[Int] {
			(x: Rep[Int], y: Rep[Int]) => (h(x+2, y) + h(x-2, y) + h(x, y) + h(x+1, y) + h(x-1, y)) / 5
		}
		val i = final_func {
			(x: Rep[Int], y: Rep[Int]) => (g(x, y+2) + g(x, y-2) + g(x, y) + g(x, y+1) + g(x, y-1)) / 5
		}


		i.tile("x", "y", "x_outer", "y_outer", "x_inner", "y_inner", 8, 8)
		i.split("y_inner", "y_inner1", "y_inner2", 4)
		g.computeAt(i, "y_inner1")
		g.storeAt(i, "y_outer")
		g.split("y", "y_outer", "y_inner", 2)
		h.computeAt(g, "y_outer")


		registerFunction("g", g)
		registerFunction("h", h)
		registerFunction("i", i)
	}
}

class FourByFour extends FlatSpec {
	"FourByFour" should "make a blurry boi" in {
		println("five by five blur")
		val blurProg =
			new FiveByFive with CompilerInstance with TestAstOps
		val blurProgAnalysis = new FiveByFive with TestPipelineAnalysis
		blurProg.compile(blurProgAnalysis.getBoundsGraph, "very_blurred")
	}
}

