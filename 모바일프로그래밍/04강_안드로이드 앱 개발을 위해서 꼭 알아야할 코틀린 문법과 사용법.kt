package com.seo.sayHello

import android.annotation.SuppressLint
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import kotlinx.android.synthetic.main.activity_main.*
import com.seo.sayHello.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    val TAG = "MainActivity"

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        var myName = "서지현"
        Log.d(TAG, "내 이름은 : $myName")
        myName = "서지혁"
        Log.d(TAG, "내 이름은 : $myName")
        val myAge =19//값이 고정
        Log.d(TAG, "내 나이는 : $myAge")

        var myNumbers = "1,2,3,4,5,6"
        var thisWeekNumbers = "5,6,7,8,9,10"
        if(myNumbers == thisWeekNumbers){
            textLog.text = "당첨되었습니다."
        }
        else{
            textLog.text = "당첨되지 않았습니다."
        }

        for(index in 1..10){
            textLog.append("\n현재 숫자는 $index 입니다.")
            Log.d(TAG, "현재 숫자는 $index 입니다.")

        }
    }
}