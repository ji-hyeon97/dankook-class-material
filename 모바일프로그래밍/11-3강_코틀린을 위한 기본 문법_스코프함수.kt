package com.seo.sayHello

import android.annotation.SuppressLint
import android.app.Activity
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import kotlinx.android.synthetic.main.activity_main.*
import com.seo.sayHello.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    val binding by lazy { ActivityMainBinding.inflate(layoutInflater) }
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        //스코프함수 with 사용 -> binding을 계속 작성하지 않아도 되어 깔끔하다
        with(binding) {
            btnsay.setOnClickListener {}
            textLog.text = "반가워~"
        }

        //binding.btnsay.setOnClickListener{}
        //binding.textLog.text = "반가워~"

        studyRun()
    }

    //스코프함수
    //run, let, apply, also
    //with
    //1. run
    fun studyRun() {
        val phones = mutableListOf("010-1234-5678", "010-9876-5432", "010-4788-9477")
        val list = mutableListOf(1, 2, 3, 4, 5, 6, 7, 8, 9)
        val names = mutableListOf("Scott", "Kelly", "Michael")

        //phones.add() 처럼 반복되는 phones 생략가능
        phones.run {
            add("010-2345-6789")
        }

//        스코프 함수를 작성하지 않으면 이와 같이 코드가 복잡해짐
        var seoulPeople = SeoulPeople()

        seoulPeople.persons.add(Person("Scott","010-1234-5678",11))
        seoulPeople.persons.add(Person("Scott","010-1234-5678",12))
        seoulPeople.persons.add(Person("Scott","010-1234-5678",13))

        //run, let: 변수를 정의했으나 다른 결과값을 받을려고 하는 경우
        //apply, also: 순수하게 변수에 반영된 값을 구함
        val resultRun = seoulPeople.persons.run {
            add(Person("Scott","010-1234-5678",14))
            add(Person("Scott","010-1234-5678",15))
            add(Person("Scott","010-1234-5678",16))
            size
        }
        Log.d("스코프함수","resultRun: ${resultRun}")

        //스코프 안에서 예약어를 붙혀서 쓰고 싶을때: seoulPeople.persons -> persons
        val resultLet = seoulPeople.persons.let{ persons ->
            persons.add(Person("Scott","010-1234-5678",17))
            persons.add(Person("Scott","010-1234-5678",18))
            persons.add(Person("Scott","010-1234-5678",19))
            10
        }
        Log.d("스코프함수","resultLet: ${resultLet}")

        val resultApply = seoulPeople.persons.apply{
            add(Person("Scott","010-1234-5678",20))
            add(Person("Scott","010-1234-5678",21))
            add(Person("Scott","010-1234-5678",22))
        }
        Log.d("스코프함수","resultApply: ${resultApply}")

        val resultAlso = seoulPeople.persons.also{ persons ->
            persons.add(Person("Scott","010-1234-5678",23))
            persons.add(Person("Scott","010-1234-5678",24))
            persons.add(Person("Scott","010-1234-5678",25))
            12
        }
        Log.d("스코프함수","resultAlso: ${resultAlso}")//변수의값 그대로 반환
    }
}

class SeoulPeople{
    var persons = mutableListOf<Person>()
    init{
        persons.add(Person("Scott","010-1234-5678",26))
        persons.add(Person("Kelly","010-1234-5678",27))
        persons.add(Person("Michael","010-1234-5678",28))
    }
}

data class Person(
    var name:String = "",
    var phone:String = "",
    var age:Int = 21
)
