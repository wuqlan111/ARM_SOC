
#ifndef   RING_BUFFER_H
#define   RING_BUFFER_H

#include  <stdint.h>

typedef struct {
    uint32_t  head;
    uint32_t  size;
    uint32_t  tail;
    uint8_t  *  buffer;
} ring_buffer_t;






#endif


