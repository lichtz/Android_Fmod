package com.zero.licht.androidfmod;

/**
 * Created by licht on 2018/3/11.
 */

public class EffectUtils {
    public static final  int TYPE_NORMAL =0;
    public static final  int TYPE_LUOLI = 1;
    public static final  int  TYPE_DASHU =2;
    /**
     * 音效处理
     * @param path
     * @param type
     */
    public  native  static  void fix(String path,int type);
    static {
        System.loadLibrary("w-voice");
    }
}
