package com.seo.sayHello

import android.annotation.SuppressLint
import android.app.Activity
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import kotlinx.android.synthetic.main.activity_main.*
import com.seo.sayHello.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        var myName: String = "메시"
        Log.d("Null test","문자열의 길이는=${myName.length}")

        //1. nullable
        var number: Int? = null
        Log.d("Null test","nullable=${number}")
        var newVariable:Activity? = null


        //null pointer exception
        //2. safe call
        var result1 = number?.plus(37)
        Log.d("Null test","nullable=${result1}")
        //result1 = null

        //3. Elvis Expression -> null일 경우 대체하는 디폴드 값 전체값으로 대체
        var result2 = number?.plus(37)?:51
        Log.d("Null test","nullable=${result2}")

        var number2:Int = 30
        var result = number2.plus(50)
        Log.d("Null test","nullable=${result}")
    }
}
