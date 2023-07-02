
#include  <stdint.h>
#include  <memory.h>

#include  "arch_regs.h"


extern  void  reset_init_exceptions(void);

extern  int  main(void);


void   arch_init(void)
{

    uint32_t  a  =  10;
    uint32_t  *p   =  &a;
    *p  =   12;

    uint32_t  b = *p;


    reset_init_exceptions();

    main();

}







