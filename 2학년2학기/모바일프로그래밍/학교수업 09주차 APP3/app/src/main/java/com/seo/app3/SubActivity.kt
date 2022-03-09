package com.seo.app3

import android.app.Activity
import android.content.Intent
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

        Log.d("DKMobile","SubActivity onCreate()")
        Log.d("DKMobile","getExtra "+num1R.toString()+", "+num2R.toString()+" result="+((num1R+num2R).toString()))

        val resultTxt = findViewById<TextView>(R.id.resultTxt)
        resultTxt.text = num1R.toString() +"+"+num2R.toString()+"="+((num1R+num2R).toString())

        Log.d("DKMobile","SubActivity onStart()")
        Log.d("DKMobile","SubActivity onResume()")
        Log.d("DKMobile","SubActivity onStop()")

        val returnBtn = findViewById<Button>(R.id.returnBtn)
        returnBtn.setOnClickListener {
            Log.d("DKMobile","Return button pressed.")
            val outIntent = Intent(this, MainActivity::class.java)
            outIntent.putExtra("result" ,num1R+num2R)
            setResult(Activity.RESULT_OK,outIntent)
            Log.d("DKMobile","SubActivity onPause()")
            finish()
        }
    }
}
