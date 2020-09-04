import kotlin.math.max

private fun nextLine() = readLine()!!
private fun nextInt() = nextLine().toInt()
private fun nextToks() = nextLine().split(" ")
private fun nextInts() = nextToks().map{it.toInt()}

data class Edge(val u: Int, val v: Int, val c: Int, val d: Int)
data class Frac(val num: Long, val den: Long)

operator fun Frac.compareTo(x: Frac) = (num*x.den).compareTo(den*x.num)

fun main() {
    val (n, m, low, up) = nextInts()
	val edges = (1..m).map{nextInts()}.map{(u,v,c,d) -> Edge(u,v,c,d)}
	var dp = Array<IntArray>(1+up){IntArray(n){0}}
	for (d in 0 until up) {
		for (e in edges) {
			if (e.d+d > up) continue
			dp[d+e.d][e.v] = max(dp[d+e.d][e.v],dp[d][e.u]+e.c)
		}
	}
	var ans = Frac(0L, 1L)
	for (d in low..up) {
	    val cand = Frac(dp[d].max()?.toLong() ?: 0L,d.toLong())
		if (cand > ans) ans = cand
	}
	println("${ans.num} ${ans.den}")
	//dp.forEach{println(it.joinToString(" "))}
}
