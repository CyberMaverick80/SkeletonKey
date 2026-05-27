#include "security/auth/auth_state_machine.h"

static auth_state_t current_state =
    AUTH_STATE_LOCKED;

void auth_state_machine_init(void)
{
    current_state = AUTH_STATE_LOCKED;
}

void auth_state_transition(auth_state_t state)
{
    current_state = state;
}

auth_state_t auth_state_get(void)
{
    return current_state;
}
