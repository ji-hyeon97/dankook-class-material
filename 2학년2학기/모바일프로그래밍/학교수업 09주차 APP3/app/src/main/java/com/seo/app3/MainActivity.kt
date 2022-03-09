package com.seo.app3

import android.app.Activity
import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import androidx.activity.result.contract.ActivityResultContracts


class MainActivity : AppCompatActivity() {
    private val getResult =
        registerForActivityResult(
            ActivityResultContracts.StartActivityForResult()) { res->
            if(res. resultCode == Activity.RESULT_OK){
                Log.d("DKMobile","MainActivity onStart()")
                val value = res.data?.getIntExtra("result", 0)
                Log.d("DKMobile", "Received Result is "+value.toString())
                val mainResultView = findViewById<TextView>(R.id.mainResultView)
                mainResultView.text = "Result is "+value.toString()
                Log.d("DKMobile","MainActivity onResume()")
                Log.d("DKMobile","SubActivity onStop()")
                Log.d("DKMobile","SubActivity onDestory()")
                Log.d("DKMobile","MainActivity onPause()")
                Log.d("DKMobile","MainActivity onStop()")
                Log.d("DKMobile","MainActivity onDestory()")
            }
        }
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        Log.d("DKMobile","MainActivity onCreate()")
        Log.d("DKMobile","MainActivity onStart()")
        Log.d("DKMobile","MainActivity onResume()")


        val intentOpen = Intent(this, SubActivity::class.java)
        val openBtn = findViewById<Button>(R.id.openBtn)

        openBtn.setOnClickListener {
            Log.d("DKMobile","OPEN SUB button pressed")
            val num1w = findViewById<EditText>(R.id.num1)
            val num2w = findViewById<EditText>(R.id.num2)
            val num1 = num1w.text.toString().toInt()
            val num2 = num2w.text.toString().toInt()

            Log.d("DKMobile","PutExtra"+num1.toString()+", "+num2.toString())
            intentOpen.putExtra("num1Extra",num1)
            intentOpen.putExtra("num2Extra",num2)

            Log.d("DKMobile","MainActivity onPause()")

            //startActivity(intentOpen)
            getResult.launch(intentOpen)
        }
    }
}