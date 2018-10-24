package cn.yan.android.sevenzip;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import cn.yan.lib.android.sevenzip.SevenZip;

public class DemoActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_demo);

        // Example of a call to a native method
        final TextView tv = (TextView) findViewById(R.id.sample_text);
        SevenZip.zip("xxxxxx/xxxxx", "xxxx/dddddf", new SevenZip.OnStateListener() {
            @Override
            public void onStart(String src) {
                tv.setText(tv.getText() + "\n" + "onStarted");
            }

            @Override
            public void onChange(String src, float progress) {
                tv.setText(tv.getText() + "\n" + "onChange");
            }

            @Override
            public void onError(String src, int errorCode) {
                tv.setText(tv.getText() + "\n" + "onError "+errorCode);
            }

            @Override
            public void onSuccess(String src) {
                tv.setText(tv.getText() + "\n" + "onSuccess");
            }
        });
    }
}
