#include <zephyr/logging/log.h>

#include "state.h"

LOG_MODULE_REGISTER(state, LOG_LEVEL_INF);

static sk_state_t current_state = STATE_BOOT;

void state_init(void)
{
    LOG_INF("State manager initialized");
}

void state_set(sk_state_t new_state)
{
    LOG_INF("State transition: %s -> %s",
        state_to_string(current_state),
        state_to_string(new_state));

    current_state = new_state;
}

sk_state_t state_get(void)
{
    return current_state;
}

const char *state_to_string(sk_state_t state)
{
    switch (state) {

    case STATE_BOOT:
        return "BOOT";

    case STATE_LOCKED:
        return "LOCKED";

    case STATE_AUTH_REQUIRED:
        return "AUTH_REQUIRED";

    case STATE_UNLOCKED:
        return "UNLOCKED";

    case STATE_RECOVERY:
        return "RECOVERY";

    case STATE_TAMPER:
        return "TAMPER";

    default:
        return "UNKNOWN";
    }
}
