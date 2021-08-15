package com.seo.sayHello

import android.annotation.SuppressLint
import android.app.Activity
import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.widget.CompoundButton
import android.widget.SeekBar
import android.widget.Toast
import androidx.core.widget.addTextChangedListener
import kotlinx.android.synthetic.main.activity_main.*
import com.seo.sayHello.databinding.ActivityMainBinding
import kotlin.concurrent.thread

class MainActivity : AppCompatActivity() {

    val binding by lazy{ ActivityMainBinding.inflate(layoutInflater)}

    override fun onCreate(savedInstanceState: Bundle?) { //entry point(시작점)
        super.onCreate(savedInstanceState)
        setContentView(binding.root)

        binding.btnStart.setOnClickListener {
            val intent = Intent(this, SubActivity::class.java) //Intent 오류시 alt + enter
            intent.putExtra("from1","Hello Bundle")
            intent.putExtra("from2",2021)
            startActivityForResult(intent,99)


        }
    }

    //ctrl + o로 호출하기기
   override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        super.onActivityResult(requestCode, resultCode, data)

        if (resultCode == Activity.RESULT_OK) {
            when (requestCode) {
                99 -> {
                    data?.getStringExtra("returnValue")?.let{message ->
                        Toast.makeText(this,message,Toast.LENGTH_SHORT).show()
                    }
                }
            }
        }
    }
}
