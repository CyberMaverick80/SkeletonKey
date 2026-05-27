#include "security/session/session_guard.h"

#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(session_guard, LOG_LEVEL_INF);

/* =========================================================
 * Internal state
 * ========================================================= */

static bool session_authenticated = false;

/* =========================================================
 * Session guard implementation
 * ========================================================= */

void session_guard_init(void)
{
    session_authenticated = false;

    LOG_INF("Session guard initialized");
}

bool session_guard_is_authenticated(void)
{
    return session_authenticated;
}

bool session_guard_allow_sensitive_action(void)
{
    if (!session_authenticated) {

        LOG_WRN("Sensitive action denied");
        return false;
    }

    return true;
}

void session_guard_lock(void)
{
    session_authenticated = false;

    LOG_WRN("Session locked");
}

void session_guard_unlock(void)
{
    session_authenticated = true;

    LOG_INF("Session unlocked");
}
