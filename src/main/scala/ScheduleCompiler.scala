package sepia


trait ScheduleCompiler extends CompilerFuncOps with AstOps {
	def computeLoopBounds(variable: Dim, stage: Func[_],
												boundsGraph: CallGraph,
												enclosingLoops: Map[(Func[_], String), Dim]): (Rep[Int], Rep[Int]) = {

		println("...loopBounds")
		if (variable.isInstanceOf[FusedDim]) {
			val fusedVariable = variable.asInstanceOf[FusedDim]
			val innerBounds = computeSimpleLoopBounds(fusedVariable.inner, stage,
																								boundsGraph, enclosingLoops)
			val outerBounds = computeSimpleLoopBounds(fusedVariable.outer, stage,
																								boundsGraph, enclosingLoops)
			val a = outerBounds._1
			val b = outerBounds._2
			val c = innerBounds._1
			val d = innerBounds._2
			val lowerBound = c + (d - c) * a
			val upperBound = d + (b - 1) * (d - c)
			variable.looplb_=(lowerBound)
			variable.loopub_=(upperBound)
			variable.shadowingUb_=(upperBound)
			(lowerBound, upperBound)
		} else if (variable.isInstanceOf[OuterDim]) {
			// redundancy?
			val outerVariable = variable.asInstanceOf[OuterDim]
			val normalBounds = computeSimpleLoopBounds(outerVariable.old, stage, boundsGraph, enclosingLoops)
			val a = normalBounds._1
			val b = normalBounds._2
			outerVariable.setOldLoopOffset(a)
			val lowerBound = 0
			// (x + y - 1) / y ceils
			// maybe q = (x % y) ? x / y + 1 : x / y is better?
			val extent = outerVariable.splitFactor
			val upperBound = (b - a + extent - 1) / extent
			variable.looplb_=(lowerBound)
			variable.loopub_=(upperBound)
			variable.shadowingUb_=(b)
			println(f".........outerLoopBounds ($lowerBound, $upperBound)")
			(lowerBound, upperBound)
		} else computeSimpleLoopBounds(variable, stage, boundsGraph, enclosingLoops)
	}

	def computeSimpleLoopBounds(variable: Dim, stage: Func[_],
															boundsGraph: CallGraph,
															enclosingLoops: Map[(Func[_], String), Dim]): (Rep[Int], Rep[Int]) = {
		println(f"......simple LB of stage: $stage, variable: $variable")
		if (stage.inlined) throw new InvalidSchedule(f"Inlined function $stage should have no loops")
		else if (stage.computeRoot) {
			println(".........compute Root")
			variable.looplb_=(variable.min)
			variable.loopub_=(variable.max)
			variable.shadowingUb_=(stage.vars(variable.shadowingName).max)
			println(f".........rootBounds (${variable.min}, ${variable.max})")
			(variable.min, variable.max)
		} else {
			val v = stage.computeAt
							.getOrElse(throw new InvalidSchedule(f"Non-inlined function $stage has no computeAt variable"))
			// shadowingName?
			val shouldAdjust = enclosingLoops.keySet contains (v.f, variable.shadowingName)
			println(f".........v.f: ${v.f}, variable.shadowingName: ${variable.shadowingName}")
			println(f".........enclosing Loops: $enclosingLoops")
			if (!shouldAdjust) {
				variable.looplb_=(variable.min)
				variable.loopub_=(variable.max)
				variable.shadowingUb_=(stage.vars(variable.shadowingName).max)
				println(f".........computeAtBounds (no adj) (${variable.min}, ${variable.max})")
				(variable.min, variable.max)
			}
			else {

				// JUST COMPUTE INNER
				val baseVar = enclosingLoops((v.f, variable.name))
				val baseVar2 = enclosingLoops.getOrElse((v.f, v.shadowingName), null)
				println(f".........baseVar: ${enclosingLoops((v.f, variable.name))}, baseVar2: ${enclosingLoops((v.f, v.shadowingName))}")

				// CHANGELOG:
				// before: variable.shadowingName needs to be x or y ? TOTO check deeper nesting
				val bound = BoundsAnalysis
						 .boundsForProdInCon(boundsGraph, stage.id, v.f.id, variable.name)
						 .getOrElse(throw new InvalidSchedule(f"No bounds for ${v.name} found"))

				// JUST COMPUTE INNER
				val unadjLb = baseVar2 match {
					case b if b == baseVar || b == null || !baseVar.sameAxisAs(baseVar2) => bound.mulLower * baseVar.v * baseVar.scaleRatio / bound.divLower + bound.lb
					case b =>  bound.mulLower * (baseVar.v * baseVar.scaleRatio + b.v) / bound.divLower + bound.lb
				}

				val unadjUb = baseVar2 match {
					case b if b == baseVar || b == null || !baseVar.sameAxisAs(baseVar2) => (bound.mulHigher * baseVar.v * baseVar.scaleRatio + baseVar.scaleRatio - 1) / bound.divHigher + bound.ub
					case b =>  bound.mulHigher * (baseVar.v * baseVar.scaleRatio + b.v) / bound.divHigher + bound.ub

				}

//			  val unadjLb = bound.mulLower * baseVar.v / bound.divLower + bound.lb
//				val unadjUb = bound.mulHigher * baseVar.v / bound.divHigher + bound.ub
			  variable.looplb_=(unadjLb)
				variable.shadowingUb_=(unadjUb + 1)
				variable.loopub_=(unadjUb + 1)
				println(f".........computeAtBounds (adj) (${unadjLb}, ${unadjUb + 1})")
				(unadjLb, unadjUb + 1)
			}
		}
	}

