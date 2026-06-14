#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>


struct circular_buffer {
	uint16_t *buffer;	// Pointer where the array data is stored
	size_t size;		// Total number of elements in the buffer
	size_t head;		// Index for the next write operation (push)
	size_t tail;		// Index for the next read operation (pop)
	bool is_full;		// Set to true when the buffer is full
};


void cb_init(struct circular_buffer *cb, uint16_t *buffer, size_t size);


bool cb_push(struct circular_buffer *cb, uint16_t data);


bool cb_pop(struct circular_buffer *cb, uint16_t *data);


bool cb_is_empty(struct circular_buffer *cb);


bool cb_is_full(struct circular_buffer *cb);

#endif // CIRCULAR_BUFFER_H
