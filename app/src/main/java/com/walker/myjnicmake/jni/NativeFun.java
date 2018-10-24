package com.walker.myjnicmake.jni;
/**
 *@author Walker
 *
 *@e-mail feitianwumu@163.com
 *
 *@date on 2018/10/19
 *
 *@summary 直接从native源码调用方法
 *
 */
public class NativeFun {
    static {
        System.loadLibrary("native_hello");
    }

    public static native String stringFromJNI();

    public static native String outputJsonCode(String name, String age, String sex, String type);

    public static native String parseJsonCode(String json_str);
}
