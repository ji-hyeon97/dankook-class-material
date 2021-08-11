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

        var variable = 157

        //배열
        //int -> intArray
        var intArr:IntArray = IntArray(10)
        intArr[0] = 10
        intArr[1] = 20
        intArr[2] = 30
        intArr[3] = 40
        intArr[9] = 100
        //intArr[10] = 110 배열의 크기에 맞지 않음
        Log.d("array","9번인덱스 값: ${intArr[9]}")

        var weekArray = CharArray(7)
        weekArray[0] = '월'
        // ...
        weekArray[6] = '일'

        //컬랙션  Generic(제네릭) <>값을 넣는것-> 특정 타입
        var mutableList = mutableListOf<Int>()
        mutableList.add(5)
        mutableList.add(10)
        mutableList.add(75)
        mutableList.add(36)
        mutableList.add(66)
        Log.d("컬랙션","3번 인덱스의 값: ${mutableList.get(3) }")
        Log.d("컬랙션","3번 인덱스의 값: ${mutableList[3] }")

        //맵 (키, 밸류) => 변수명, 값
        var mutableMap = mutableMapOf<String,String>()
        mutableMap.put("변수1","값1")
        mutableMap.put("변수2","값2")
        Log.d("컬랙션","맵 변수1의 값은 : ${mutableMap.get("변수1")}")
    }
}