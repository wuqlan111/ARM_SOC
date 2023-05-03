
#ifndef  ARCH_NVIC_H
#define  ARCH_NVIC_H

#include  <stdint.h>

#include  "arch_regs.h"

static  inline  uint32_t  get_max_interrupt()
{
    return  (REG32_READ(ICTR_REG_ADDR) + 1) << 5;
}

static  inline int32_t get_interrupt_state(uint32_t  irq)
{
    uint32_t  max_number = get_max_interrupt();
    if (max_number < irq)
        return  -1;

    return  
}













#endif

