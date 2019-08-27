import sepia._

trait TwoStageBoxBlurSplitAndComputeAtInner extends TestPipeline {
  override def prog(in: Input, w: Rep[Int], h: Rep[Int]): Rep[Unit] = {
    val g = func[Short] {
      (x: Rep[Int], y: Rep[Int]) => in(x, y) / 1.toShort
    }
    val i = final_func[Short] {
      (x: Rep[Int], y: Rep[Int]) => g(x, y)
    }

    i.split("y", "y_outer", "y_inner", 4)
    g.computeAt(i, "y_inner")


    registerFunction("g", g)
    registerFunction("i", i)
  }
}

trait TwoStageBoxBlurSplitAndComputeAtOuter extends TestPipeline {
  override def prog(in: Input, w: Rep[Int], h: Rep[Int]): Rep[Unit] = {
    val g = func[Short] {
      (x: Rep[Int], y: Rep[Int]) => in(x, y) / 1.toShort
    }
    val i = final_func[Short] {
      (x: Rep[Int], y: Rep[Int]) => g(x, y)
    }

    i.split("y", "y_outer", "y_inner", 4)
    g.computeAt(i, "y_outer")


    registerFunction("g", g)
    registerFunction("i", i)
  }
}

trait TwoStageBoxBlurSplitAndComputeAtAndStoreAt extends TestPipeline {
  override def prog(in: Input, w: Rep[Int], h: Rep[Int]): Rep[Unit] = {
    val g = func[Short] {
      (x: Rep[Int], y: Rep[Int]) => in(x, y) / 1.toShort
    }
    val i = final_func[Short] {
      (x: Rep[Int], y: Rep[Int]) => g(x, y)
    }

    i.split("y", "y_outer", "y_inner", 4)
    g.computeAt(i, "y_inner")
    g.storeAt(i, "y_outer")

    registerFunction("g", g)
    registerFunction("i", i)
  }
}


trait TwoStageBoxBlurTileAndComputeAtOuter extends TestPipeline {
  override def prog(in: Input, w: Rep[Int], h: Rep[Int]): Rep[Unit] = {
    val g = func[Short] {
      (x: Rep[Int], y: Rep[Int]) => in(x, y) / 1.toShort
    }
    val i = final_func[Short] {
      (x: Rep[Int], y: Rep[Int]) => g(x, y)
    }

    i.tile("x", "y", "x_outer", "y_outer", "x_inner", "y_inner", 4, 4)
    g.computeAt(i, "y_outer")

    registerFunction("g", g)
    registerFunction("i", i)
  }
}

trait TwoStageBoxBlurTileAndComputeAtInner extends TestPipeline {
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
  }
}

trait TwoStageBoxBlurTileAndComputeAtAndStoreAt extends TestPipeline {
  override def prog(in: Input, w: Rep[Int], h: Rep[Int]): Rep[Unit] = {
    val g = func[Short] {
      (x: Rep[Int], y: Rep[Int]) => in(x, y) / 1.toShort
    }
    val i = final_func[Short] {
      (x: Rep[Int], y: Rep[Int]) => g(x, y)
    }

    i.tile("x", "y", "x_outer", "y_outer", "x_inner", "y_inner", 4, 4)
    g.computeAt(i, "y_inner")
    g.storeAt(i, "y_outer")

    registerFunction("g", g)
    registerFunction("i", i)
  }
}