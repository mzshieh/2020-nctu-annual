import java.util.TreeMap
import kotlin.math.min

private fun readInt() = readLine()!!.toInt()

fun main() {
    var dp = IntArray(100001){it-1}
    var s = TreeMap<Int,Int>()
    for (i in 0..1000) s[i*i] = i
    for (i in 2..100000) {
        for (j in 1..(i/2)) dp[i] = min(dp[i], dp[j]+dp[i-j]+1)
        for (j in 2..(s.floorEntry(i).value)) {
            if (i%j == 0) dp[i] = min(dp[i], dp[j]+dp[i/j]+1)
        }
    }
    for (i in 1..readInt()) {
        println("${dp[readInt()]}")
    }
}
