#ifndef AUTH_STATE_MACHINE_H
#define AUTH_STATE_MACHINE_H

#include <stdbool.h>

typedef enum {
    AUTH_STATE_LOCKED = 0,
    AUTH_STATE_WAITING,
    AUTH_STATE_AUTHENTICATED,
    AUTH_STATE_LOCKOUT
} auth_state_t;

/* Initialization */
void auth_state_machine_init(void);

/* State control */
void auth_state_set(auth_state_t state);
auth_state_t auth_state_get(void);

/* State helpers */
bool auth_state_is_authenticated(void);
bool auth_state_is_locked(void);

#endif
