package com.seo.sayHello

import android.annotation.SuppressLint
import android.app.Activity
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.widget.CompoundButton
import androidx.core.widget.addTextChangedListener
import kotlinx.android.synthetic.main.activity_main.*
import com.seo.sayHello.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    val binding by lazy { ActivityMainBinding.inflate(layoutInflater) }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        //setContentView(R.layout.activity_main)
        setContentView(binding.root)
        /*

        with(binding) {
            checkApple.setOnCheckedChangeListener { buttonView, isChecked ->
                if (isChecked) Log.d("체크박스", "사과가 선택되었습니다.")
                else Log.d("체크박스", "사과가 선택 해제 되었습니다.")
            }
        }

        with(binding) {
            checkBanana.setOnCheckedChangeListener { buttonView, isChecked ->
                if (isChecked) Log.d("체크박스", "바나나가 선택되었습니다.")
                else Log.d("체크박스", "바나나가 선택 해제 되었습니다.")
            }
        }

        with(binding) {
            checkOrange.setOnCheckedChangeListener { buttonView, isChecked ->
                if (isChecked) Log.d("체크박스", "오렌지가 선택되었습니다.")
                else Log.d("체크박스", "오렌지가 선택 해제 되었습니다.")
            }
        }
        */
        with(binding) {
            checkApple.setOnCheckedChangeListener(checkboxListener)
            checkBanana.setOnCheckedChangeListener(checkboxListener)
            checkOrange.setOnCheckedChangeListener(checkboxListener)
        }
    }

    val checkboxListener = CompoundButton.OnCheckedChangeListener { checkBox, isChecked ->
        when (checkBox.id) {
            R.id.checkApple -> {
                if (isChecked) Log.d("체크박스", "사과가 선택되었습니다.")
                else Log.d("체크박스", "사과가 선택 해제 되었습니다.")
            }
            R.id.checkBanana -> {
                if (isChecked) Log.d("체크박스", "바나나가 선택되었습니다.")
                else Log.d("체크박스", "바나나가 선택 해제 되었습니다.")
            }
            R.id.checkOrange -> {
                if (isChecked) Log.d("체크박스", "오렌지가 선택되었습니다.")
                else Log.d("체크박스", "오렌지가 선택 해제 되었습니다.")
            }
        }
    }
}

