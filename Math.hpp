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

/**
 * @brief Classe estática para operações matemáticas recorrentes
 * 
 */
class Math
{
private:

public:
    Math() {}
    static int map(int x, int in_min, int in_max, int out_min, int out_max, bool limit = false){
        int out = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
        if(limit){
            return Math::limit(out, out_min, out_max);
        }else{
            return out;
        }
    }

    static int limit(int in, int lim1, int lim2){
        int lMin, lMax, out;
        if(lim1 == lim2) return lim1;
        lMin = lim1 < lim2 ? lim1 : lim2;
        lMax = lim1 > lim2 ? lim1 : lim2;
        out = min(in, lMax);
        out = max(in, lMin);
        return out;
    }
};
