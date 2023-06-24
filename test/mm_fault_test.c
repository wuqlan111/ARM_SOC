
#include  <stdio.h>
#include  <stdint.h>
#include  <memory.h>

#include  "arch_printk.h"



void  invalid_data_address(uint32_t is_write)
{
    uint32_t  * addr = (uint32_t *) 0x100010;
    uint32_t  value  =  0;

    if (is_write) {
        __DBG_PRINTF_ALL("write to addr--%p\n", addr);
        *addr   =   0x11223344;
    } else {
        value   =  *addr;
        __DBG_PRINTF_ALL("read from addr--%p,\tvalue--0x%08x\n", addr,  value);
    }

    uint32_t   a, b = 0;
    a =  b + 2;
    __DBG_PRINTF_ALL("read or write successfully\n");

}




















