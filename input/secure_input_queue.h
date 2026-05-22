#ifndef SECURE_INPUT_QUEUE_H
#define SECURE_INPUT_QUEUE_H

#include <stdbool.h>

#include "secure_input_types.h"

#define SECURE_INPUT_QUEUE_SIZE 16

void secure_input_queue_init(void);

bool secure_input_queue_push(
    secure_input_event_t event
);

bool secure_input_queue_pop(
    secure_input_event_t *event
);

#endif
