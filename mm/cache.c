
#include  <stdint.h>
#include  "arch_regs.h"
#include  "cache.h"

#define  MAX_CACHE_WRITE_BACK      (2048)
#define  CTR_CWG_BIT       (24)
#define  CTR_ERG_BIT       (20)
#define  CTR_DCACHE_MIN_BIT     (16)

typedef  struct {


} __attribute(pack(4)) cache_info_t;



uint32_t get_cache_write_back_granule(void)
{
    uint32_t val = REG32_READ(ID_CTR_REG_ADDR)>>CTR_CWG_BIT & 0xf;
    return  1<<(val + 2);
}


uint32_t get_cache_exclusive_access_granule(void)
{
    uint32_t val = REG32_READ(ID_CTR_REG_ADDR)>>CTR_ERG_BIT & 0xf;
    return  1<<(val+2);
}


uint32_t get_dcache_min_line(void)
{
    uint32_t val = REG32_READ(ID_CTR_REG_ADDR)>>CTR_DCACHE_MIN_BIT & 0xf;
    return  1<<(val+2);
}


uint32_t get_icache_min_line(void)
{
    uint32_t val = REG32_READ(ID_CTR_REG_ADDR) & 0xf;
    return  1<<(val+2);
}








