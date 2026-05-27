#ifndef AUTH_STATE_MACHINE_H
#define AUTH_STATE_MACHINE_H

typedef enum {

    AUTH_STATE_LOCKED = 0,
    AUTH_STATE_AUTH_REQUIRED,
    AUTH_STATE_AUTHENTICATED,
    AUTH_STATE_FAILED

} auth_state_t;

void auth_state_machine_init(void);

void auth_state_transition(auth_state_t state);

auth_state_t auth_state_get(void);

#endif
