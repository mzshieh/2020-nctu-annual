import kotlin.system.exitProcess
import java.io.File
import kotlin.math.sqrt

fun testIf(pred: Boolean, msg: String) {
    if (!pred) throw Exception(msg)
}

fun Double.sq() = this*this

fun verify(input: List<String>, answer: List<String>) {
	val (ansX, ansY) = answer[0].split(" ").map{it.toDouble()}
	val pts = input.map{it.split(" ").map{it.toBigDecimal().toDouble()}}
	val (outX, outY) = readLine()!!.split(" ").map{it.toDouble()}
	var ansLen = pts.map{(x,y) -> sqrt((x-ansX).sq() + (y-ansY).sq())}.sum()
	var outLen = pts.map{(x,y) -> sqrt((x-outX).sq() + (y-outY).sq())}.sum()
	testIf(outLen / ansLen <= 1.0 + 1e-6, "Too long")
	testIf(readLine() == null, "Extra lines")
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
