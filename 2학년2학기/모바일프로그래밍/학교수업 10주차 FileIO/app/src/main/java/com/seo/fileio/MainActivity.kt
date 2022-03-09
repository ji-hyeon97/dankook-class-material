package com.seo.fileio

import android.content.Context
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.TextView

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        var content = findViewById<TextView>(R.id.textview)


        val fileName = "internal.txt"
        val fileBody = "File for testing"
        val buffo = applicationContext.openFileOutput(fileName, Context.MODE_PRIVATE)
        buffo.write(fileBody.toByteArray())
        content.text = fileBody
        buffo.close()

        val buffi = applicationContext.openFileInput(fileName)
        val buffr = buffi.bufferedReader()
        var txt = buffr.readLine()
        buffr.close()
        Log.d("FILETEST", "---> $txt")


    }
}