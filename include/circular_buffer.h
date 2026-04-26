#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>


typedef struct {
    uint16_t *buffer;   // Pointer where the array data is stored
    size_t size;        // Total number of elements in the buffer
    size_t head;        // Index for the next write operation (push)
    size_t tail;        // Index for the next read operation (pop)
    bool is_full;       // Set to true when the buffer is full
} circular_buffer_t;


void cb_init(circular_buffer_t *cb, uint16_t *buffer, size_t size);


bool cb_push(circular_buffer_t *cb, uint16_t data);


bool cb_pop(circular_buffer_t *cb, uint16_t *data);


bool cb_is_empty(circular_buffer_t *cb);


bool cb_is_full(circular_buffer_t *cb);

#endif // CIRCULAR_BUFFER_H