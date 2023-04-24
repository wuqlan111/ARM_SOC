
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



#define  ICTR_REG_ADDR            (SCS_BASE_ADDR + 0x4)
#define  ACTLR_REG_ADDR           (SCS_BASE_ADDR + 0x8)


//systick registers
#define   SYSTICK_BASE_ADDR              (SCS_BASE_ADDR +  SYSTICK_REG_OFFSET)
#define   SYSTICK_CSR_REG_ADDR           (SYSTICK_BASE_ADDR)
#define   SYSTICK_RVR_REG_ADDR           (SYSTICK_BASE_ADDR  +  0x4)
#define   SYSTICK_CVR_REG_ADDR           (SYSTICK_BASE_ADDR  +  0x8)
#define   SYSTICK_CALIB_REG_ADDR         (SYSTICK_BASE_ADDR  +  0xc)


//nvic  registers
#define  NVIC_BASE_ADDR                       (SCS_BASE_ADDR + NVIC_REG_OFFSET)
#define  NVIC_ISER_REG_ADDR(n)                (NVIC_BASE_ADDR + (n) * 4)
#define  NVIC_ICER_REG_ADDR(n)                (NVIC_BASE_ADDR + 0x80 + (n) * 4)
#define  NVIC_ISPR_REG_ADDR(n)                (NVIC_BASE_ADDR + 0x100 + (n) * 4)
#define  NVIC_ICPR_REG_ADDR(n)                (NVIC_BASE_ADDR + 0x180 + (n) * 4)
#define  NVIC_IABR_REG_ADDR(n)                (NVIC_BASE_ADDR + 0x200 + (n) * 4)
#define  NVIC_IPR_REG_ADDR(n)                 (NVIC_BASE_ADDR + 0x300 + (n) * 4)
#define  NVIC_ISER_PERI_INT_WIDTH             1
#define  NVIC_ICER_PERI_INT_WIDTH             1
#define  NVIC_ISPR_PERI_INT_WIDTH             1
#define  NVIC_ICPR_PERI_INT_WIDTH             1
#define  NVIC_IABR_PERI_INT_WIDTH             1
#define  NVIC_IPR_PERI_INT_WIDTH              8



//scb registers
#define  SCB_BASE_ADDR                      (SCS_BASE_ADDR + SCB_REG_OFFSET)
#define  SCB_CPUID_REG_ADDR                 (SCB_BASE_ADDR)
#define  SCB_ICSR_REG_ADDR                  (SCB_BASE_ADDR + 0x4)
#define  SCB_VTOR_REG_ADDR                  (SCB_BASE_ADDR + 0x8)
#define  SCB_AIRCR_REG_ADDR                 (SCB_BASE_ADDR + 0xC)
#define  SCB_SCR_REG_ADDR                   (SCB_BASE_ADDR + 0x10)
#define  SCB_CCR_REG_ADDR                   (SCB_BASE_ADDR + 0x14)
#define  SCB_SHPR1_REG_ADDR                 (SCB_BASE_ADDR + 0x18)
#define  SCB_SHPR2_REG_ADDR                 (SCB_BASE_ADDR + 0x1C)
#define  SCB_SHPR3_REG_ADDR                 (SCB_BASE_ADDR + 0x20)
#define  SCB_SHPRR_REG_ADDR                 (SCB_BASE_ADDR + 0x24)
#define  SCB_CFSR_REG_ADDR                  (SCB_BASE_ADDR + 0x28)
#define  SCB_HFSR_REG_ADDR                  (SCB_BASE_ADDR + 0x2C)
#define  SCB_DFSR_REG_ADDR                  (SCB_BASE_ADDR + 0x30)
#define  SCB_MMFAR_REG_ADDR                 (SCB_BASE_ADDR + 0x34)
#define  SCB_BFAR_REG_ADDR                  (SCB_BASE_ADDR + 0x38)
#define  SCB_AFSR_REG_ADDR                  (SCB_BASE_ADDR + 0x3C)
#define  SCB_ID_PFR0_REG_ADDR               (SCB_BASE_ADDR + 0x40)
#define  SCB_ID_PFR1_REG_ADDR               (SCB_BASE_ADDR + 0x44)
#define  SCB_ID_DFR0_REG_ADDR               (SCB_BASE_ADDR + 0x48)
#define  SCB_ID_AFR0_REG_ADDR               (SCB_BASE_ADDR + 0x4C)
#define  SCB_ID_MMFR0_REG_ADDR              (SCB_BASE_ADDR + 0x50)
#define  SCB_ID_MMFR1_REG_ADDR              (SCB_BASE_ADDR + 0x54)
#define  SCB_ID_MMFR2_REG_ADDR              (SCB_BASE_ADDR + 0x58)
#define  SCB_ID_MMFR3_REG_ADDR              (SCB_BASE_ADDR + 0x5C)
#define  SCB_ID_ISAR0_REG_ADDR              (SCB_BASE_ADDR + 0x60)
#define  SCB_ID_ISAR1_REG_ADDR              (SCB_BASE_ADDR + 0x64)
#define  SCB_ID_ISAR2_REG_ADDR              (SCB_BASE_ADDR + 0x68)
#define  SCB_ID_ISAR3_REG_ADDR              (SCB_BASE_ADDR + 0x6C)
#define  SCB_ID_ISAR4_REG_ADDR              (SCB_BASE_ADDR + 0x70)
#define  SCB_ID_ISAR5_REG_ADDR              (SCB_BASE_ADDR + 0x74)
#define  SCB_ID_CLIDR_REG_ADDR              (SCB_BASE_ADDR + 0x78)
#define  SCB_ID_CTR_REG_ADDR                (SCB_BASE_ADDR + 0x7C)
#define  SCB_ID_CCSIDR_REG_ADDR             (SCB_BASE_ADDR + 0x80)
#define  SCB_ID_CSSELR_REG_ADDR             (SCB_BASE_ADDR + 0x84)
#define  SCB_CPACR_REG_ADDR                 (SCB_BASE_ADDR + 0x88)






















#endif


