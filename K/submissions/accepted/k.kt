private fun nextLine() = readLine()!!
private fun nextToks() = nextLine().split(" ").filter{it.length>0}
private fun nextBigs() = nextToks().map{it.toBigInteger()}

fun main() {
    val (ax, ay) = nextBigs()
    val (bx, by) = nextBigs()
    val (cx, cy) = nextBigs()
    val dx = bx-ax
    val dy = by-ay
    val DX = cx-ax
    val DY = cy-ay
    val dxx = bx-cx
    val dyy = by-cy
    if ((dx*DY).compareTo(dy*DX)==0)
        println("-1")
    else
        println(dx.gcd(dy)+DX.gcd(DY)+dxx.gcd(dyy))
}
