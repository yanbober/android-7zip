#include <jni.h>
#include "lzmaSdkExecutor.h"
#include "androidNdkLogcat.h"

void callbackStart(JNIEnv* env, jobject listener, char* sourcePath) {
    jclass listenerClass = (*env)->GetObjectClass(env, listener);
    if (listenerClass == 0) {
        LOGE("Unable to find class!");
        return;
    }

    jmethodID start = (*env)->GetMethodID(env, listenerClass, "onStart", "(Ljava/lang/String;)V");
    if (start == NULL) {
        LOGE("Unable to find method!");
        return;
    }

    jstring jsourcePath = (*env)->NewStringUTF(env, sourcePath);
    (*env)->CallVoidMethod(env, listener, start, jsourcePath);
    (*env)->DeleteLocalRef(env, jsourcePath);
}

void callbackChange(JNIEnv* env, jobject listener, char* sourcePath, float process) {
    jclass listenerClass = (*env)->GetObjectClass(env, listener);
    if (listenerClass == 0) {
        LOGE("Unable to find class!");
        return;
    }

    jmethodID change = (*env)->GetMethodID(env, listenerClass, "onChange", "(Ljava/lang/String;F)V");
    if (change == NULL) {
        LOGE("Unable to find method!");
        return;
    }

    jstring jsourcePath = (*env)->NewStringUTF(env, sourcePath);
    (*env)->CallVoidMethod(env, listener, change, jsourcePath, 12);
    (*env)->DeleteLocalRef(env, jsourcePath);
}

void callbackError(JNIEnv* env, jobject listener, char* sourcePath, int errorCode) {
    jclass listenerClass = (*env)->GetObjectClass(env, listener);
    if (listenerClass == 0) {
        LOGE("Unable to find class!");
        return;
    }

    jmethodID error = (*env)->GetMethodID(env, listenerClass, "onError", "(Ljava/lang/String;I)V");
    if (error == NULL) {
        LOGE("Unable to find method!");
        return;
    }

    jstring jsourcePath = (*env)->NewStringUTF(env, sourcePath);
    (*env)->CallVoidMethod(env, listener, error, jsourcePath, errorCode);
    (*env)->DeleteLocalRef(env, jsourcePath);
}

void callbackFinish(JNIEnv* env, jobject listener, char* sourcePath) {
    jclass listenerClass = (*env)->GetObjectClass(env, listener);
    if (listenerClass == 0) {
        LOGE("Unable to find class!");
        return;
    }

    jmethodID finish = (*env)->GetMethodID(env, listenerClass, "onSuccess", "(Ljava/lang/String;)V");
    if (finish == NULL) {
        LOGE("Unable to find method!");
        return;
    }

    jstring jsourcePath = (*env)->NewStringUTF(env, sourcePath);
    (*env)->CallVoidMethod(env, listener, finish, jsourcePath);
    (*env)->DeleteLocalRef(env, jsourcePath);
}

JNIEXPORT void JNICALL
Java_cn_yan_lib_android_sevenzip_SevenZip_zip(JNIEnv *env, jclass type, jstring srcZipFile_,
                                              jstring dstZipFile_, jobject listener) {
    const char *srcZipFile = (*env)->GetStringUTFChars(env, srcZipFile_, 0);
    const char *dstZipFile = (*env)->GetStringUTFChars(env, dstZipFile_, 0);

    OnStateListener callback = {
            .env = env,
            .objCallback = listener,
            .onStart = callbackStart,
            .onChange = callbackChange,
            .onFinish = callbackFinish,
            .onError = callbackError
    };
    zip(srcZipFile, dstZipFile, callback);

    (*env)->ReleaseStringUTFChars(env, srcZipFile_, srcZipFile);
    (*env)->ReleaseStringUTFChars(env, dstZipFile_, dstZipFile);
}

JNIEXPORT void JNICALL
Java_cn_yan_lib_android_sevenzip_SevenZip_unzip(JNIEnv *env, jclass type, jstring srcZipFile_,
                                                jstring dstZipDir_, jobject listener) {
    const char *srcZipFile = (*env)->GetStringUTFChars(env, srcZipFile_, 0);
    const char *dstZipDir = (*env)->GetStringUTFChars(env, dstZipDir_, 0);

    OnStateListener callback = {
            .env = env,
            .objCallback = listener,
            .onStart = callbackStart,
            .onChange = callbackChange,
            .onFinish = callbackFinish,
            .onError = callbackError
    };
    unzip(srcZipFile, dstZipDir, callback);

    (*env)->ReleaseStringUTFChars(env, srcZipFile_, srcZipFile);
    (*env)->ReleaseStringUTFChars(env, dstZipDir_, dstZipDir);
}
