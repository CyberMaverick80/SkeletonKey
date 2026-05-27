#ifndef SESSION_GUARD_H
#define SESSION_GUARD_H

#include <stdbool.h>

/* =========================================================
 * Session Guard API
 * ========================================================= */

void session_guard_init(void);

bool session_guard_is_authenticated(void);

bool session_guard_allow_sensitive_action(void);

void session_guard_lock(void);

void session_guard_unlock(void);

#endif
