
#ifndef  ARCH_VFP_H
#define  ARCH_VFP_H

#include  <stdint.h>
#include  "arch_regs.h"


#define FPCCR_ASPEN_FALG         (1<<31U)
#define FPCCR_LAZY_SAVE_FALG     (1<<30U)
#define FPCCR_DEBUG_PENDING_FALG     (1<<8U)
#define FPCCR_BUSFAULT_PENDING_FALG       (1<<6U)
#define FPCCR_MEMFAULT_PENDINg_FALG      (1<<5U)
#define FPCCR_HARDFSULT_PENDING_FALG     (1<<4U)
#define FPCCR_THREAD_MODE_FALG         (1<<3U)
#define FPCCR_UNPRIVILEGE_LEVEL_FALG     0x2U
#define FPCCR_LAZY_ACTIVE_FALG       0x1U


#define FPCAR_CONTEXT_ADDR_FLAG      (0xFFFFFFF8U)

















#endif

