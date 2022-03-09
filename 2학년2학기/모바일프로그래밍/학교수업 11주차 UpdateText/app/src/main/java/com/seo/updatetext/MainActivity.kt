package com.seo.updatetext

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.Handler
import android.os.Looper
import android.os.Message
import android.util.Log
import android.widget.TextView
import kotlin.concurrent.thread


class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val myHandler = object : Handler(Looper.getMainLooper()) {
            override fun handleMessage(msg: Message) {
                super.handleMessage(msg)
                val helloText = findViewById<TextView>(R.id.hellotxt)
                Log.d("BkgThread", "Main thread")
                if(msg.what == 1) {
                    helloText.setText("${msg.arg1}")
                }
            }
        }

        Thread {
            var i=0
            while(i<10) {
                i += 1
                Log.d("BkgThread", "In background thread : $i")
                var msg = myHandler.obtainMessage()
                msg.what = 1
                msg.arg1 = i
                myHandler.sendMessage(msg)
                Thread.sleep(1000)
            }
        }.start()
    }
}