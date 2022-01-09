package com.seo.afinal

import android.content.Context
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.Handler
import android.os.Looper
import android.os.Message
import android.util.Log
import android.widget.Button
import android.widget.TextView

//class MyHandler : Handler(Looper.getMainLooper()) {
//        override fun handleMessage(msg: Message) {
//            super.handleMessage(msg)
////            val helloText = findViewById<TextView>(R.id.helloText)
//
//            Log.d("BkgThread", "Main thread")
////            if(msg.what == 1) {
////                helloText.setText("$msg.arg1")
////            }
//        }
//}

var started = false
var paused = false
var lastCount = 0

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val timerText = findViewById<TextView>(R.id.timerText)
        val buttonStart = findViewById<Button>(R.id.buttonStart)
        val buttonStop = findViewById<Button>(R.id.buttonStop)
        val buttonPause = findViewById<Button>(R.id.buttonPause)

        val sharedPref = getSharedPreferences("kr.ac.dankook.example.SHARED_PREF", Context.MODE_PRIVATE);

        lastCount = sharedPref.getInt("lastCount", 0)
        Log.d("BkgThread", "Read lastCount = $lastCount")

        val min = String.format("%02d", lastCount/60)
        val sec = String.format("%02d", lastCount%60)
        timerText.text = "$min:$sec"

        val myHandler = object : Handler(Looper.getMainLooper()) {
            override fun handleMessage(msg: Message) {
                super.handleMessage(msg)

                Log.d("BkgThread", "Main thread")
                if(msg.what == 1) {
//                    count = msg.arg1
                    val min = String.format("%02d", msg.arg1/60)
                    val sec = String.format("%02d", msg.arg1%60)
                    timerText.text = "$min:$sec"
                }
            }
        }

        Thread {
            while(true) {
                Thread.sleep(1000)
                if(started) {
                    if(paused == false) {
                        Log.d("BkgThread", "In background thread : $lastCount")
                        var msg = myHandler.obtainMessage()
                        msg.what = 1
                        msg.arg1 = lastCount
                        myHandler.sendMessage(msg)
                        lastCount += 1
//                        lastCount = i
                    }
//                } else {
//                    lastCount=0
                }
            }
        }.start()



        buttonStart.setOnClickListener {
            started = true
        }

        buttonPause.setOnClickListener {
            if(started) paused = paused != true

            val editor = sharedPref.edit()
            editor.putInt("lastCount", lastCount)
            editor.apply()
            Log.d("BkgThread", "Save lastCount = $lastCount")
        }

        buttonStop.setOnClickListener {
            started = false
            paused  = false
            lastCount = 0
        }
    }
}