	//BOUNDS
	//scale dim
	def computeStorageBounds(stage: Func[_],
													 boundsGraph: CallGraph,
												 	 enclosingLoops: Map[(Func[_], String), Dim]): (Rep[Int], Rep[Int]) = {
		println()
		println("...storage Bounds")
		if (stage.inlined) throw new InvalidSchedule(f"Inlined function $stage should have no storage")
		else if (stage.storeRoot) (stage.domWidth, stage.domHeight)
		else {
			val v = stage.storeAt
							.getOrElse(throw new InvalidSchedule(f"Non-inlined function $stage has no storeAt"))
			println(f"......storing at $v dim with scaleRatio ${v.scaleRatio}")
			println(f"......enclosingLoops: $enclosingLoops")

			val shouldAdjustX = enclosingLoops.keySet contains (v.f, "x")
			println(f"......adjustX: $shouldAdjustX")
			val xDim: Rep[Int] = if (!shouldAdjustX) stage.domWidth else {
				      BoundsAnalysis
							.boundsForProdInCon(boundsGraph, stage.id, v.f.id, "x")
						  .getOrElse(throw new InvalidSchedule(f"No bounds for ${v.name} found"))
				      .width - 1 + v.scaleRatio
			}

			//outer dim
			val shouldAdjustY = enclosingLoops.keySet contains (v.f, "y")
			println(f"......adjustY: $shouldAdjustY")
			val yDim: Rep[Int] = if (!shouldAdjustY) stage.domWidth else {
				      BoundsAnalysis
						 .boundsForProdInCon(boundsGraph, stage.id, v.f.id, "y")
						 .getOrElse(throw new InvalidSchedule(f"No bounds for ${v.name} found"))
				     .width - 1 + v.scaleRatio
			}
			println()
			println(f"......storageBounds ($xDim, $yDim)")
			(xDim, yDim)
		}
	}

	def red(children: List[ScheduleNode],
					f: ScheduleNode => Map[(Func[_], String), Dim]) = {
		children.map(f(_)).foldLeft(Map[(Func[_], String), Dim]())(_ ++ _)
	}

