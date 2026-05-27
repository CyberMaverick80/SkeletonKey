#include "security/session/session_timeout.h"
#include "security/session/session_guard.h"

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(session_timeout, LOG_LEVEL_INF);

/* =========================================================
 * Configuration
 * ========================================================= */

#define SESSION_TIMEOUT_SECONDS 30

/* =========================================================
 * Internal state
 * ========================================================= */

static int64_t last_activity_time;

/* =========================================================
 * Session timeout implementation
 * ========================================================= */

void session_timeout_init(void)
{
    last_activity_time = k_uptime_get();

    LOG_INF("Session timeout initialized");
}

void session_timeout_refresh(void)
{
    last_activity_time = k_uptime_get();
}

void session_timeout_check(void)
{
    int64_t current_time = k_uptime_get();

    int64_t elapsed_ms =
        current_time - last_activity_time;

    if (elapsed_ms >=
        (SESSION_TIMEOUT_SECONDS * 1000)) {

        LOG_WRN("Session timeout exceeded");

        session_guard_lock();
    }
}
