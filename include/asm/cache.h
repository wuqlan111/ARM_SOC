
#ifndef   ASM_ARCH_CACHE_H
#define   ASM_ARCH_CACHE_H

#include  <stdint.h>

#include  "arch_regs.h"

#define  CTYPE_NO_CACHE     0
#define  CTYPE_INSTRUCTION_CACHE        (1u)
#define  CTYPE_DATA_CACHE          (2u)
#define  CTYPE_SEPARETE_CACHE      (3u)
#define  CTYPE_UNIFIED_CACHE       (4u)


#define get_cache_type(level)    ( (REG32_READ(ID_CLIDR_REG_ADDR) >> ((level) - 1)) & 0x7)












#endif



