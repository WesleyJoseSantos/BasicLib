/**
 * @file TimerPulse.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __TIMERPULSE__H__
#define __TIMERPULSE__H__

#include "Arduino.h"

class TimerPulse
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

#endif  //!__TIMERPULSE__H__