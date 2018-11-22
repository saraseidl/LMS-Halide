package sepia

import scala.collection.mutable.ListBuffer

case class Bound(val lb: Int, val ub: Int) {
	// Inclusive bounds
	def join(other: Bound): Bound = {
		val newLb = if (lb < other.lb) lb else other.lb
		val newUb = if (ub > other.ub) ub else other.ub
	  Bound(newLb, newUb)
	}

	def add(other: Bound): Bound = {
		Bound(lb + other.lb, ub + other.ub)
	}

	def width(): Int = (ub - lb) + 1
}

object Bound {
	val zero = Bound(Int.MaxValue, Int.MinValue)
}

trait PipelineForAnalysis extends DslExp with SymbolicOpsExp
													with SymbolicFuncOpsExp with Pipeline {
	// Before we pass the program to the staged interpreter, we must
  // first do some analysis on

	def treeTraversal[T](f: List[T] => T, m: Exp[_] => T,
                       node: Def[_]): T = node match {
      case ObjDoubleParseDouble(x)      => f(List(x).map(m))
      case ObjDoublePositiveInfinity()  => f(List().map(m))
      case ObjDoubleNegativeInfinity()  => f(List().map(m))
      case ObjDoubleMinValue()          => f(List().map(m))
      case ObjDoubleMaxValue()          => f(List().map(m))
      case DoubleFloatValue(x)          => f(List(x).map(m))
      case DoubleToInt(x)               => f(List(x).map(m))
      case DoubleToFloat(x)             => f(List(x).map(m))
      case DoublePlus(x,y)              => f(List(x, y).map(m))
      case DoubleMinus(x,y)             => f(List(x, y).map(m))
      case DoubleTimes(x,y)             => f(List(x, y).map(m))
      case DoubleDivide(x,y)            => f(List(x, y).map(m))
      case ObjFloatParseFloat(x)        => f(List(x).map(m))
      case FloatToInt(x)                => f(List(x).map(m))
      case FloatToDouble(x)             => f(List(x).map(m))
      case FloatPlus(x,y)               => f(List(x, y).map(m))
      case FloatMinus(x,y)              => f(List(x, y).map(m))
      case FloatTimes(x,y)              => f(List(x, y).map(m))
      case FloatDivide(x,y)             => f(List(x, y).map(m))
      case ObjIntegerParseInt(x)        => f(List(x).map(m))
      case ObjIntMaxValue()             => f(List().map(m))
      case ObjIntMinValue()             => f(List().map(m))
      case IntDoubleValue(x)            => f(List(x).map(m))
      case IntFloatValue(x)             => f(List(x).map(m))
      case IntBitwiseNot(x)             => f(List(x).map(m))
      case IntPlus(x,y)                 => f(List(x, y).map(m))
      case IntMinus(x,y)                => f(List(x, y).map(m))
      case IntTimes(x,y)                => f(List(x, y).map(m))
      case IntDivide(x,y)               => f(List(x, y).map(m))
      case IntMod(x,y)                  => f(List(x, y).map(m))
      case IntBinaryOr(x,y)             => f(List(x, y).map(m))
      case IntBinaryAnd(x,y)            => f(List(x, y).map(m))
      case IntBinaryXor(x,y)            => f(List(x, y).map(m))
      case IntToLong(x)                 => f(List(x).map(m))
      case IntToFloat(x)                => f(List(x).map(m))
      case IntToDouble(x)               => f(List(x).map(m))
      case IntShiftLeft(x,y)            => f(List(x, y).map(m))
      case IntShiftRightLogical(x,y)    => f(List(x, y).map(m))
      case IntShiftRightArith(x,y)      => f(List(x, y).map(m))
      case ObjLongParseLong(x)          => f(List(x).map(m))
      case LongMod(x,y)                 => f(List(x, y).map(m))
      case LongShiftLeft(x,y)           => f(List(x, y).map(m))
      case LongBinaryOr(x,y)            => f(List(x, y).map(m))
      case LongBinaryAnd(x,y)           => f(List(x, y).map(m))
      case LongToInt(x)                 => f(List(x).map(m))
      case LongShiftRightUnsigned(x,y)  => f(List(x, y).map(m))
			case SymbolicInt(_) 							=> f(List().map(m))
			case ShortPlus(a, b)							=> f(List(a, b).map(m))
			case ShortDivide(a, b)						=> f(List(a, b).map(m))
			case ShortMinus(a, b)							=> f(List(a, b).map(m))
			case ShortTimes(a, b)							=> f(List(a, b).map(m))
			case ShortConvert(a)				  		=> f(List(a).map(m))
  }

	var funcs: Map[(Rep[Int], Rep[Int]) => RGBVal, Int] = Map()
	private var id = 0

	def toFunc(f: (Rep[Int], Rep[Int]) => RGBVal, dom: ((Int, Int), (Int, Int))): Func = {
		funcs += (f -> id)
		id += 1
		mkFunc(f, dom, id)
	}

	def mergeBoundsMaps(b1: Map[Func, Map[String, Bound]],
											b2: Map[Func, Map[String, Bound]]): Map[Func, Map[String, Bound]] = {
		// Given two maps for func -> bound, bound, will join the two maps together.
		// If the two maps both have a bound for key k, will merge the bounds by taking
		// the smallest of the min and the largest of the max.

		def mergeSingleBoundSet(a: Map[String, Bound], b: Map[String, Bound]) = {
			a ++ b.map { case (k, bBound) => k -> {
					val aBound = a.getOrElse(k, Bound.zero)
					aBound join bBound
				}}
		}

		b1 ++ b2.map{ case (k,v) => k -> {
				mergeSingleBoundSet(v, b1.getOrElse(k, Map())) }}
	}

	def extractBound(expr: Exp[_], dim: String) = expr match {
		case Def(v) => v match {
			case IntPlus(Def(SymbolicInt(dim)), Const(k)) => Bound(k, k)
			case IntPlus(Const(k), Def(SymbolicInt(dim))) => Bound(k, k)
			case IntMinus(Const(k), Def(SymbolicInt(dim))) => Bound(-k, -k)
			case IntMinus(Def(SymbolicInt(dim)), Const(k)) => Bound(-k, -k)
			case SymbolicInt(dim) => Bound(0, 0)
			case _ => throw new InvalidAlgorithm(f"Error: Invalid x input to function, $v")
		}
		case Const(_) => Bound(0, 0)
	}


	def analyseInputTransformations(xExpr: Exp[_],
																	yExpr: Exp[_]): Map[String, Bound] = {
	// For now, we just analyse additive constants on x / y coordinates.
	// Do we need anything else?

		val xTransformation: Bound = extractBound(xExpr, "x")
		val yTransformation: Bound = extractBound(yExpr, "y")

		Map("x" -> xTransformation, "y" -> yTransformation)
	}

	def getInputTransformations(v: RGBVal): Map[Func, Map[String, Bound]] = {
		mergeBoundsMaps(getInputTransformations(v.red),
										mergeBoundsMaps(getInputTransformations(v.blue),
																		getInputTransformations(v.green)))
	}

  def getInputTransformations(e: Exp[_]): Map[Func, Map[String, Bound]] = e match {
    case Def(v) => v match {
    	case FuncApplication(func, xExpr, yExpr) =>  {
				Map(func -> analyseInputTransformations(xExpr, yExpr))
			}
			// This is for the special case when we're calling in...
			case ArrayApply(a, _) => {
				a match {
					case Def(SymbolicArray()) => Map()
				}
			}

      case x => {
				treeTraversal[Map[Func, Map[String, Bound]]](
					_.foldLeft(Map[Func, Map[String, Bound]]())(mergeBoundsMaps),
					getInputTransformations _, x)
			}
    }
    case Const(_) => Map()
  }

	def getInputBounds(): Map[Func, Map[Func, Map[String, Bound]]] = {
		// f -> (g1 -> (a, b), g2 -> (c, d) ...) means that
		// f calls functions g1, g2 with (a, b) a bound on
		// g1's input and (c, d) a bound on g2's input.
		val symbolicInput = Buffer(0, 0, newSymbolicArray())
		prog(symbolicInput)
		funcs.keys.foldLeft(Map[Func, Map[Func, Map[String, Bound]]]())
								{(m, f) =>
									m + (f -> getInputTransformations(f(newSymbolicInt("x"),
																										  newSymbolicInt("y"))))}
	}

	def getBoundsGraph(): Map[Int, Map[Int, Map[String, Bound]]] = {
	    getInputBounds.map{case (k, v) => funcs(k) ->
	         v.map{case (k1, v2) => funcs(k1) -> v2}}
	}

	class UselessFuncOps(f: Func) extends FuncOps(f) {
		// Just convert sched ops to no-ops in the analysis phase
		override def computeAt(consumer: Func, s: String): Unit = return
	}

	override implicit def toFuncOps(f: Func) = new UselessFuncOps(f)
}
