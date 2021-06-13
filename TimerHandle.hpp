/**
 * @file TimerHandle.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "Arduino.h"

class TimerHandle
{
private:
    unsigned long prevMillis;
    unsigned long time;
    bool aux;
public:
    TimerHandle(){}
    TimerHandle(unsigned long timer){
        time = timer;
    }
    void setTimer(unsigned long time){
        this->time = time;
    }
    bool tick(){
        return this->tick(time);
    }
    bool tick(unsigned long time){
        aux = false;
        if(prevMillis == 0){
            prevMillis = millis();
        }
        if(millis() - prevMillis >= time){
            aux = true;
            prevMillis += time;
        }
        return aux;
    }
};
