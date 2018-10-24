//
// Created by yan on 2018/10/24.
//

#ifndef ANDROID_7ZIP_ANDROIDNDKLOGCAT_H
#define ANDROID_7ZIP_ANDROIDNDKLOGCAT_H

#include<android/log.h>

#define _DEBUG_LOG 1
#define TAG "7ZIPEXECUTOR"

#if _DEBUG_LOG
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL, TAG, __VA_ARGS__)
#else
#define LOGD(...)
#define LOGI(...)
#define LOGW(...)
#define LOGE(...)
#define LOGF(...)
#endif


#endif //ANDROID_7ZIP_ANDROIDNDKLOGCAT_H
