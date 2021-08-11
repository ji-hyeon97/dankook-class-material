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

        var variable:String = "서지현"

        //코틀린의 기본타입
        //실수형
        var doubleValue:Double = 35.6
        var floatValue:Float = 135.7f
        //정수형
        var intValue:Int = 13245
        var longValue:Long = 212465789465
        var shortValue:Short = 123
        var byteValue:Byte = 127
        //문자형
        var charValue:Char = 'a'
        var stringValue:String = "문자열의 길이에 상관없이 입력"
        //불린형
        var boolValue:Boolean = true

        //var 값의 변경 가능
        //val 값의 변경 불가능


    }
}