import org.scalatest.FlatSpec
import scala.collection.mutable.ListBuffer
import java.io.File

import sepia._

trait CompilerInstance extends ScheduleCompiler
											 with PipelineForCompiler with DslExp
											 with AstOps {
	self =>
    val codegen = new DslGenC {
      val IR: self.type = self
    }

	def widthOutDiff(boundsGraph: CallGraph) = {
		BoundsAnalysis.boundsForProdInCon(boundsGraph, -1,
									 finalFunc.getOrElse(throw new InvalidAlgorithm("No final func selected")).id,
									 "x").getOrElse(Bound(0, 0)).width - 1
	}

	def heightOutDiff(boundsGraph: CallGraph) = {
		BoundsAnalysis.boundsForProdInCon(boundsGraph, -1,
									 finalFunc.getOrElse(throw new InvalidAlgorithm("No final func selected")).id,
									 "y").getOrElse(Bound(0, 0)).width - 1

	}

	def ev(boundsGraph: CallGraph)
				(in: Rep[Array[UShort]], out: Rep[Array[UShort]], w: Rep[Int], h: Rep[Int]) = {
		compiler_prog(in, out, w, h)
		//println(sched)
		println()
		evalSched(sched, boundsGraph, Map(), sched)
		//println(sched)
		assignOutArray(out)
	}

	def compile(boundsGraph: CallGraph, progname: String) = {
		val pw = 	new java.io.PrintWriter(new File(f"testOutput/$progname.c"))
		codegen.emitSourceMut(ev(boundsGraph), "pipeline", pw)
		codegen.emitStaticData("WIDTH_OUT_DIFF", widthOutDiff(boundsGraph), pw)
		codegen.emitStaticData("HEIGHT_OUT_DIFF", heightOutDiff(boundsGraph), pw)
	}
}

class CompilerSpec extends FlatSpec {
	"The grad program" should "return the default tree" in {
		println("simple grad prog")

	 	val gradProg =
	 		new GradProg with CompilerInstance with TestAstOps

		val gradProgAnalysis = new GradProg with TestPipelineAnalysis

	 	gradProg.compile(gradProgAnalysis.getBoundsGraph, "simple_grad")
	 	val correctAst: ScheduleNode[String, String] =
	 		new RootNode(List(
	 			new StorageNode("f",List(
	 				new LoopNode("y", "f", Sequential, List(
	 					new LoopNode("x", "f", Sequential, List(
	 						new ComputeNode("f", List())
	 					))
	 				))
	 			))
	 		))
			assertResult(correctAst)(gradProg.scheduleRep)
	}

	"The blurred grad program" should "return the default tree, with f inlined" in {
		println("blurred grad prog")

		val gradProg =
			new BlurredGradProg with CompilerInstance with TestAstOps

		val gradProgAnalysis = new BlurredGradProg with TestPipelineAnalysis

		gradProg.compile(gradProgAnalysis.getBoundsGraph, "blurred_grad")
		val correctAst: ScheduleNode[String, String] =
			new RootNode(List(
				new StorageNode("g",List(
					new LoopNode("y", "g", Sequential, List(
						new LoopNode("x", "g", Sequential, List(
							new ComputeNode("g", List())
						))
					))
				))
			))
			assertResult(correctAst)(gradProg.scheduleRep)
	}

	"The blurred grad prog with computeAt" should "deinline f and move it" in {
		println("blurred grad prog w/ compute at")

		val gradProg =
			new BlurredGradProgComputeAt with CompilerInstance with TestAstOps
		val gradProgAnalysis = new BlurredGradProgComputeAt with TestPipelineAnalysis
		gradProg.compile(gradProgAnalysis.getBoundsGraph, "blurred_grad_compute_at")

		val correctAst: ScheduleNode[String, String] =
			new RootNode(List(
				new StorageNode("g",List(
					new LoopNode("y", "g", Sequential, List(
						new StorageNode("f", List(
							new LoopNode("y", "f", Sequential, List(
								new LoopNode("x", "f", Sequential, List(
									new ComputeNode("f", List())
								))
							)),
							new LoopNode("x", "g", Sequential, List(
								new ComputeNode("g", List())
							))
						))
					))
				))
			))

			assertResult(correctAst)(gradProg.scheduleRep)
	}

