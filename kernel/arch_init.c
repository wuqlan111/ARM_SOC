
#include  <stdint.h>
#include  <memory.h>

#include  "arch_regs.h"


extern  void  reset_init_exceptions(void);

extern  int  main(void);


void   arch_init(void)
{

    reset_init_exceptions();

    main();

}







