#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#include <stdbool.h>
#include <stdint.h>

#define PIN_MAX_LENGTH 16

void pin_manager_init(void);

bool pin_manager_verify(
    const char *entered_pin
);

void pin_manager_clear_buffer(
    char *buffer,
    uint32_t length
);

#endif