	"The blurred grad prog with computeAt and storeRoot" should "deinline f and move it" in {
		println("blurred grad prog w/ compute & store root")

		val gradProg =
			new BlurredGradStoreRoot with CompilerInstance with TestAstOps
		val gradProgAnalysis = new BlurredGradStoreRoot with TestPipelineAnalysis
		gradProg.compile(gradProgAnalysis.getBoundsGraph, "blurred_grad_store_root")

		val correctAst: ScheduleNode[String, String] =
			new RootNode(List(
				new StorageNode("f", List(
					new StorageNode("g",List(
						new LoopNode("y", "g", Sequential, List(
							new LoopNode("y", "f", Sequential, List(
								new LoopNode("x", "f", Sequential, List(
									new ComputeNode("f", List())
								))
							)),
							new LoopNode("x", "g", Sequential, List(
								new ComputeNode("g", List())
							))
						))
					))
				))
			))

			assertResult(correctAst)(gradProg.scheduleRep)
	}

	"The three stage box blur program" should "return the default tree, with f & g inlined" in {
		println("three stage box blur")

		val gradProg =
			new ThreeStageBoxBlur with CompilerInstance with TestAstOps

		val gradProgAnalysis = new ThreeStageBoxBlur with TestPipelineAnalysis

		println("Three stage box blur:")
		gradProg.compile(gradProgAnalysis.getBoundsGraph, "three_stage_box_blur")
		val correctAst: ScheduleNode[String, String] =
			new RootNode(List(
				new StorageNode("i",List(
					new LoopNode("y", "i", Sequential, List(
						new LoopNode("x", "i", Sequential, List(
							new ComputeNode("i", List())
						))
					))
				))
			))
			assertResult(correctAst)(gradProg.scheduleRep)
	}

	"The three stage blur with computeAt" should "inline g, but precompute f" in {
		println("Three stage box blur with computeAt:")
		val blurProg =
			new ThreeStageBoxBlurWithComputeAt with CompilerInstance with TestAstOps
		val blurProgAnalysis = new ThreeStageBoxBlurWithComputeAt with TestPipelineAnalysis
		blurProg.compile(blurProgAnalysis.getBoundsGraph, "three_stage_box_blur_with_compute_at")

		val correctAst: ScheduleNode[String, String] =
			new RootNode(List(
				new StorageNode("i",List(
					new LoopNode("y", "i", Sequential, List(
						new StorageNode("f", List(
							new LoopNode("y", "f", Sequential, List(
								new LoopNode("x", "f", Sequential, List(
									new ComputeNode("f", List())
								))
							)),
							new LoopNode("x", "i", Sequential, List(
								new ComputeNode("i", List())
							))
						))
					))
				))
			))

		assertResult(correctAst)(blurProg.scheduleRep)
	}

	"The two stage blur with a storeAt" should "have the below tree" in {
		println("Two stage blur w/ storeAt:")
		val blurProg = new TwoStageBoxBlurStoreAt with CompilerInstance with TestAstOps
		val blurProgAnalysis = new TwoStageBoxBlurStoreAt with TestPipelineAnalysis

		val correctAst: ScheduleNode[String, String] = new RootNode(List(
			new StorageNode("i", List(
				new LoopNode("y", "i", Sequential, List(
					new StorageNode("g", List(
						new LoopNode("x", "i", Sequential, List(
							new LoopNode("y", "g", Sequential, List(
								new LoopNode("x", "g", Sequential, List(
									new ComputeNode("g", List())
								))
							)),
							new ComputeNode("i", List())
						))
					))
				))
			))
		))

		blurProg.compile(blurProgAnalysis.getBoundsGraph, "two_stage_blur_store_at")
		assertResult(correctAst)(blurProg.scheduleRep)

	}

	"The two stage blur with a (reflected) storeAt" should "have the below tree" in {
		println("Two stage blur w/ reflected storeAt:")
		val blurProg = new TwoStageBoxBlurStoreAtReflected with CompilerInstance with TestAstOps
		val blurProgAnalysis = new TwoStageBoxBlurStoreAtReflected with TestPipelineAnalysis

		val correctAst: ScheduleNode[String, String] = new RootNode(List(
			new StorageNode("i", List(
				new LoopNode("y", "i", Sequential, List(
					new StorageNode("g", List(
						new LoopNode("x", "i", Sequential, List(
							new LoopNode("y", "g", Sequential, List(
								new LoopNode("x", "g", Sequential, List(
									new ComputeNode("g", List())
								))
							)),
							new ComputeNode("i", List())
						))
					))
				))
			))
		))

		blurProg.compile(blurProgAnalysis.getBoundsGraph, "two_stage_blur_store_at_reflected")
		assertResult(correctAst)(blurProg.scheduleRep)

	}


