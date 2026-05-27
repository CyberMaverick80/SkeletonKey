#ifndef AUTH_LOCKOUT_H
#define AUTH_LOCKOUT_H

#include <stdbool.h>

/* Initialize lockout system */
void auth_lockout_init(void);

/* Increment failed attempts */
void auth_lockout_increment(void);

/* Reset failed attempts */
void auth_lockout_reset(void);

/* Check lockout status */
bool auth_lockout_is_locked(void);

#endif
