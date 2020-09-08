import kotlin.system.exitProcess
import java.io.File
import java.math.BigInteger

fun testIf(pred: Boolean, msg: String = "") {
    if (!pred) throw Exception(msg)
}

fun verify(input: List<String>, answer: List<String>) {
    val firstLine = readLine()!!
    testIf(firstLine == "YES" || firstLine == "NO", "1st line: $firstLine" )
    val secondLine = readLine() ?: ""
    testIf(secondLine.all{it == '0' || it == '1'}, "2nd line: non-binary" )
    val thirdLine = readLine()
    testIf(thirdLine == null, "extra lines")
    if (answer[0] == "NO" && firstLine == "NO") {
        testIf(secondLine == "", "2nd line: non-empty")
        return // OK
    }
    val (n, m) = input[0].split(" ").map{it.toInt()}
    val color = secondLine
    testIf(n==color.length, "2nd line: wrong length")
    
    for (i in 1..m) {
        val (u, v, c) = input[i].split(" ").map{it.toInt()-1}
        when (c) {
            0 -> testIf(color[u] == '1' || color[v] == '1', "(${1+u},${1+v}) is wrong")
            1 -> testIf(color[u] == '0' || color[v] == '0', "(${1+u},${1+v}) is wrong")
            2 -> testIf(color[u] != color[v], "(${1+u},${1+v}) is wrong")
            3 -> testIf(color[u] == color[v], "(${1+u},${1+v}) is wrong")
            else -> throw Exception("Bad input")
        }
    }
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
