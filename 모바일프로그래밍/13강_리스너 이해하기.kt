package com.seo.sayHello

import android.annotation.SuppressLint
import android.app.Activity
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.View
import kotlinx.android.synthetic.main.activity_main.*
import com.seo.sayHello.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        var listener = object : View.OnClickListener {
            override fun onClick(p0: View?) {
                Log.d("리스너", "클릭되었습니다")
            }
        }
        button.setOnClickListener(listener)

        //onClick(p0: View?)와 같이 함수가 1개인 경우는 아래와 같이 생략 가능
        //button.setOnClickListener { Log.d("리스너","클릭되었습니다") }
    }
}