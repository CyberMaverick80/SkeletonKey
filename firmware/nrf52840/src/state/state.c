#include "state.h"
#include <zephyr/sys/printk.h>

static system_state_t state = STATE_BOOT;

void state_set_operational(void)
{
    state = STATE_OPERATIONAL;
}

void state_set_locked(void)
{
    state = STATE_LOCKED;
}

void state_tick(void)
{
    switch (state) {
        case STATE_OPERATIONAL:
            printk("STATE: OPERATIONAL\n");
            break;

        case STATE_LOCKED:
            printk("STATE: LOCKED\n");
            break;

        default:
            printk("STATE: INITIALIZING\n");
            break;
    }
}
