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

/**
 * @brief Manipulador de timer
 * 
 */
class TimerHandle
{
private:
    unsigned long prevMillis;
    unsigned long time;
    bool aux;
public:

    /**
     * @brief Constrói um objeto do tipo TimerHandle
     * 
     */
    TimerHandle(){}

    /**
     * @brief Constrói um objeto do tipo TimerHandle
     * 
     * @param timer Tempo do temporizador
     */
    TimerHandle(unsigned long timer){
        time = timer;
    }

    /**
     * @brief Seta o tempo do temporizador
     * 
     * @param time 
     */
    void setTimer(unsigned long time){
        this->time = time;
    }

    /**
     * @brief Verifica se o temporizador foi esgotado. Caso verdadeiro, reseta o temporizador.
     * 
     * @return true 
     * @return false 
     */
    bool tick(){
        return this->tick(time);
    }

    /**
     * @brief Varifica se o temporizador foi esgotado. Caso verdadeiro, reseta o temporizador.
     * 
     * @param time Intervalo de tempo a ser definido para o temporizador.
     * @return true 
     * @return false 
     */
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
