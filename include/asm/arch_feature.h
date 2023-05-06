#ifndef   ARCH_FEATURE_H
#define   ARCH_FEATURE_H

#include  <stdint.h>

#include  "arch_regs.h"

#define  ID_PFR0_THUMB_FLAG     (0xF0U)
#define  ID_PFR0_THUMB2_SUPPORT   (0x30U)


static inline  uint32_t can_support_thumb2(void)
{
    return  (REG32_READ(ID_PFR0_REG_ADDR) & ID_PFR0_THUMB_FLAG) == ID_PFR0_THUMB2_SUPPORT;

}


#define  ID_DFR0_DEBUG_FLAG    (0xF00000U)
#define  ID_DFR0_DEBUG_MEMORY_MAPPED   (0x100000U)

static inline  uint32_t can_support_memory_mapped_debug(void)
{
    return  (REG32_READ(ID_DFR0_REG_ADDR) & ID_DFR0_DEBUG_FLAG) == ID_DFR0_DEBUG_MEMORY_MAPPED;
}











#endif