	"The two stage blur with compute at x" should "have the below tree" in {
		println("Two stage blur w/ compute at x:")
		val blurProg = new TwoStageBoxBlurComputeAtX with CompilerInstance with TestAstOps
		val blurProgAnalysis = new TwoStageBoxBlurComputeAtX with TestPipelineAnalysis

		val correctAst: ScheduleNode[String, String] = new RootNode(List(
			new StorageNode("i", List(
				new LoopNode("y", "i", Sequential, List(
					new LoopNode("x", "i", Sequential, List(
						new StorageNode("g", List(
							new LoopNode("y", "g", Sequential, List(
								new LoopNode("x", "g", Sequential, List(
									new ComputeNode("g", List())
								))
							)),
							new ComputeNode("i", List())
						))
					))
				))
			))
		))

		blurProg.compile(blurProgAnalysis.getBoundsGraph, "two_stage_blur_compute_at_x")
		assertResult(correctAst)(blurProg.scheduleRep)
	}

	"The two stage blur with computeRoot should have the below tree" should "have the below tree" in {
		println("Two stage blur with compute root:")
		val blurProg = new TwoStageBoxBlurComputeRoot with CompilerInstance with TestAstOps
		val blurProgAnalysis = new TwoStageBoxBlurComputeRoot with TestPipelineAnalysis

		val correctAst: ScheduleNode[String, String] = new RootNode(List(
			new StorageNode("g", List(
				new LoopNode("y", "g", Sequential, List(
					new LoopNode("x", "g", Sequential, List(
						new ComputeNode("g", List())
					))
				)),
				new StorageNode("i", List(
					new LoopNode("y", "i", Sequential, List(
						new LoopNode("x", "i", Sequential, List(
							new ComputeNode("i", List())
						))
					))
				))
			))
		))

		blurProg.compile(blurProgAnalysis.getBoundsGraph, "two_stage_blur_compute_at_root")
		assertResult(correctAst)(blurProg.scheduleRep)
	}

	"The grad program with a split variable" should "split the x variable in 2" in {
		println("Grad x split: ")
		val gradProg = new GradSplit with CompilerInstance with TestAstOps
		val gradProgAnalysis = new GradSplit with TestPipelineAnalysis
		val correctAst: ScheduleNode[String, String] = new RootNode(List(
			new StorageNode("f", List(
				new LoopNode("y", "f", Sequential, List(
					new LoopNode("x_outer", "f", Sequential, List(
						new LoopNode("x_inner", "f", Sequential, List(
							new ComputeNode("f", List())
						))
					))
				))
			))
		))

		gradProg.compile(gradProgAnalysis.getBoundsGraph, "split_grad")
		assertResult(correctAst)(gradProg.scheduleRep)
	}

	"The grad program with two split variables" should "split the variable x and y in 2" in {
		println("Grad x and y split: ")
		val gradProg = new DoubleGradSplit with CompilerInstance with TestAstOps
		val gradProgAnalysis = new DoubleGradSplit with TestPipelineAnalysis
		val correctAst: ScheduleNode[String, String] = new RootNode(List(
			new StorageNode("f", List(
				new LoopNode("y_outer", "f", Sequential, List(
					new LoopNode("y_inner", "f", Sequential, List(
						new LoopNode("x_outer", "f", Sequential, List(
							new LoopNode("x_inner", "f", Sequential, List(
								new ComputeNode("f", List())
							))
						))
					))
				))
			))
		))

		gradProg.compile(gradProgAnalysis.getBoundsGraph, "2split_grad")
		assertResult(correctAst)(gradProg.scheduleRep)
	}

	"The box blur program with two split variables" should "split the variable x and y in 2" in {
		println("Box blur split: ")
		val gradProg = new TwoStageBoxBlurWithSplitVar with CompilerInstance with TestAstOps
		val gradProgAnalysis = new TwoStageBoxBlurWithSplitVar with TestPipelineAnalysis
		val correctAst: ScheduleNode[String, String] = new RootNode(List(
			new StorageNode("i", List(
				new LoopNode("y", "i", Sequential, List(
					new StorageNode("g", List(
						new LoopNode("y_outer", "g", Sequential, List(
							new LoopNode("y_inner", "g", Sequential, List(
								new LoopNode("x", "g", Sequential, List(
									new ComputeNode("g", List())
								))
							))
						)),
						new LoopNode("x", "i", Sequential, List(
							new ComputeNode("i", List())
						))
					))
				))
			))
		))

		gradProg.compile(gradProgAnalysis.getBoundsGraph, "split_blur")
		assertResult(correctAst)(gradProg.scheduleRep)
	}

