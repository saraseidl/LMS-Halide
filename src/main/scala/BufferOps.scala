package sepia

import lms.common._

trait ImageBufferOps extends PrimitiveOps with ArrayOps with ShortOps {
  type UShort = Short

  case class Buffer(val width: Rep[Int], val height: Rep[Int], val a: Rep[Array[UShort]]) {
    def apply(x: Rep[Int], y: Rep[Int]) =
      bufferApply(this, x, y)
  }

  class RGBValOps(v: RGBVal) {
    def +(other: RGBVal): RGBVal = RGBVal(v.red + other.red,
                                          v.green + other.green,
                                          v.blue + other.blue)
    def +(other: Rep[Int]): RGBVal = RGBVal(v.red + other,
                                               v.green + other,
                                               v.blue + other)

    def -(other: RGBVal): RGBVal = RGBVal(v.red - other.red,
                                          v.green - other.green,
                                          v.blue - other.blue)
    def -(other: Rep[Int]): RGBVal = RGBVal(v.red - other,
                                               v.green - other,
                                               v.blue - other)

    def *(other: RGBVal): RGBVal = RGBVal(v.red * other.red,
                                          v.green * other.green,
                                          v.blue * other.blue)
    def *(other: Rep[Int]): RGBVal = RGBVal(v.red * other,
                                               v.green * other,
                                               v.blue * other)

    def /(other: RGBVal): RGBVal = RGBVal(v.red / other.red,
                                          v.green / other.green,
                                          v.blue / other.blue)
    def /(other: Rep[Int]): RGBVal = RGBVal(v.red / other,
                                               v.green / other,
                                               v.blue / other)
  }

  implicit def RGBValToOps(v: RGBVal): RGBValOps = new RGBValOps(v)

  case class RGBVal(red: Rep[Int], green: Rep[Int], blue: Rep[Int])

  def bufferApply(b: Buffer, x: Rep[Int], y: Rep[Int]): RGBVal
}

trait CompilerImageOps extends ImageBufferOps {
  object NewBuffer {
    def apply(width: Rep[Int], height: Rep[Int]) = newBuffer(width, height)
  }

  implicit def bufferToBufferOps(b: Buffer): BufferOps = new BufferOps(b)

  class BufferOps(b: Buffer) {
    def update(x: Rep[Int], y: Rep[Int], v: RGBVal) = bufferUpdate(b, x, y, v)
    def memcpy(src: Buffer) = bufferMemCpy(src, b)
  }

  def newBuffer(width: Rep[Int], height: Rep[Int]): Buffer
  def bufferUpdate(b: Buffer, x: Rep[Int], y: Rep[Int], v: RGBVal): Rep[Unit]
  def bufferMemCpy(src: Buffer, dest: Buffer): Rep[Unit]

}

trait ImageBufferOpsExp extends ImageBufferOps with CompilerImageOps
                        with ArrayOpsExpOpt with PrimitiveOpsExpOpt {

  case class MemCpy(src: Rep[Array[UShort]], dest: Rep[Array[UShort]], size: Rep[Int])
    extends Def[Unit]

  override def newBuffer(m: Exp[Int], n: Exp[Int]) = {
    Buffer(m, n, array_obj_new[UShort](m * n * 3))
  }

  override def bufferApply(b: Buffer, x: Exp[Int], y: Exp[Int]) = {
    RGBVal(s2i(array_apply(b.a, 3 * (x + b.width * y) + 2)),
           s2i(array_apply(b.a, 3 * (x + b.width * y) + 1)),
           s2i(array_apply(b.a, 3 * (x + b.width * y))))
  }

  override def bufferUpdate(b: Buffer, x: Exp[Int], y: Exp[Int], v: RGBVal) = {
    array_update(b.a, 3 * (x + b.width * y) + 2, i2s(v.red))
    array_update(b.a, 3 * (x + b.width * y) + 1, i2s(v.green))
    array_update(b.a, 3 * (x + b.width * y), i2s(v.blue))
  }

  override def bufferMemCpy(src: Buffer, dest: Buffer) = {
    MemCpy(src.a, dest.a, src.width * src.height * 3)
  }
}