
#include  <stdio.h>
#include  <stdint.h>

#include  "arch_printk.h"


extern  void  test_mm_fault(void);

int  main(void)
{

    __asm__ volatile("svc #3");
    test_mm_fault();
    while(1) ;

    return  0;
}





