
#include  <stdint.h>
#include  <stdlib.h>
#include  <string.h>
#include  <memory.h>

#include  "mpu.h"
#include  "arch_printk.h"


void  mpu_test(void)
{

    uint32_t  max_regions = get_mpu_max_regions();
    __DBG_PRINTF_ALL("mpu support max regions:\t%d\n", max_regions);
    /*get */

    








}



