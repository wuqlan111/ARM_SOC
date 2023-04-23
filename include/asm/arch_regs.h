
#ifndef  ARMv7_ARCH_REGS
#define  ARMv7_ARCH_REGS

#include  <stdint.h>


// arch special  registers
#define  APSR_REG             "APSR"
#define  IPSR_REG             "IPSR"
#define  EPSR_REG             "EPSR"
#define  IAPSR_REG            "IAPSR"
#define  EAPSR_REG            "EAPSR"
#define  XPSR_REG             "XPSR"
#define  IEPSR_REG            "IEPSR"
#define  MSP_REG              "MSP"
#define  PSR_REG              "PSR"
#define  PRIMASK_REG          "PRIMASK"
#define  BASEPRI_REG          "BASEPRI"
#define  BASEPRI_MAX_REG      "BASEPRI_MAX"
#define  FAULTMASK_REG        "FAULTMASK"
#define  CONTROL_REG          "CONTROL"


//read  special  register
#define   read_xpsr(name)    {       \
                    uint32_t val = 0;    \
                    __asm__ volatile("\tmrs\t" (name)", %0":"=r"(val)::"=r"(val));       \
                    val;                \
                }
//write  special  register
#define   write_xpsr(name, value)   {       \
                    uint32_t  val  = (value);       \
                    __asm__ volatile("\tmsr %0, "(name)::"=r"(val):"=r"(val));  \
                }

//update  special  register
#define   update_xpsr(name,  value, mask)  {        \
                    uint32_t  val  =  0;            \
                    __asm__ volatile("\tmrs\t"(name)", %0":"=r"(val)::"=r"(val));       \
                    val &= ~(mask);           \
                    val |=  ((mask) & (value));     \
                    __asm__ volatile("\tmsr %0, "(name)::"=r"(val):"=r"(val));  \
                }


#define  CLEAR_PRIMASK()     (__asm__ volatile("\tcpsie i":::))
#define  SET_PRIMASK()       (__asm__ volatile("\tcpsid i":::))
#define  CLEAR_FAULTMASK()   (__asm__ volatile("\tcpsie f":::))
#define  SET_FAULTMASK()     (__asm__ volatile("\tcpsid f":::))


#define  SCS_BASE_ADDR       (0xE000E000u)
#define  SYSTICK_REG_OFFSET  (0x10u)
#define  NVIC_REG_OFFSET     (0x100u)
#define  SCB_REG_OFFSET      (0xD00u)
#define  MPU_REG_OFFSET      (0xD90u)
#define  DEBUG_REG_OFFSET    (0xDF0u)
#define  SW_REG_OFFSET       (0xF00u)
#define  CACHE_REG_OFFSET    (0xF8Fu)
#define  MID_REG_OFFSET      (0xFD0u)


/**/









#endif