	def getLoopsAfterSN(stage: Func[_], completeTree: ScheduleNode): Map[(Func[_], String), Dim] = {
		// Collect all of the loop nodes on the path from the storage node for f to its compute node

		def cnIsChild(node: ScheduleNode): Boolean = {
			node.exists((n: ScheduleNode) => n match {
				case ComputeNode(_, _) => n.belongsTo(stage)
				case _ => false
			})
		}

		def collectLoops(node: ScheduleNode): Map[(Func[_], String), Dim] = node match {
			case LoopNode(v, stage, _, children) => {
				if (cnIsChild(node)) red(children, collectLoops) + ((stage, v.name) -> v)
				else Map()
			}
			case _ => red(node.getChildren, collectLoops)
		}

		completeTree match {
			case RootNode(children) => red(children, getLoopsAfterSN(stage, _))
			case ComputeNode(_, children) => red(children, getLoopsAfterSN(stage, _))
			case s@StorageNode(otherStage, children) => {
				if (otherStage == stage) {
					val loops = collectLoops(s)
					loops
				}
				else red(children, getLoopsAfterSN(stage, _))
			}
			case LoopNode(_, _, _, children) => red(children, getLoopsAfterSN(stage, _))

		}
	}

	def notPreviouslyComputed(stage: Func[_],
												    completeTree: ScheduleNode,
											 	    boundsGraph: CallGraph,
														enclosingLoops: Map[(Func[_], String), Dim]): Rep[Boolean] = {

		println("NotComputed")
			if (stage.computeRoot) true
			else {
				val computeAtFunc: Func[_] = stage.computeAt.getOrElse(throw new InvalidSchedule("non-inlined function has no compute at")).f
				val relevantEnclosingLoops = getLoopsAfterSN(stage, completeTree).filterKeys(_._1 == computeAtFunc)

				println(f"Relevant enclosing loops: $relevantEnclosingLoops")
				val relevantBounds: Map[String, Bound] =
					for (((f, name), d) <- relevantEnclosingLoops)
							yield name -> {
								BoundsAnalysis.boundsForProdInCon(boundsGraph, stage.id, f.id, name).getOrElse(throw new Exception())
							}

				if (relevantBounds.isEmpty) unit(true)
				else {
					println(f"Bounds: ${relevantBounds.isEmpty}")
					val consumerVariables: Map[String, Dim] = computeAtFunc.vars.toMap

					 // Generate list for each variable
					 // v < v.min + overlapSize || v == upperLoopBound
					 def p(name: String) = {
						 val v = stage.vars(name)
						 val w = relevantBounds(name).width - 1
						 val (_, ub): (Rep[Int], Rep[Int]) = computeLoopBounds(v, v.f, boundsGraph, enclosingLoops)
						 v.v < v.min + w || v.v == ub - 1
					 }
					 relevantBounds.keys.toList.foldLeft(unit(false))({
						 case (acc, n) => acc || p(n)
					 })
				 }
			 }
	}

