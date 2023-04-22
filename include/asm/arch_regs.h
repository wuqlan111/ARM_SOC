
#ifndef  ARMv7_ARCH_REGS
#define  ARMv7_ARCH_REGS

#include  <stdint.h>


#define   read_xpsr(name)    {       \
                    uint32_t val = 0;    \
                    __asm__ volatile("");       \
                }

#define   write_xpsr(name, value)   (__asm__ volatile(""))
                    


#define   update_xpsr(name,  value, mask)  {        \
                    uint32_t  val  =  0;            \
                    __asm__  volatile();        \
                    val &= ~(mask);           \
                    val |=  ((mask) & (value));     \
                    __asm__  volatile();        \
                }





#endif