	"The box blur program store root and split" should "split the variable x and y in 2" in {
		println("Box blur split, store root: ")
		val gradProg = new TwoStageBoxBlurStoreRootSplit with CompilerInstance with TestAstOps
		val gradProgAnalysis = new TwoStageBoxBlurStoreRootSplit with TestPipelineAnalysis
		val correctAst: ScheduleNode[String, String] = new RootNode(List(
			new StorageNode("f", List(
				new StorageNode("g", List(
					new LoopNode("y", "g", Sequential, List(
						new LoopNode("y_outer", "f", Sequential, List(
							new LoopNode("y_inner", "f", Sequential, List(
								new LoopNode("x", "f", Sequential, List(
									new ComputeNode("f", List())
								))
							))
						)),
						new LoopNode("x", "g", Sequential, List(
							new ComputeNode("g", List())
						))
					))
				))
			))
		))

		gradProg.compile(gradProgAnalysis.getBoundsGraph, "split_blur_store_root")
		assertResult(correctAst)(gradProg.scheduleRep)
	}

	"One stage box blur split loops reordered" should "reoder x and y" in {
		println("One stage blur, reordered: ")
		val blurProg = new OneStageBoxBlurSplitLoopsReordered with CompilerInstance
									 with TestAstOps
		val blurProgAnalysis = new OneStageBoxBlurSplitLoopsReordered
													 with TestPipelineAnalysis
		val correctAst: ScheduleNode[String, String] = new RootNode(List(
			new StorageNode("i", List(
				new LoopNode("x", "i", Sequential, List(
					new LoopNode("y", "i", Sequential, List(
						new ComputeNode("i", List())
					))
				))
			))
		))

		blurProg.compile(blurProgAnalysis.getBoundsGraph, "one_stage_blur_reordered")
		assertResult(correctAst)(blurProg.scheduleRep)
	}

	"Tiled grad" should "split and reorder x and y" in {
		println("Grad tiled: ")
		val blurProg = new SimpleGradTiled with CompilerInstance
									 with TestAstOps
		val blurProgAnalysis = new SimpleGradTiled
													 with TestPipelineAnalysis
		val correctAst: ScheduleNode[String, String] = new RootNode(List(
			new StorageNode("f", List(
				new LoopNode("y_outer", "f", Sequential, List(
					new LoopNode("x_outer", "f", Sequential, List(
						new LoopNode("y_inner", "f", Sequential, List(
							new LoopNode("x_inner", "f", Sequential, List(
								new ComputeNode("f", List())
							))
						))
					))
				))
			))
		))

		blurProg.compile(blurProgAnalysis.getBoundsGraph, "tiled_grad")
		assertResult(correctAst)(blurProg.scheduleRep)
	}

	"Fused blur" should "fuse the x and y variables" in {
		println("One stage blur fused: ")
		val blurProg = new FusedBlur with CompilerInstance
									 with TestAstOps
		val blurProgAnalysis = new FusedBlur with TestPipelineAnalysis

		val correctAst: ScheduleNode[String, String] = new RootNode(List(
			new StorageNode("i", List(
				new LoopNode("xy", "i", Sequential, List(
					new ComputeNode("i", List())
				))
			))
		))

		blurProg.compile(blurProgAnalysis.getBoundsGraph, "fused_blur")
		assertResult(correctAst)(blurProg.scheduleRep)
	}

	"IDProg" should "create a simple prog" in {
		println("IDProg: ")
		val blurProg =
			new IDProg with CompilerInstance with TestAstOps
		val blurProgAnalysis = new IDProg with TestPipelineAnalysis
		blurProg.compile(blurProgAnalysis.getBoundsGraph, "id_prog")
	}

	"TwoStageBlur" should "make a blurring progam (I need better testing)" in {
		println("two stage blur (simple)")

		val blurProg =
			new TwoStageBoxBlur with CompilerInstance with TestAstOps
		val blurProgAnalysis = new TwoStageBoxBlur with TestPipelineAnalysis
		blurProg.compile(blurProgAnalysis.getBoundsGraph, "two_stage_blur")
	}
	"OneStageBoxBlur" should "make a blurring progam (I need better testing)" in {
		println("one stage blur (simple)")

		val blurProg =
			new OneStageBoxBlur with CompilerInstance with TestAstOps
		val blurProgAnalysis = new OneStageBoxBlur with TestPipelineAnalysis
		blurProg.compile(blurProgAnalysis.getBoundsGraph, "one_stage_blur")
	}

	"Cropper" should "" in {
		println("cropper stage blur (simple)")

		val cropProg = new Cropper with CompilerInstance with TestAstOps
		val cropProgAnalysis = new Cropper with TestPipelineAnalysis
		cropProg.compile(cropProgAnalysis.getBoundsGraph, "cropper")
	}
}
