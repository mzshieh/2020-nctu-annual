import java.math.BigInteger
import kotlin.math.sqrt
private fun nextLine() = readLine()!!
private fun nextInt() = nextLine().toInt()
private fun nextToks() = nextLine().split(" ").filter{it.length > 0}
private fun nextInts() = nextToks().map{it.toInt()}
private fun nextLongs() = nextToks().map{it.toLong()}

typealias BInt = BigInteger

data class Frac(val num: BInt, val den: BInt = BInt.ONE) {
	fun canonical(): Frac {
		val g = num.gcd(den)
		if (den < BInt.ZERO)
			return Frac(-num/g, -den/g)
		return Frac(num/g,den/g)
	}
	override fun toString() = if (canonical().den>BInt.ONE) "${canonical().num}/${canonical().den}" else "$num"
	operator fun compareTo(x: Frac) = (num*x.den).compareTo(den*x.num)
	operator fun times(x: Frac) = Frac(num*x.num,den*x.den)
	operator fun div(x: Frac) = Frac(num*x.den,den*x.num)
	operator fun plus(x: Frac) = Frac(num*x.den+x.num*den,den*x.den)
	operator fun minus(x: Frac) = Frac(num*x.den-x.num*den,den*x.den)
	operator fun unaryMinus() = Frac(-num,den)
	fun toDouble() = num.toDouble() / den.toDouble()
}
fun String.toFrac() = Frac(this.toBigInteger())


typealias Point = Pair<Frac,Frac>

private fun nextFracs() = nextToks().map{it.toFrac()}
private fun nextPt(): Point {
	val (num, den) = nextFracs()
	return Pair(num, den)
}

infix fun Point.dot(x: Point) = first * x.first + second * x.second
infix fun Point.cross(x: Point) = first * x.second - second * x.first
operator fun Point.plus(x: Point) = Pair(first+x.first, second+x.second)
operator fun Point.minus(x: Point) = Pair(first-x.first, second-x.second)
operator fun Point.times(x: Frac) = Pair(x*first,x*second)
operator fun Frac.times(x: Point) = x * this
fun Point.mag() = sqrt((this dot this).toDouble())

data class Seg(val p: Point, val q: Point)
fun Seg.dir() = p - q
fun Seg.length() = dir().mag()

infix fun Seg.intersect(other: Seg): Point? {
	val det = dir() cross other.dir()
	if (det.num == BInt.ZERO) return null
	val (dx,dy) = other.dir()
	val (DX,DY) = p - other.p
	val t = (dy*DX - dx*DY)/det
	//println("t = $t, det = $det, ? = ${dy*DX-dx*DY}, (dx,dy,DX,DY)=($dx,$dy,$DX,$DY)")
	return p + (q-p)*t
}

fun main() {
	val pts = (1..4).map{nextPt()}
	var cand = ArrayList<Point>(pts)
	for (i in 0 until 4)
		for (j in i+1 until 4) {
			val (k, l) = (0..3).filter{it != i && it != j}
			val x = Seg(pts[i],pts[j]) intersect Seg(pts[k],pts[l])
			if (x == null) continue
			cand.add(x)
		}
	// println("$pts")
	// println("$cand")
	var ans = cand[0]
	var best = 1e10
	for (c in cand) {
		val dist = pts.map{Seg(it,c).length()}.sum()
		//println("$c $dist")
		if (best > dist) {
			best = dist
			ans = c
		}
	}
	println("${ans.first.toDouble()} ${ans.second.toDouble()}")
}
