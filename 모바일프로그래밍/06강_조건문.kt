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

        var first = 300
        var second = 500
        var third = 270

        //비교연산자
        var result1 = first < 500
        Log.d("compare", "첫번째 결과는 ${result1}")//true,false 반환
        var result2 = second < 500
        Log.d("compare", "두번째 결과는 ${result2}")

        //논리연산자
        var logic1 = result1 && result2
        Log.d("compare", "논리연산자 && 결과는 ${logic1}")

        var logic2 = result1 || result2
        Log.d("compare", "논리연산자 || 결과는 ${logic2}")

        //부정연산자
        var logic3 = !result1
        Log.d("compare", "논리연산자 ! 결과는 ${logic3}")

        //if
        var month = 7
        if (month > 9) {
            Log.d("if", "가을")
        } else if (month < 6 && month < 9) {
            Log.d("if", "여름")
        } else {
            Log.d("if", "겨울 or 봄")
        }

        //코틀린 when => 대부분의 언어에서는 switch(if문의 확장) 가독성 좋음
        when (month) {
            9 -> {
                Log.d("when", "9월입니다.")
            }
            7 -> {
                Log.d("when", "7월입니다.")
            }
            6, 7, 8 -> { //in 6..8
                Log.d("when", "여름입니다.")
            }
            in 6..8 -> {
                Log.d("when", "여름입니다.")
            }
            else -> {
                Log.d("when", "연습잘했다!")
            }
        }
    }
}