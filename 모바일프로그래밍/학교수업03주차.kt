val -> 값이 변하지 않는다
var -> 값이 변한다
Null Safety
val languageName: String?=Null 로 해준다


val count = 50
if (count == 42) {
  println("Get answer.")
}
else if (count > 35) {
  println("Close to answer.")
}
else{
  println("Fail.")
}


var a = 5
var b = 3
var bigger = if(a>b) a else b
println(bigger)
var bigger2 = if(a>b) {
  a = a - b
  a // result 
} else {
  b = b - a
  b //result
}
println(bigger2)


val count = 42
val answerString: String
when(count) {
  42 -> {
    answerString = "Answer is 42."
  }
  35 -> {
    answerString = "Answer is 35."
  }   
  else -> {
    answerString = "Fail."
  }
}
println(answerString)


val count = 37
val answerString: String
when { //when은 switch 기능이라고 봐도 될듯
  count == 42 -> answerString = "Get answer."
  count > 35 -> answerString = "Close to nswer."
  else -> answerString = "Fail."
}
println(answerString)


val now = 10
val answerString: String
when(now) {
  8 -> answerString = "It’s 8 o’clock."
  9, 10 -> answerString = "It’s 9 or 10 o’clock."
  else -> answerString = "What time is it now?"
}
println(answerString)


val age = 15
val answerString: String
when(age) {
  in 10..19 -> {
  answerString = "Teen-ager."
  }
  !in 10..19 -> {
    answerString = "Not teen-ager." 
  }
  else -> {
    answerString = "How old are you?"
  }
}


var current = 1
val until = 12
while(current < until) {
   println("Current ${current}.")
   current++
}


var current = 1
val until = 12
do {
   println("Current ${current}.")
   current++
  } while(current < until)


for(index in 1..10) {
  println("Current ${index}.")
}
for(index in 1 until 10) {
  println("Current ${index}.")
}
for(index in 1..10 step 2) {
  println("Current ${index}.")
}
for(index in 10 downTo 1) {
  println("Current ${index}.")
}


var current = 1
val until = 3
while(current < until) {
  println("Current ${current}.")
  if(current == 2) break
  current++
}


var current = 1
val until = 3
while(current < until) {
  var num2 = 5
  while(num2 > 0) {
    if(num2 < 3) {
      break
    }
    println("Current ${current}, num2 ${num2}.")
    num2--
  }
  current++
}


var current = 1
val until = 3
outer@while(current < until) {  
  var num2 = 5
  inner@while(num2 > 0) {
    if(num2 < 3) {
      break@inner //라벨로 조건을 걸 수 있다
    }
    println("Current ${current}, num2 ${num2}.")
    num2--
  }
  current++
}


var current = 1
val until = 3
outer@while(current < until) {
  var num2 = 5
  inner@while(num2 > 0) {
    if(num2 < 3) {
      break@outer
    }
    println("Current ${current}, num2 ${num2}.")
    num2--
  }
  current++
}


for(index in 1..5) {
  if(index >= 2 && index <4) {
  continue
  }
  println("Index ${index}.")
}


for(index in 1..2) {
  for(index2 in 1..5) {
    if(index2 >= 2 && index2 <4) {
      continue
    }
    println("Index ${index}, Index2 ${index2}.")
  }
}


outer@for(index in 1..2) {
  inner@for(index2 in 1..5) {
    if(index2 >= 2 && index2 <4) {
      continue@inner
    }
    println("Index ${index}, Index2 ${index2}.")
  }
}


outer@for(index in 1..2) {
  inner@for(index2 in 1..5) {
    if(index2 >= 2 && index2 <4) {
      continue@outer
    }
    println("Index ${index}, Index2 ${index2}.")
  }
}


var intArr = IntArray(10)
var longArr = LongArray(10)
var charArr = CharArray(10)
var floatArr = FloatArray(10)
var doubleArr = DoubleArray(10)
intArr[0] = 90
intArr.set(1, 80) // 1번째 값 80
intArr.set(9, 95) 
intArr.set(10, 100) -> error


var intArr = IntArray(10)
var longArr = LongArray(10)
var charArr = CharArray(10)
var floatArr = FloatArray(10)
var doubleArr = DoubleArray(10)
intArr[0] = 90
intArr.set(1, 80)
intArr.set(9, 95)
println(intArr [1])
println(intArr [9])
println(intArr .get(0)) //90출력


var daysArr = arrayOf<Short>(31, 28, 31, 30, 
  31, 30, 31, 31, 
  30, 31, 30, 31)
// Implicit
var monthArr = arrayOf("Jan","Feb","Mar",
  "Apr","May","Jun",
  "Jul","Aug","Sep",
  "Oct","Nov","Dec")
for (i in 0..11){
  println("${monthArr[i]} has ${daysArr[i]} days");
}


fun sum(a : Int, b : Int) : Int {
  return a+b
}
fun main() {
  println(sum(3, 4))
}


fun sum(a : Int, b : Int = 10) : Int {
  return a+b
}
fun main() {
  println(sum(3))
}


fun sum(a : Int=10, b : Int) : Int {
  return a+b
}
fun main() {
  println(sum(3))//b값이 없다
}


fun sum(a : Int=10, b : Int) : Int {
 return a+b
}
fun main() {
  println(sum( b=3))
  println(sum( 5, 3))
  println(sum( a=5, b=3))
}