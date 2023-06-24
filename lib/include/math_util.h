
#ifndef  ARCH_MATH_UTIL_H
#define  ARCH_MATH_UTIL_H

#include  <stdint.h>


static  inline  uint32_t  is_clog2(uint32_t  value)
{
    return   !((value - 1) & value);
}


















#endif

