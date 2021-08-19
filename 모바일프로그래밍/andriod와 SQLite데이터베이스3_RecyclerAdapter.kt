package com.seo.sayHello

import android.view.LayoutInflater
import java.text.SimpleDateFormat
import android.view.View
import android.view.ViewGroup
import androidx.recyclerview.widget.RecyclerView
import kotlinx.android.synthetic.main.item_recycler.view.*


class RecyclerAdapter: RecyclerView.Adapter<Holder>() {
    var listData = mutableListOf<Memo>()
    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): Holder {
        val view = LayoutInflater.from(parent.context).inflate(R.layout.item_recycler,parent,false)

        return Holder(view)
    }

    override fun onBindViewHolder(holder: Holder, position: Int) {
        val memo = listData.get(position)
        holder.setMemo(memo)
    }

    override fun getItemCount(): Int {
        return listData.size
    }
}

class Holder(itemView:View) : RecyclerView.ViewHolder(itemView){
    fun setMemo(memo:Memo){
        itemView.textNo.text = "${memo.no}"
        itemView.textContent.text = "${memo.content}"
        val sdf = SimpleDateFormat("yyyy/MM/dd hh:mm")
        val datatime = sdf.format(memo.datetime)
        itemView.textDatetime.text = "$datatime"
    }
}