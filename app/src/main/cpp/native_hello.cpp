//
// Created by admin on 2018/10/19.
//
#include <jni.h>
#include <string>
#include "json/json.h"
//使用宏来优化代码调用
#define MYFUNC(name) Java_com_walker_myjnicmake_jni_##name

/*优化之前的代码
extern "C" JNIEXPORT
jstring JNICALL
Java_com_walker_myjnicmake_jni_NativeFun_stringFromJNI(JNIEnv *env, jclass thiz)
{
    std::string hello = "Hello,I from C++";
    return env->NewStringUTF(hello.c_str());
}
 */

// //优化之后的代码
extern "C" JNIEXPORT
jstring JNICALL
MYFUNC(NativeFun_stringFromJNI)(JNIEnv *env, jclass thiz)
{
    return env->NewStringUTF("Hello,I from C++");
}

extern "C" JNIEXPORT
jstring JNICALL
MYFUNC(NativeFun_outputJsonCode)(JNIEnv *env, jclass thiz,
                                   jstring jname, jstring jage, jstring jsex, jstring jtype)
{
    Json::Value root;
    const char *name = env->GetStringUTFChars(jname, NULL);
    const char *age = env->GetStringUTFChars(jage, NULL);
    const char *sex = env->GetStringUTFChars(jsex, NULL);
    const char *type = env->GetStringUTFChars(jtype, NULL);

    root["name"] = name;
    root["age"] = age;
    root["sex"] = sex;
    root["type"] = type;

    env->ReleaseStringUTFChars(jname, name);
    env->ReleaseStringUTFChars(jage, age);
    env->ReleaseStringUTFChars(jsex, sex);
    env->ReleaseStringUTFChars(jtype, type);

    return env->NewStringUTF(root.toStyledString().c_str());
}

extern "C" JNIEXPORT
jstring JNICALL
MYFUNC(NativeFun_parseJsonCode)(JNIEnv *env, jclass thiz,
                                  jstring jjson)
{
    const char *json_str = env->GetStringUTFChars(jjson, NULL);
    std::string out_str;

    Json::CharReaderBuilder b;
    Json::CharReader *reader(b.newCharReader());
    Json::Value root;
    JSONCPP_STRING errs;
    bool ok = reader->parse(json_str, json_str + std::strlen(json_str), &root, &errs);
    if (ok && errs.size() == 0) {
        std::string name = root["name"].asString();
        std::string age = root["age"].asString();
        std::string sex = root["sex"].asString();
        std::string type = root["type"].asString();
        out_str = "name: " + name + "\nage: " + age + "\nsex:" + sex + "\ntype: " + type + "\n";
    }
    env->ReleaseStringUTFChars(jjson, json_str);

    return env->NewStringUTF(out_str.c_str());
}