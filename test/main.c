
#include  <stdio.h>
#include  <stdint.h>

#include  "arch_printk.h"


extern  void  test_early_printk(void);

int  main(void)
{

    test_early_printk();

    while(1) ;

    return  0;
}





