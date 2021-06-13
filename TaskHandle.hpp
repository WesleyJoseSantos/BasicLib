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
    void (*task)();
public:
    TaskHandle(){}
    void init(unsigned long timer, void (*task)()){
        setTimer(timer);
        setTaskCallback(task);
    }
    void setTimer(unsigned long timer){
        taskTimer.setTimer(timer);
    }
    void setTaskCallback(void (*task)()){
        this->task = task;
    }
    void run(unsigned long timer){
        if(taskTimer.tick(timer)){
            this->task();
        }
    }
    void run(){
        if(taskTimer.tick()){
            this->task();
        }
    }
};