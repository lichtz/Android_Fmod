package com.zero.licht.androidfmod;

import android.app.Activity;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

import org.fmod.FMOD;

import static android.content.ContentValues.TAG;

public class EffectActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_effect);
        FMOD.init(this);
    }

    static
    {
    	/*
    	 * To simplify our examples we try to load all possible FMOD
    	 * libraries, the Android.mk will copy in the correct ones
    	 * for each example. For real products you would just load
    	 * 'fmod' and if you use the FMOD Studio tool you would also
    	 * load 'fmodstudio'.
    	 */


        // Try logging libraries...
        try { System.loadLibrary("fmodL");
        }
        catch (UnsatisfiedLinkError e) { }
        // Try release libraries...
        try { System.loadLibrary("fmod");
        }
        catch (UnsatisfiedLinkError e) { }

//    	System.loadLibrary("stlport_shared");
        System.loadLibrary("w-voice");
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        FMOD.close();
    }

    public void mFix(View view) {
//        file:///android_asset/
        String path = "file:///android_asset/wave.mp3";
        EffectUtils.fix(path,EffectUtils.TYPE_NORMAL);
    }

    public void mL(View view) {
        String path = "file:///android_asset/wave.mp3";
        EffectUtils.fix(path,EffectUtils.TYPE_LUOLI);
    }

    public void ds(View view) {
        String path = "file:///android_asset/wave.mp3";
        EffectUtils.fix(path,EffectUtils.TYPE_DASHU);
    }

    public void fun(View view) {
        String path = "file:///android_asset/wave.mp3";
        EffectUtils.fix(path,3);
    }

    public void ECHO(View view) {
        String path = "file:///android_asset/wave.mp3";
        EffectUtils.fix(path,4);
    }

    public void sc(View view) {
        String path = "file:///android_asset/wave.mp3";
        EffectUtils.fix(path,5);
    }
}
