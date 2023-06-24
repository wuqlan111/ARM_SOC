
#ifndef   RING_BUFFER_H
#define   RING_BUFFER_H

#include  <stdint.h>

struct ring_buffer;
typedef  struct  ring_buffer  ring_buffer_t;

struct  ring_buffer{
    uint32_t  head;
    const  uint32_t  size;
    uint32_t  tail;
    uint8_t  *  const  buffer;
    int32_t  (* const read_data_len)(ring_buffer_t * buffer, uint32_t * len);
};

int32_t  get_ring_buffer_data_len(ring_buffer_t * buffer, uint32_t  * len);
void  clean_ring_buffer_data(ring_buffer_t * buffer);
int32_t  write_to_ring_buffer(ring_buffer_t * buffer, uint8_t * data, uint32_t len);
int32_t  read_from_ring_buffer(ring_buffer_t * buffer, uint8_t * data, uint32_t size, uint32_t * len);




#endif


