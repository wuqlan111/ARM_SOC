
#ifndef  ARCH_MATH_UTILS_H
#define  ARCH_MATH_UTILS_H

#include  <stdint.h>


static  uint32_t math_log2(uint32_t value)
{
    uint32_t  ret  =  0;
    for (int32_t i =  0; i < 31; i++) {
        if (value & (1 << i)) {
            ret  =  i;
            break;
        }
    }

    return   ret;

}




#endif


