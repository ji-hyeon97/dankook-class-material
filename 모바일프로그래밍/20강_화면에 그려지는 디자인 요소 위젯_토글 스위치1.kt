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
        setContentView(binding.root)

        with(binding) {
            toggleButton.setOnCheckedChangeListener { buttonView, isChecked ->
                if (isChecked) textToggle.text = "On"
                else textToggle.text = "Off"
                //textToggle.text = if(isChecked) "On" else "off"
            }
            switchButton.setOnCheckedChangeListener { buttonView, isChecked ->
                textSwitch.text = if (isChecked) "On" else "off"
            }
        }
    }
}
