
#include  <stdint.h>
#include  <memory.h>

#include  "arch_regs.h"


extern  void  reset_init_exceptions(void);

extern  int  main(void);


void   arch_init(void)
{

    uint32_t   *  p  =  (uint32_t *)0x0800fffc;
    uint32_t  a   =  *p;
     *p  =   12;

    reset_init_exceptions();

    main();

}







