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

/**
 * @brief Manipulador de task
 * 
 */
class TaskHandle
{
private:
    TimerHandle taskTimer;
    void (*task)();
public:
    /**
     * @brief Constrói um novo objeto do tipo TaskHandle
     * 
     */
    TaskHandle(){}
    void init(unsigned long timer, void (*task)()){
        setTimer(timer);
        setTaskCallback(task);
    }

    /**
     * @brief Seta o intervalo de execução da task
     * 
     * @param timer 
     */
    void setTimer(unsigned long timer){
        taskTimer.setTimer(timer);
    }

    /**
     * @brief Seta o método a ser executado pela task
     * 
     * @param task 
     */
    void setTaskCallback(void (*task)()){
        this->task = task;
    }

    /**
     * @brief Executa a task
     * 
     * @param timer Intervalo de execução da task
     */
    void run(unsigned long timer){
        if(taskTimer.tick(timer)){
            this->task();
        }
    }

    /**
     * @brief Executa a task
     * 
     */
    void run(){
        if(taskTimer.tick()){
            this->task();
        }
    }
};