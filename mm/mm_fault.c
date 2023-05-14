
#include <stdio.h> 
#include "context_stack.h"

#define  MMFSR_MMARVALID_MASK       (0x1<<7U)
#define  MMFSR_MLSPERR_MASK         (0x1<<5U)
#define  MMFSR_MSTKERR_MASK         (0x1<<4U)
#define  MMFSR_MUNSTKERR_MASK       (0x1<<3U)
#define  MMFSR_DACCVIOL_MASK        (0x1<<1U)
#define  MMFSR_IACCVIOL_MASK        (0x1U)


static inline uint32_t get_memory_fault_addr(void)
{
    return  REG32_READ(SCB_MMFAR_REG_ADDR);
}

static  inline  uint32_t  get_memory_fault_info(void)
{
    return  REG32_READ(SCB_CFSR_REG_ADDR) & 0xff;
}














