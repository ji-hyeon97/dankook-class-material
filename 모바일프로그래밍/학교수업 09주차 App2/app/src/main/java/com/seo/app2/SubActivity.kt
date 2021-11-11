package com.seo.app2

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.Button
import android.widget.TextView

class SubActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_sub)

        val intentSub = intent

        val num1R = intentSub.getIntExtra("num1Extra",0)
        val num2R = intentSub.getIntExtra("num2Extra",0)

        Log.d("DKMobile","onCreate()")
        Log.d("DKMobile",num1R.toString()+", "+num2R.toString())

        val resultTxt = findViewById<TextView>(R.id.resultTxt)
        resultTxt.text = num1R.toString() +"+"+num2R.toString()+"="+((num1R+num2R).toString())

        val returnBtn = findViewById<Button>(R.id.returnBtn)
        returnBtn.setOnClickListener {
            Log.d("DKMobile","BACK button pressed.")
            finish()
        }

    }
}