package com.seo.room

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.room.Room
import com.seo.room.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    val binding by lazy{ ActivityMainBinding.inflate(layoutInflater)}
    lateinit var helper:RoomHelper
    lateinit var memoAdapter: RecyclerAdapter
    val memoList = mutableListOf<RoomMemo>()
    lateinit var memoDAO:RoomMemoDAO

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(binding.root)

        //allowMainThreadQueries() : Room 에서 쿼리가 가능하게 만듬
        helper = Room.databaseBuilder(this,RoomHelper::class.java,"room_db").allowMainThreadQueries().build()
        memoDAO = helper.roomMemoDao()
        memoAdapter = RecyclerAdapter(memoList)
        refreshAdapter()

        with(binding){
            recyclerMemo.adapter = memoAdapter
            recyclerMemo.layoutManager = LinearLayoutManager(this@MainActivity)

            buttonSave.setOnClickListener{
                val content = editMemo.text.toString()
                if(content.isNotEmpty()){
                    val datetime = System.currentTimeMillis()
                    val memo = RoomMemo(content,datetime)
                    memoDAO.insert(memo)
                    refreshAdapter()

                }
            }
        }
    }

    fun refreshAdapter(){
        memoList.clear()
        memoList.addAll(memoDAO.getAll())
        memoAdapter.notifyDataSetChanged()
    }
}