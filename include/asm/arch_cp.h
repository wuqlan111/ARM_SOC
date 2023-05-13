
#ifndef  ARCH_COPROCESSOR_H
#define  ARCH_COPROCESSOR_H

#include  <stdint.h>

#include  "arch_regs.h"

#define MAX_CP_NUMBER     16

enum {
    CP_ACCESS_DENIED  =  0,
    CP_ACCESS_PRIVILEGED,
    CP_ACCESS_RESERVED,
    CP_ACCESS_FULL,
};


static inline uint32_t is_cp_implemented(uint32_t cp)
{
    if (cp >=  MAX_CP_NUMBER)
        return  0;
    uint32_t flag  =  (0x3 << cp);
    REG32_UPDATE(SCB_CPACR_REG_ADDR, flag, flag);
    uint32_t  ret  =  REG32_READ(SCB_CPACR_REG_ADDR) & flag ? 1: 0;
    return  ret;
}

static  inline enable_or_disable_cp(uint32_t  cp)
{



}



#endif

