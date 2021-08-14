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
import kotlin.concurrent.thread

class MainActivity : AppCompatActivity() {

    val binding by lazy { ActivityMainBinding.inflate(layoutInflater) }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(binding.root)

        with(binding) {
            // <-메인스레드
            showProgress(true)
            thread(start = true) { //-> 서브스레드
                Thread.sleep(5000)
                runOnUiThread {
                    showProgress(false)
                    progressLayout.visibility = View.GONE
                }
            }//<-서브스레드
        }//<-메인스레드
    }
    fun showProgress(show: Boolean){
        binding.progressLayout.visibility = if(show) View.VISIBLE else View.GONE
    }
}