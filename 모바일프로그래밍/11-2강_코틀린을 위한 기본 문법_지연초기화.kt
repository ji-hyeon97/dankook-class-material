package com.seo.sayHello

import android.annotation.SuppressLint
import android.app.Activity
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import kotlinx.android.synthetic.main.activity_main.*
import com.seo.sayHello.databinding.ActivityMainBinding

//선행조건
//1. class
//2. null safety
class MainActivity : AppCompatActivity() {

    //지연초기화 : 메모리가 낭비되는 것을 막음(클래스)
    //lateinit
    lateinit var person:Person //기본형 : Int, Long, Float, Double은 사용 못함
    //lazy ->값을 바꾸는 경우가 없는 경우
    //val 변수명 by lazy{변수에 들어갈 클래스생성자}
    val age by lazy { Person() }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        person = Person()

    }
}
class Person{
    var name="서지현"
    var age=25
    var adress="창원"
    var tel="01047889477"
}
