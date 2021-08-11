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

        functionName()
        functionParam("값", 153)
        var pi = getPi()
        Log.d("함수", "pi=${pi}")
    }

    //기본함수
    fun functionName() {}

    //입력값이 있는 함수
    fun functionParam(param1: String, param2: Int) {
        Log.d("함수", "param1 = ${param1}, param2=${param2}")
    }

    //출력값이 있는 함수
    fun getPi(): Double {
        return 3.141592
    }
    //함수를 사용하는 용도-> 코드를 분류하기 위해
}
