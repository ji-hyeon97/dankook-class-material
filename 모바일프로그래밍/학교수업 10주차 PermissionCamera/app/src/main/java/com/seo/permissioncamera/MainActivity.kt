package com.seo.permissioncamera

import android.Manifest
import android.content.pm.PackageManager
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.Button
import android.widget.TextView
import androidx.core.app.ActivityCompat
import androidx.core.content.ContextCompat

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val btnCamera = findViewById<Button>(R.id.button)
        btnCamera.setOnClickListener {
            Log.d("DKMobile", "CAMERA button pressed.")
            val cameraPermission =
                ContextCompat.checkSelfPermission(this, Manifest.permission.CAMERA)
            if (cameraPermission == PackageManager.PERMISSION_GRANTED) {
                Log.d("DKMOBILE", "CAMERA permission already granted")
                var permitTxt = findViewById<TextView>(R.id.textView2)
                permitTxt.text = "CAMERA permission granted now"
            } else {
                ActivityCompat.requestPermissions(this, arrayOf(Manifest.permission.CAMERA), 99)
                var permitTxt = findViewById<TextView>(R.id.textView2)
                permitTxt.text = "CAMERA permission not granted"
            }
        }
    }

    override fun onRequestPermissionsResult(
        requestCode: Int, permissions: Array<out String>,
        grantResults: IntArray
    ) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults)
        var permitTxt = findViewById<TextView>(R.id.textView2)

        when (requestCode) {
            99 -> {
                if (grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                    Log.d("DKMOBILE", "CAMERA permission granted now")
                    permitTxt.text = "CAMERA permission granted now"
                } else {
                    Log.d("DKMOBILE", "CAMERA permission not granted")
                    permitTxt.text = "CAMERA permission not granted"
                }
            }
        }
    }
}
