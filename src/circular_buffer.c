#include "circular_buffer.h"
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>


void cb_init(struct circular_buffer *cb, uint16_t *buffer, size_t size) {
    cb->buffer = buffer;
    cb->size = size;
    cb->head = 0;
    cb->tail = 0;
    cb->is_full = false;
}

bool cb_is_empty(struct circular_buffer *cb) {
    // If not full and head is at tail, the buffer must be empty
    return (!cb->is_full && (cb->head == cb->tail));
}

bool cb_is_full(struct circular_buffer *cb) {
    return cb->is_full;
}

bool cb_push(struct circular_buffer *cb, uint16_t data) {
    if (cb_is_full(cb)) {
        return false; // Error: Buffer overflow
    }

    // Write data at the current head position
    cb->buffer[cb->head] = data;

    // Advance head and wrap around using modulo
    cb->head = (cb->head + 1) % cb->size;

    // Check if head caught up to tail
    if (cb->head == cb->tail) {
        cb->is_full = true;
    }

    return true;
}

bool cb_pop(struct circular_buffer *cb, uint16_t *data) {
    if (cb_is_empty(cb)) {
        return false; // Error: Buffer underflow
    }

    // SAFE COPY: Copy value from buffer to the provided variable
    // This happens BEFORE we move the tail pointer
    *data = cb->buffer[cb->tail];

    // Beacuse we are removing an item, the buffer cannot be full anymore
    cb->is_full = false;

    // Advance tail and wrap around
    cb->tail = (cb->tail + 1) % cb->size;

    return true;
}
