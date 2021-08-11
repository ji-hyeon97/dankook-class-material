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

        //for ->until(마지막인덱스제외), downto(내림차순), step(건너뛰기)
        for(index in 1..10) {
            Log.d("반복문","index=${index}")
        }

        var intArray = intArrayOf(0,1,2,3,4,5,6,7,8)
        for (value in intArray){
            Log.d("반복문","value=${value}")
        }

        // while 문
        var out=0
        do{
            Log.d("while","현재 out 카운트:${out}")
            out +=1
        }while(out<3)

        //control loop ->break, continue
        for(index in 0..10){
            if(index>5) break;
            Log.d("포","현재숫자 :${index}")
        }
    }
}