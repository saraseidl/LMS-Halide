import sepia._
import org.scalatest.FlatSpec

trait Blur extends TestPipeline {
  override def prog(in: Input, w: Rep[Int], h: Rep[Int]): Rep[Unit] = {
    val h = func[Short] {
      (x: Rep[Int], y: Rep[Int]) => (in(x, y) + in(x+1, y) + in(x-1, y)) / 3.toShort
    }
    val g = func[Short] {
      (x: Rep[Int], y: Rep[Int]) => h(x,y-1) + h(x,y+1) / 2.toShort
    }
    val f = final_func[Short] {
      (x: Rep[Int], y: Rep[Int]) => g(x, y) / 3.toShort
    }

//    f.split("y", "y_outer", "y_inner", 8)


//        f.tile("x", "y", "x_outer", "y_outer", "x_inner", "y_inner", 4, 4)
//        g.storeAt(f, "y_outer")
//        g.computeAt(f, "x_outer")
//        g.split("y", "y_outer", "y_inner", 2)

//    f.autoschedule(g, f)

//    g.computeAt(f, "y")
//    g.computeRoot()

    f.dummyAuto[Short](64, 64, "cCost")

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

    val blur = new Blur with CompilerInstance with AutoSchedulerR with TestAstOps
    val blurAnalysis = new Blur with TestPipelineAnalysis
    blur.compile(blurAnalysis.getBoundsGraph, "blurry")
  }
}