
#include  <stdio.h>
#include  <stdint.h>

#include  "arch_printk.h"


int  main(void)
{

    uint32_t  * p = (uint32_t * )0xffff0;
    *p   =  0x12345678;


    for (int32_t i = 0; i < 4; i++) {
        
        __DBG_PRINTF_ALL("/********%d****/\n", i);
    }

    while(1) ;

    return  0;
}





