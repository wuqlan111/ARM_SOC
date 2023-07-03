
#include  <stdio.h>
#include  <stdint.h>

#include  "arch_printk.h"


extern  void  test_mm_fault(void);
extern  int32_t  svcall_test(uint32_t  param1,  uint32_t param2,  
            uint32_t param3,  uint32_t  param4);

int  main(void)
{

    __asm__ volatile("svc #3");
    test_mm_fault();
    while(1) ;

    return  0;
}





