/**
 * @file Monitor.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __MONITOR__H__
#define __MONITOR__H__

#include "Arduino.h"

#define monitor(x) Serial.print(#x);Serial.print(" = ");Serial.println(x);  ///< Macro para monitoramento de variáveis

#endif  //!__MONITOR__H__
