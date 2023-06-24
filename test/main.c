
#include  <stdio.h>
#include  <stdint.h>

#include  "arch_printk.h"


extern  void  mpu_test(void);

int  main(void)
{

    mpu_test();

    while(1) ;

    return  0;
}





