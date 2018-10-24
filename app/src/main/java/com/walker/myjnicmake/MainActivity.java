package com.walker.myjnicmake;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.walker.myjnicmake.jni.NativeFun;

public class MainActivity extends AppCompatActivity {

    private TextView mTvShow;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mTvShow = findViewById(R.id.tvShow);
    }

    public void onNativeFun(View v) {
        mTvShow.setText("");
        mTvShow.setText(NativeFun.stringFromJNI());
    }

    public void onImportLibs(View v) {
        mTvShow.setText("");
        String outPutJson = NativeFun.outputJsonCode("walker", "26", "man", "so");
        String parseJson = NativeFun.parseJsonCode(outPutJson);
        mTvShow.setText("生成的Json:\n" + outPutJson + "\n解析:" + parseJson);
    }
}
