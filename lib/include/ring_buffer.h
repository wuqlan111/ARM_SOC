
#ifndef   RING_BUFFER_H
#define   RING_BUFFER_H

#include  <stdint.h>

struct ring_buffer;
typedef  struct  ring_buffer  ring_buffer_t;

struct  ring_buffer{
    uint32_t  head;
    uint32_t  size;
    uint32_t  tail;
    uint8_t  *  buffer;
    int32_t  (* read_data_len)(ring_buffer_t * buffer, uint32_t * len);
};






#endif


