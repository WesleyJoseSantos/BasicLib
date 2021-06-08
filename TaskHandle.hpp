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

#pragma once

#include "TimerHandle.hpp"

class TaskHandle
{
private:
    TimerHandle taskTimer;
public:
    void run(int time, void (*task)()){
        if(taskTimer.tick(time)){
            task();
        }
    }
};