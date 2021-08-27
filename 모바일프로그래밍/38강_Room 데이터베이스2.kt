package com.seo.room

import android.icu.text.SimpleDateFormat
import android.os.Build
import android.view.LayoutInflater
import android.view.ViewGroup
import androidx.annotation.RequiresApi
import androidx.recyclerview.widget.RecyclerView
import com.seo.room.databinding.ItemRecyclerBinding

class RecyclerAdapter(val roomMemoList:List<RoomMemo>) : RecyclerView.Adapter<RecyclerAdapter.Holder>() {

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): Holder {
        val binding = ItemRecyclerBinding.inflate(LayoutInflater.from(parent.context),parent,false)
        return Holder(binding)

    }

    @RequiresApi(Build.VERSION_CODES.N)
    override fun onBindViewHolder(holder: Holder, position: Int) {
        holder.setMemo(roomMemoList.get(position))


    }

    override fun getItemCount() = roomMemoList.size

    class Holder(val binding: ItemRecyclerBinding) : RecyclerView.ViewHolder(binding.root) {
        @RequiresApi(Build.VERSION_CODES.N)
        fun setMemo(roomMemo: RoomMemo){
            with(binding){
                textNo.text = "${roomMemo.no}"
                textContent.text = roomMemo.content

                val sdf = SimpleDateFormat("yyyy/MM/dd hh:mm")
                textDatetime.text = sdf.format(roomMemo.datetime)


            }

        }

    }
}