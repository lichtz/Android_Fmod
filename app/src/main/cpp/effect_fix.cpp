//
// Created by licht on 2018/3/11.
//
#include "fmod.hpp"
#include "com_zero_licht_androidfmod_EffectUtils.h"
#include <unistd.h>
#include <android/log.h>
#define  TYPE_NORMAL 0
#define TYPE_LUOLI 1
#define  TYPE_DASHU 2
#define  TYPE_FUN 3
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,"zyl",__VA_ARGS__)

using namespace FMOD;
JNIEXPORT void JNICALL Java_com_zero_licht_androidfmod_EffectUtils_fix
(JNIEnv * jniEnv, jclass cls, jstring path, jint type){
    System *system;
     Sound *sound1;
    Channel *channel;
    DSP *dsp;
    System_Create(&system);

//初始化
    system->init(32, FMOD_INIT_NORMAL, NULL);
    const  char* audio_path = jniEnv->GetStringUTFChars(path,NULL);
    //创建声音
    system->createSound(audio_path,FMOD_DEFAULT,0,&sound1);
    try {
        switch (type){
            case TYPE_NORMAL :
                system->playSound(sound1,0, false,&channel);
                break;
            case TYPE_LUOLI:
                system->createDSPByType(FMOD_DSP_TYPE_PITCHSHIFT,&dsp);
                dsp->setParameterFloat(FMOD_DSP_PITCHSHIFT_PITCH,2.5);
                system->playSound(sound1,0, false,&channel);
                channel->addDSP(0,dsp);

                break;
            case TYPE_DASHU:
                system->createDSPByType(FMOD_DSP_TYPE_PITCHSHIFT,&dsp);
                dsp->setParameterFloat(FMOD_DSP_PITCHSHIFT_PITCH,0.8);
                system->playSound(sound1,0, false,&channel);
                channel->addDSP(0,dsp);
                break;
            case TYPE_FUN:
                system->playSound(sound1,0, false,&channel);
                float  frequency;
                channel->getFrequency(&frequency);
                frequency = frequency *1.6;
                channel->setFrequency(frequency);
                break;
            case 4:
                system->createDSPByType(FMOD_DSP_TYPE_ECHO,&dsp);
                dsp->setParameterFloat(FMOD_DSP_ECHO_DELAY,300);
                dsp->setParameterFloat(FMOD_DSP_ECHO_FEEDBACK,20);
                system->playSound(sound1,0, false,&channel);
                channel->addDSP(0,dsp);

                break;
            case 5:
                system->createDSPByType(FMOD_DSP_TYPE_TREMOLO,&dsp);
                dsp->setParameterFloat(FMOD_DSP_TREMOLO_SKEW,1);
                system->playSound(sound1,0, false,&channel);
                channel->addDSP(0,dsp);
                break;
            default:
                break;

        }
        system->update();
        bool playing = true;
        while (playing) {
            channel->isPlaying(&playing);
            usleep(1000000);

        }
    }catch (...){
        goto end;

    }
    goto end;


end:
    jniEnv->ReleaseStringUTFChars(path,audio_path);
    sound1->release();
    dsp->release();
    system->release();
}
