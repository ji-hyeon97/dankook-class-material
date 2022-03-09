package com.seo.database

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import androidx.room.Room

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val db = Room.databaseBuilder(applicationContext,UserDB::class. java, "userdb").allowMainThreadQueries().build()
        val users = db.userDao().getAll()

        if(users.isNotEmpty()) {
            Log.d("USERDB","something in db")
        }
        else {
            Log.d("USERDB","Nothing in db")
        }

        val userd1 = User(1, "jihyeon", "Seo")
        val userd2 = User(2, "jihyn", "S")
        db.userDao().insertAll(userd1)
        db.userDao().insertAll(userd2)

        var readuser = db.userDao().findByName("j%", "%")
        if (readuser != null) {
            Log.d("USERDB", readuser.firstName+" "+readuser.lastName)
        }
        else {
        }
    }
}