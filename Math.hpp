/**
 * @file Math.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

class Math
{
private:

public:
    Math() {}
    static long map(long x, long in_min, long in_max, long out_min, long out_max){
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    }
};
