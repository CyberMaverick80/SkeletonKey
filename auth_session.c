#include "auth_session.h"

#include <zephyr/kernel.h>

static bool session_active = false;
static int64_t session_start_time = 0;

void auth_session_init(void)
{
    session_active = false;
    session_start_time = 0;
}

void auth_session_start(void)
{
    session_active = true;
    session_start_time = k_uptime_get();
}

void auth_session_end(void)
{
    session_active = false;
    session_start_time = 0;
}

bool auth_session_is_active(void)
{
    return session_active;
}

uint32_t auth_session_get_uptime(void)
{
    if (!session_active) {
        return 0;
    }

    return (uint32_t)((k_uptime_get() - session_start_time) / 1000);
}
