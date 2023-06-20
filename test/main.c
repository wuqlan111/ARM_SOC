
#include  <stdio.h>
#include  <stdint.h>

#include  "arch_printk.h"


int  main(void)
{

    for (int32_t i = 0; i < 4; i++) {
        
        __DBG_PRINTF_ALL("/********%d****/\n", i);
    }

    while(1) ;

    return  0;
}





