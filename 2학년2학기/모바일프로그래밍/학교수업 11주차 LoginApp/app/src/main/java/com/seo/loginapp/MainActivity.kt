package com.seo.loginapp

import android.content.Context
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.Button
import android.widget.EditText

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val sharedPref = getSharedPreferences("com.seo.loginapp.SHARED_PREF_File", Context.MODE_PRIVATE)
        val editor = sharedPref.edit()

        val usernameInput = findViewById<EditText>(R.id.Username)
        val passwordInput = findViewById<EditText>(R.id.Password)
        val buttonInput = findViewById<Button>(R.id.button)

        val username: String = "unknown"
        val password: String = "****"
        val id = -1

        buttonInput.setOnClickListener {

            val username: String? = sharedPref.getString("username","unknown")
            val password: String? = sharedPref.getString("password","****")
            val id = sharedPref.getInt("id",-1)
            when(id) {
                -1 -> Log.d(
                    "login",
                    "there is no saved login info. wait user input username & password and click login button"
                )
            }

            editor.putString("username", usernameInput.text.toString())
            editor.putString("password", passwordInput .text.toString())
            editor.putInt("id", 1)

            editor.apply()

            Log.d("login","username : "+username.toString() +", password : "+ password.toString()  +", id : "+ id.toString())
        }
    }
}