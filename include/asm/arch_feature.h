#ifndef   ARCH_FEATURE_H
#define   ARCH_FEATURE_H

#include  <stdint.h>

#include  "arch_regs.h"

static inline  uint32_t can_support_thumb2(void)
{
    return  (REG32_READ(ID_PFR0_REG_ADDR) & 0xf0) == 0xf0;

}


static inline  uint32_t can_support_thumb2(void)
{
    return  (REG32_READ(ID_PFR0_REG_ADDR) & 0xf0) == 0xf0;

}











#endif

