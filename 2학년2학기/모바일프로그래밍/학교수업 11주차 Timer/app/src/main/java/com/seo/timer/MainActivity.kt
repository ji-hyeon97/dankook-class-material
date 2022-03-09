package com.seo.timer

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.Handler
import android.os.Looper
import android.os.Message
import android.widget.Button
import android.widget.TextView
import kotlin.concurrent.thread

var started = false
var total = 0

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val timerText = findViewById<TextView>(R.id.TextTimer)
        val buttonStart = findViewById<Button>(R.id.buttonStart)
        val buttonStop = findViewById<Button>(R.id.buttonStop)

        val myHandler = object : Handler(Looper.getMainLooper()) {
            override fun handleMessage(msg: Message) {
                super.handleMessage(msg)

                val minute = String.format("%02d",total/60)
                val second = String.format("%02d",total%60)

                timerText.text = "$minute:$second"

            }
        }

        buttonStart.setOnClickListener {
            // Do what?
            started = true
            thread(start = true){
                while(started){
                    Thread.sleep(1000)
                    if(started){
                        total = total + 1
                        myHandler?.sendEmptyMessage(0)
                    }
                }
            }
        }
        buttonStop.setOnClickListener {
            // Do what?
            if(started){
                started = false
                total = 0

            }
        }

    }
}
