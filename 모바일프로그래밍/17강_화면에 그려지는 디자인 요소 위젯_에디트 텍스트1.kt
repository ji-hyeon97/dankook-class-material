package com.seo.sayHello

import android.annotation.SuppressLint
import android.app.Activity
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import androidx.core.widget.addTextChangedListener
import kotlinx.android.synthetic.main.activity_main.*
import com.seo.sayHello.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    val binding by lazy {ActivityMainBinding.inflate(layoutInflater) }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        with(binding){
            editText.addTextChangedListener{ editable->
                Log.d("에딧텍스트","입력된값 :${editable.toString()}")
                //SPAN_EXCLUSIVE_EXCLUSIVE spans cannot have a zero length 디버깅 과정을 하긴 해야할 듯
                //에뮬레이터는 돌아가는데 로그값이 안나옴...

                textView.text = editable.toString()
            }
        }
    }
}