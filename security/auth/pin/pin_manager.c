#include "pin_manager.h"

#include <string.h>

static char stored_pin[PIN_MAX_LENGTH] = "1234";

void pin_manager_init(void)
{
    /* Placeholder initialization */
}

bool pin_manager_verify(
    const char *entered_pin
)
{
    bool result =
        (strcmp(entered_pin, stored_pin) == 0);

    return result;
}

void pin_manager_clear_buffer(
    char *buffer,
    uint32_t length
)
{
    if (buffer == NULL) {
        return;
    }

    volatile char *p = buffer;

    while (length--) {
        *p++ = 0;
    }
}
