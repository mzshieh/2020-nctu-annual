import kotlin.system.exitProcess
import java.io.File
import java.math.BigInteger
import java.math.BigDecimal

fun testIf(pred: Boolean, msg: String = "Failed") {
    if (!pred) throw Exception(msg)
}

/*
fun BigDecimal.sq() = this * this

fun BigDecimal.pow(x: Int): BigDecimal {
    if (x == 0) return "1".toBigDecimal()
    if (x % 2 == 0) return pow(x/2).sq()
    return pow(x/2).sq() * this
}
*/

fun verify(input: List<String>, answer: List<String>) {
    //println("${input.size} ${answer.size}")
    if (answer[0] == "-1") {
        testIf(readLine()!! == "-1")
        testIf(readLine() == null, "Extra output")
        return
    }
    val (sn, sk, sa) = input[0].split(" ").filter{it.length>0}
    val n = sn.toInt()
    val k = sk.toInt()
    val a = sa.toBigDecimal().pow(n)
    val adj = (1 until n).map{readLine()!!.split(" ").filter{it.length>0}.map{it.toInt()-1}}
    //adj.forEach{println("$it")}
    var dp = Array<BigInteger>(n){BigInteger.ZERO}
    dp[0] = BigInteger.ONE
    for (i in 0 until n-1) {
        testIf(adj[i].size <= k, "too many edge")
        testIf(adj[i].min()!! >= i+1, "not acyclic")
        testIf(adj[i].distinct().size == adj[i].size, "not simple")
        for (j in adj[i]) dp[j] += dp[i]
    }
    println("${dp[n-1]}")
    testIf(dp[n-1].toBigDecimal() >= a, "Not enough")
    testIf(readLine() == null, "Extra output") 
}

fun main(args: Array<String>) {
    try{
        verify(File(args[0]).readLines(), File(args[1]).readLines())
    } catch (e: Exception) {
        println(e)
        println("Wrong Answer")
        exitProcess(43)
    }
    println("Correct")
    exitProcess(42)
}
