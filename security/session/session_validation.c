#include "security/session/session_validation.h"
#include "security/session/session_guard.h"

#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(session_validation, LOG_LEVEL_INF);

/* =========================================================
 * Session validation implementation
 * ========================================================= */

void session_validation_init(void)
{
    LOG_INF("Session validation initialized");
}

bool session_validation_is_valid(void)
{
    return session_guard_is_authenticated();
}
