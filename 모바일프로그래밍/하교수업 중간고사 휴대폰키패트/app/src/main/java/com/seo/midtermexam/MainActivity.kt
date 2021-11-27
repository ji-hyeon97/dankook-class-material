package com.seo.midtermexam

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.TextView

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        var button1 = findViewById<Button>(R.id.button1)
        var button2 = findViewById<Button>(R.id.button2)
        var button3 = findViewById<Button>(R.id.button3)
        var button4 = findViewById<Button>(R.id.button4)
        var button5 = findViewById<Button>(R.id.button5)
        var button6 = findViewById<Button>(R.id.button6)
        var button7 = findViewById<Button>(R.id.button7)
        var button8 = findViewById<Button>(R.id.button8)
        var button9 = findViewById<Button>(R.id.button9)
        var button10 = findViewById<Button>(R.id.button10)
        var button11 = findViewById<Button>(R.id.button11)
        var button12= findViewById<Button>(R.id.button12)
        var TextSay = findViewById<TextView>(R.id.TextSay)

        var mix = StringBuilder()

        button1 .setOnClickListener {
            mix.append(1)
            TextSay.setText(mix)
        }
        button2 .setOnClickListener {
            mix.append(2)
            TextSay.setText(mix)
        }
        button3 .setOnClickListener {
            mix.append(3)
            TextSay.setText(mix)
        }
        button4 .setOnClickListener {
            mix.append(4)
            TextSay.setText(mix)
        }
        button5 .setOnClickListener {
            mix.append(5)
            TextSay.setText(mix)
        }
        button6 .setOnClickListener {
            mix.append(6)
            TextSay.setText(mix)
        }
        button7 .setOnClickListener {
            mix.append(7)
            TextSay.setText(mix)
        }
        button8 .setOnClickListener {
            mix.append(8)
            TextSay.setText(mix)
        }
        button9 .setOnClickListener {
            mix.append(9)
            TextSay.setText(mix)
        }
        button10 .setOnClickListener {
            mix.append('#')
            TextSay.setText(mix)
        }
        button11.setOnClickListener {
            mix.append(0)
            TextSay.setText(mix)
        }
        button12 .setOnClickListener {
            mix.append('*')
            TextSay.setText(mix)
        }
    }
}