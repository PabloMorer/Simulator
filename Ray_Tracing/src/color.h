#ifndef COLOR_H
#define COLOR_H

#include "util.h"

#include <iostream>
using color = vec3;


inline double linear_to_gamma(double linear_component)
{
    return sqrt(linear_component);
}


#endif 
