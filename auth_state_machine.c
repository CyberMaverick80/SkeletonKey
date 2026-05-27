#include "auth_state_machine.h"

static auth_state_t current_state = AUTH_STATE_LOCKED;

void auth_state_machine_init(void)
{
    current_state = AUTH_STATE_LOCKED;
}

void auth_state_set(auth_state_t state)
{
    current_state = state;
}

auth_state_t auth_state_get(void)
{
    return current_state;
}

bool auth_state_is_authenticated(void)
{
    return current_state == AUTH_STATE_AUTHENTICATED;
}

bool auth_state_is_locked(void)
{
    return current_state == AUTH_STATE_LOCKED ||
           current_state == AUTH_STATE_LOCKOUT;
}
