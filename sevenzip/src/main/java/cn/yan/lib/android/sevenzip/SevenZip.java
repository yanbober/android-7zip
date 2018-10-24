package cn.yan.lib.android.sevenzip;

public class SevenZip {
    static {
        System.loadLibrary("native-lib");
    }

    public static native void zip(String srcZipFile, String dstZipFile, OnStateListener listener);

    public static native void unzip(String srcZipFile, String dstZipDir, OnStateListener listener);

    public interface OnStateListener {
        void onStart(String src);
        void onChange(String src, float progress);
        void onError(String src, int errorCode);
        void onSuccess(String src);
    }
}