	def getOffsets(enclosingLoops: Map[(Func[_], String), Dim],
								 sn: ScheduleNode,
							 	 boundsGraph: CallGraph): List[(String, Rep[Int])] = {
			sn match {
				case StorageNode(f, _) => {
					if (f.computeRoot) {
						print("......compute root:")
						// variable.min
						// CHANGELOG:BOUNDS - only x/y bounds?
						f.vars.filterKeys( k => k == "x" || k == "y" ).map({ case (k, v) =>
								val bound = BoundsAnalysis
										 .boundsForProdInCon(boundsGraph, -1, f.id, k)
										 .getOrElse(Bound(0, 0, 1, 1, 1, 1))
								(k, v.min)}).toList
					} else {
						println("......not compute root:")
						// if a loop node is above sn, offset = lb
						// otherwise, offset = variable.min
						def getAdjustment(consumer: Func[_], name: String) = {
							val baseVar = enclosingLoops((consumer, name))
							val bound = BoundsAnalysis
									 .boundsForProdInCon(boundsGraph, f.id, consumer.id, name)
									 .getOrElse(throw new InvalidSchedule(f"No bounds for ${name} found"))
							baseVar.v + bound.lb * bound.mulLower / bound.divLower
						}

						// JUST COMPUTE INNER
						def getAdjustmentTest(consumer: Func[_], dim: String, name: String) = {
							println(f"........Enclosing loops: $enclosingLoops")
							println(f"........Looking for $dim and $name")
							val baseVar = enclosingLoops((consumer, name))
							val baseVar2 = enclosingLoops.getOrElse((consumer, dim), null)

							val bound = BoundsAnalysis
								.boundsForProdInCon(boundsGraph, f.id, consumer.id, name)
								.getOrElse(throw new InvalidSchedule(f"No bounds for ${name} found"))


							baseVar2 match {
								case b if b == baseVar || b == null || !baseVar.sameAxisAs(baseVar2) => baseVar.v * baseVar.scaleRatio + bound.lb * bound.mulLower / bound.divLower
								case b => baseVar.v * baseVar.scaleRatio + b.v + bound.lb * bound.mulLower / bound.divLower
							}
						}

						val computeAtFunc = f.computeAt.getOrElse(throw new InvalidSchedule("No compute at for non inlined function")).f
						val computeAtName = f.computeAt.getOrElse(throw new InvalidSchedule("No compute at for non inlined function")).shadowingName
						println(f"........Vars: ${f.vars.map({case (name, v) =>
							(name, if (enclosingLoops.keySet.contains((computeAtFunc, name))) getAdjustmentTest(computeAtFunc, computeAtName ,name) else v.min)
						}).toList}")

						f.vars.map({case (name, v) =>
							(name, if (enclosingLoops.keySet.contains((computeAtFunc, name))) getAdjustmentTest(computeAtFunc, computeAtName ,name) else v.min)
						}).toList
					}
				}
			}
	}

	def evalSched(node: ScheduleNode,
								boundsGraph: CallGraph,
								enclosingLoops: Map[(Func[_], String), Dim],
							  completeTree: ScheduleNode): Rep[Unit] = {
		node match {
    case LoopNode(variable, stage, loopType, children) =>
			println()
			println("evalLoop:")
			val (lb, ub) = computeLoopBounds(variable, stage, boundsGraph, enclosingLoops)
      loopType match {
        case Sequential() =>
          for (i <- (lb until ub): Rep[Range]) {
            variable.v_=(i)
						for (child <- children) evalSched(child, boundsGraph,
																							enclosingLoops ++ variable.pseudoLoops,
																							completeTree)
          }
        case Unrolled() =>
          for (i <- lb until ub) {
            variable.v_=(i)
            for (child <- children) evalSched(child, boundsGraph,
																							enclosingLoops ++ variable.pseudoLoops,
																							completeTree)
          }

				case Vectorized(n) => {
					// What I really want...
					/*for (i <- lb until ub: Vectorized[Range]) {
						variable.v_=(i)
						for (child <- children) evalSched(child, boundsGraph,
																							enclosingLoops ++ variable.pseudoLoops,
																							completeTree)
					}*/

					// TODO: Generalize - a lot!
					vectorized_loop(0 until n, i => {
						variable.v_=(i)
						//print(children)
						assert(children.length == 1)
						val child = children(0)
						child match {
							case ComputeNode(s, cs) if cs == List() => {
								if (notPreviouslyComputed(stage, completeTree, boundsGraph, enclosingLoops ++ variable.pseudoLoops)) {
									stage.storeInBuffer(stage.compute())
								}
							}
							case _ => throw new InvalidSchedule("Error: Can only vectorize loops with a direct, single compute node child.")
						}
					})
				}
      }

    case ComputeNode(stage, children) => {
			println()
			println("evalCompute:")
			//if (notPreviouslyComputed(stage, completeTree, boundsGraph, enclosingLoops)) {
				val v = stage.compute()
	      stage.storeInBuffer(v)
			//}
      for (child <- children) evalSched(child, boundsGraph, enclosingLoops, completeTree)
    }

 	  case StorageNode(stage, children) => {
			println()
			println("evalStore:")

			val dims = computeStorageBounds(stage, boundsGraph, enclosingLoops)
			stage.allocateNewBuffer(dims._1, dims._2)
			val offsets = getOffsets(enclosingLoops, node, boundsGraph)
			stage.setOffsets(offsets)
			println(f"...Offsets: $offsets")

   	 	for (child <- children) evalSched(child, boundsGraph, enclosingLoops, completeTree)
			stage.deallocBuffer()
 	  }

    case RootNode(children) => {
			println()
			println("evalRoot:")
      for (child <- children) evalSched(child, boundsGraph, enclosingLoops, completeTree)
    }
  }}
}
