package com.seo.sayHello

import android.annotation.SuppressLint
import android.app.Activity
import android.content.Context
import android.content.Intent
import android.icu.text.CaseMap
import android.icu.text.SimpleDateFormat
import android.os.Build
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.*
import androidx.annotation.RequiresApi
import androidx.core.widget.addTextChangedListener
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import kotlinx.android.synthetic.main.activity_main.*
import com.seo.sayHello.databinding.ActivityMainBinding
import java.io.*
import java.lang.StringBuilder
import kotlin.concurrent.thread

class MainActivity : AppCompatActivity() {

    companion object{
        const val KEY_FIRST_OPEN = "key_first_open"
    }

    val binding by lazy{ ActivityMainBinding.inflate(layoutInflater)}

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(binding.root)

        val shared = getSharedPreferences("파일명", Context.MODE_PRIVATE)

        val first_open = shared.getString(KEY_FIRST_OPEN,"처음")

        if(first_open!="처음"){
           binding.hello.visibility = View.GONE
        }

        val editor = shared.edit() //수정을 위한 에디터를 꺼낸다
        editor.putString(KEY_FIRST_OPEN,"두번째")
        editor.commit()
    }
}
