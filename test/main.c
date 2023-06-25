
#include  <stdio.h>
#include  <stdint.h>

#include  "arch_printk.h"


extern  void  invalid_data_address(uint32_t is_write);

int  main(void)
{

    invalid_data_address(1);

    invalid_data_address(0);

    while(1) ;

    return  0;
}





