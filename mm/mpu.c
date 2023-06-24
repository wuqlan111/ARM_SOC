
#include <stdint.h>

#include  "arch_regs.h"
#include  "mpu.h"


#define  MIN_REGION_SIZE     32


int32_t  enable_or_disable_region(uint32_t region, uint32_t enable)
{
    uint32_t  max_region =  get_mpu_max_regions();
    if ( (region >= max_region) )
        return  -1;

    uint32_t flag = enable? 0x1: 0;
    REG32_WRITE(MPU_RNR_REG_ADDR,  region);
    REG32_UPDATE(MPU_RNR_REG_ADDR,  flag, 0x1);
    REG32_WRITE(MPU_RNR_REG_ADDR,  region);

    return 0;
}


int32_t  set_mpu_region_config(uint32_t  region,  mpu_region_config_t * config)
{
    int32_t  ret  =  0;
    uint32_t  max_region =  get_mpu_max_regions();
    if ( (region >= max_region) || !config) {
        return  -1;        
    }

    
    










}












int32_t  get_mpu_region_config(uint32_t  region,  mpu_region_config_t * config);




