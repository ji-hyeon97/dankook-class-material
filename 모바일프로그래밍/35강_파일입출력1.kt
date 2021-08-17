package com.seo.sayHello

import android.annotation.SuppressLint
import android.app.Activity
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


    val binding by lazy{ ActivityMainBinding.inflate(layoutInflater)}

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(binding.root)
        with(binding) {
            val directory_name = "memo"
            val filename = "memo01.txt"
            btnSave.setOnClickListener {
                val content = textWrite.text.toString()
                writeTextField(directory_name, filename, content)
            }
            val path = directory_name + "/" +filename
            val writtenContent = readTextFile(path)
            textRead.text = writtenContent
        }
    }

    fun readTextFile(path:String):String{
        val fullpath = File(filesDir.path + "/" +path)
        if(!fullpath.exists()) return ""

        val reader = FileReader(fullpath)
        val buffer = BufferedReader(reader)

        val result = StringBuilder() //stringBuffer()
        var temp:String?=""

        while(true){
            temp = buffer.readLine()
            if(temp==null) break
            result.append(temp).append("\n")
        }
        buffer.close()
        reader.close()
        return result.toString()
    }

    fun writeTextField(directory:String, filename:String,content:String){
        //앱 기본 경로 / files / memo
        val dir = File(filesDir.path +"/" + directory)
        if(!dir.exists()) dir.mkdirs()

        val fullpath = dir.path + "/" + filename
        val writer = FileWriter(fullpath)
        val buffer = BufferedWriter(writer)
        buffer.write(content)
        buffer.close()
        writer.close()
    }
}
