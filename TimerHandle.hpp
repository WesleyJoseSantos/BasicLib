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
    void setTimer(unsigned long time){
        this->time = time;
    }
    bool tick(){
        return tick(time);
    }
    bool tick(unsigned long time){
        if(prevMillis == 0){
            prevMillis = millis();
            aux = 0;
        }
        if(millis() - prevMillis >= time){
            aux = true;
            prevMillis = 0;
        }
        return aux;
    }
};
