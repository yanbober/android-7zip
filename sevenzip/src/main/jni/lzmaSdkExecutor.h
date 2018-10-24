//
// Created by yan on 2018/10/23.
//

#ifndef ANDROID_7ZIP_P7ZIPEXECUTOR_H
#define ANDROID_7ZIP_P7ZIPEXECUTOR_H

#include <jni.h>

typedef void (*OnStart)(JNIEnv*, jobject, char*);
typedef void (*OnChange)(JNIEnv*, jobject, char*, float);
typedef void (*OnError)(JNIEnv*, jobject, char*, int);
typedef void (*OnFinish)(JNIEnv*, jobject, char*);

typedef struct {
    JNIEnv* env;
    jobject objCallback;
    OnStart onStart;
    OnChange onChange;
    OnError onError;
    OnFinish onFinish;
} OnStateListener;

void unzip(const char* srcZipFile, const char* dstFileDir, const OnStateListener listener);

void zip(const char* srcZipFile, const char* dstZipFile, const OnStateListener listener);

#endif //ANDROID_7ZIP_P7ZIPEXECUTOR_H
