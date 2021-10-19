// 생성자
class Car(var model:String, var color:String) {
  fun getModelName():String {
    return model;
  }
  fun getCarColor():String {
    return color;
  }
}
fun main() {
  var aventador = Car("aventador", "blue")
  var pony = Car("pony", "red")
  println("My first car was ${pony.color} ${pony.model}")
  println("My dream car is ${aventador.getCarColor()} ${aventador.getModelName()}")
}


//init
class Car(var model:String, var color:String) {
  fun getModelName():String {
  return model;
  }
  fun getCarColor():String {
    return color;
  }
  init {
    println("${color} ${model} car created!")
  }
}
fun main() {
  var aventador = Car("aventador", "blue")
  var pony = Car("pony", "red")
  println("My first car was ${pony.color} ${pony.model}")
  println("My dream car is ${aventador.getCarColor()} ${aventador.getModelName()}")
}


//secondary 생성자
class Car {
  var model:String=""
  var color:String=""
  fun getModelName():String {
    return model;
  }
  fun getCarColor():String {
    return color;
  }  
  constructor(model:String, color:String) {
    this.model = model
    this.color = color
    println("${color} ${model} car created!")
  }
}
fun main() {
  var aventador = Car("aventador", "blue")
  var pony = Car("pony", "red")
  println("My first car was ${pony.color} ${pony.model}")
  println("My dream car is ${aventador.getCarColor()} ${aventador.getModelName()}")
}


//상속
open class Car(var model:String, var color:String) {
  fun getModelName():String {
    return model;
  }
  fun getCarColor():String {
  return color;
  }
}
class ElectricCar(model:String, color:String, var battCap:Int) : Car(model, color) {
  var batteryLevel:Int=100
  fun getBattLevel():Int {
  return batteryLevel;
  }
  fun charging(level:Int) {
    batteryLevel = level
    return;
  }
}
fun main() {
  var tesla = ElectricCar("modelX", "white", 1000)
  println("My car is ${tesla.color} ${tesla.model}")
  println("Current battery level is ${tesla.getBattLevel()}. Battery capacity is ${tesla.battCap} Ah")
}


//secondary constructor
open class Car {
  var model:String=""
  var color:String=""
  fun getModelName():String {
    return model;
  }
  fun getCarColor():String {
  return color;
  }
  constructor(cmodel:String, ccolor:String) {
    model = cmodel
    color = ccolor
     println("${color} ${model} car created!")
  } 
}
class ElectricCar : Car {
  var batteryLevel:Int=100
  var battCap:Int=1000
  fun getBattLevel():Int {
    return batteryLevel;
  }
  fun charging(level:Int) {
    batteryLevel = level
  return;
  }
  constructor(cmodel:String, ccolor:String, cbattCap:Int) : super(cmodel, ccolor) {
    battCap = cbattCap
  }   
}


//오버라이딩
open class Car {
  var level:Int = 0
  open fun filling(kind:String, level:Int) {
    this.level = level
    println("Add ${level} litres of ${kind}")
  } 
}
class ElectricCar : Car() {
  override fun filling(_kind:String, _level:Int) {
    level = _level
  println("Charge ${level} Ampere of ${_kind}")
  } 
}
fun main() {
  var tesla = ElectricCar()
  tesla.filling("electric", 50) 
}


open class Car {
  var level:Int = 0
  open fun filling(kind:String, level:Int) {
    this.level = level
    println("Add ${level} litres of ${kind}")
  }
}
class ElectricCar : Car() {
  override fun filling(_kind:String, _level:Int) {
    level = _level
    println("Charge ${level} Ampere of ${_kind}")
    super.filling(_kind, _level);
  }
}
fun main() {
  var tesla = ElectricCar()
  tesla.filling("electric", 50)
}


//추상클래스
abstract class Car {
  abstract var fuelLevel:Int
  abstract fun filling(kind:String, level:Int)
}
class ElectricCar : Car() {
  override var fuelLevel:Int = 0
  override fun filling(kind:String, level:Int) {
    fuelLevel = level
    println("Charge ${level} Ampere of ${kind}")
  } 
}
fun main() {
  var tesla = ElectricCar()
  tesla.filling("electric", 50) 
}


//인터페이스
interface Pet {
  var category:String
  fun feeding()
  fun patting() {
    println("Keep patting")
  } 
}
class Cat(override var category:String) : Pet {
  override fun feeding() {
    println("Feed tuna can!")
  } 
}
fun main() {
  var cat = Cat("small")
  println("Cat category : ${cat.category}")
  cat.feeding()
  cat.patting() 
}


//인터페이스 초기화
interface Pet {
  var category:String
  fun feeding()
  fun patting() {
    println("Keep patting")
  } 
}
class Cat(categ:String) : Pet {
  override var category:String = ""
  override fun feeding() {
    println("Feed tuna can!")
  }
  init {
    category = categ
  } 
}
fun main() {
  var cat = Cat("small")
  println("Cat category : ${cat.category}")
  cat.feeding()
  cat.patting() 
}


//인터페이스 생성자
interface Pet {
  var category:String
  fun feeding()
  fun patting() {
    println("Keep patting")
  } 
}
class Cat : Pet {
  override var category:String = ""
  override fun feeding() {
    println("Feed tuna can!")
  }
  constructor(categ:String) {
    category = categ
  } 
}
fun main() {
  var cat = Cat("small")
  println("Cat category : ${cat.category}")
  cat.feeding()
  cat.patting()
}


//인스턴스 생성하는 새로운 방법
interface Pet {
  var category:String
  fun feeding()
  fun patting() {
    println("Keep patting")
  }
}
fun main() {
  var cat = object : Pet { 
    override var category:String = "small"
    override fun feeding() {
      println("Feed tuna can!")
    }
  }
  println("Cat category : ${cat.category}")
  cat.feeding()
  cat.patting()
}

//companion
class Person {
  companion object {
    fun callMe() = println("I'm called.")
  }
}
fun main() {
  Person.callMe()
}


//visibility mode
open class Base() {
  var a = 1
  private var b = 2
  protected open val c = 3
  internal val d = 4
  protected fun e() {
    println("Function e()")
  }
  fun f():Int {
    return b;
  }
  fun g():Int {
    return c;
  }
}
class Derived: Base() {
// a, c, d, and e() of the Base class are visible
// b is not visible
  override val c = 9 // c is protected
}
fun main() {
  val base = Base()
  println("${base.a}")
  println("${base.f()}") //private 접근은 함수를 통해서 한다
  println("${base.g()}")
  println("${base.d}")
  val derived = Derived()
  println("${derived.a}")
  println("${derived.f()}")
  println("${derived.g()}")
  println("${derived.d}")
}