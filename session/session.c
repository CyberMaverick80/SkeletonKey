#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#include "session.h"
#include "state.h"

LOG_MODULE_REGISTER(session, LOG_LEVEL_INF);

#define SESSION_TIMEOUT_SECONDS 15

static bool active_session = false;

static int64_t session_expiration = 0;

void session_init(void)
{
    LOG_INF("Session manager initialized");
}

void session_start(void)
{
    active_session = true;

    session_expiration =
        k_uptime_get() + (SESSION_TIMEOUT_SECONDS * 1000);

    LOG_INF("Secure session started");

    state_set(STATE_UNLOCKED);
}

void session_end(void)
{
    active_session = false;

    LOG_WRN("Secure session ended");

    state_set(STATE_LOCKED);
}

void session_refresh(void)
{
    if (!active_session) {
        return;
    }

    session_expiration =
        k_uptime_get() + (SESSION_TIMEOUT_SECONDS * 1000);

    LOG_INF("Session refreshed");
}

bool session_is_active(void)
{
    if (!active_session) {
        return false;
    }

    if (k_uptime_get() > session_expiration) {

        LOG_WRN("Session timeout");

        session_end();

        return false;
    }

    return true;
}
