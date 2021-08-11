package com.seo.sayHello

import android.annotation.SuppressLint
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import kotlinx.android.synthetic.main.activity_main.*
import com.seo.sayHello.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        //클래스사용
        //1.초기화 -> companion object
        Log.d("태그","메시지")

        var parent = Parent()
        parent.showHouse()

        var child = Child()
        child.showMoney()
        child.showHouse()

        var son = Son()
        var result1 = son.getNumber("을")
        Log.d("클래스","오버로드값=${result1}")

    }
}

//클래스:변수와 함수의 모음
class Log{
    companion object{
        fun d(tag:String, msg:String){
            print("{$tag} : {$msg}")
        }
    }
}

//상속을 사용하는 이유: 기존의 작성된 코드 재활용, 계층구조
open class Parent{
    var money = 5000000000
    open var house = "강남 역삼동 빌딩"
    open fun showHouse(){
        Log.d("클래스","parent house ${house}")
    }
}

//override: 부모의 변수나 메소드의 이름을 재정의 할 경우
class Child : Parent(){
    override var house = "강남 역삼동 오피스텔"
    fun showMoney(){
        Log.d("클래스","money=${money}")
    }
    override fun showHouse(){
        Log.d("클래스","child house=${house}")
    }
}

//overload: 동일한 이름의 함수를 만듬(매개변수로 차이를 둔다)
class Son{
    fun getNumber():Int{
        return 1
    }
    fun getNumber(param:String):Int{
        return 2
    }
}