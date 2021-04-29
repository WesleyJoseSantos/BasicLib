/**
 * @file TaskHandle.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __TASKHANDLE__H__
#define __TASKHANDLE__H__

#include "TimerPulse.h"

class TaskHandle
{
private:
    TimerPulse taskTimer;
public:
    void run(int time, void (*task)()){
        if(taskTimer.tick(time)){
            task();
        }
    }
};

#endif  //!__TASKHANDLE__H__