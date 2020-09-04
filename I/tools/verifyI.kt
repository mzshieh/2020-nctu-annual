import kotlin.system.exitProcess
import java.io.File
import java.math.BigInteger
import java.math.BigDecimal

fun testIf(pred: Boolean, msg: String = "Failed") {
    if (!pred) throw Exception(msg)
}

private fun nextLine() = readLine()!!
private fun nextToks() = nextLine().split(" ").filter{it.length>0}
private fun nextBigs() = nextToks().map{it.toBigInteger()}

fun verify(input: List<String>, answer: List<String>) {
    val (ax, ay) = nextBigs()
    val (bx, by) = nextBigs()
    val (cx, cy) = nextBigs()
    val dx = bx-ax
    val dy = by-ay
    val DX = cx-ax
    val DY = cy-ay
    val dxx = bx-cx
    val dyy = by-cy
    val n = input[0].toBigInteger()
    testIf((dx*DY).compareTo(dy*DX)!=0, "Not triangle")
    testIf(dx.gcd(dy)+DX.gcd(DY)+dxx.gcd(dyy)==n, "Wrong number")
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
