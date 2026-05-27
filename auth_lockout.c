#include "auth_lockout.h"

#include <zephyr/kernel.h>

#define AUTH_MAX_FAILURES      5
#define AUTH_LOCKOUT_SECONDS   30

static uint32_t failed_attempts = 0;
static int64_t lockout_start_time = 0;
static bool lockout_active = false;

void auth_lockout_init(void)
{
    failed_attempts = 0;
    lockout_start_time = 0;
    lockout_active = false;
}

void auth_lockout_record_failure(void)
{
    failed_attempts++;

    if (failed_attempts >= AUTH_MAX_FAILURES) {
        lockout_active = true;
        lockout_start_time = k_uptime_get();
    }
}

void auth_lockout_reset(void)
{
    failed_attempts = 0;
    lockout_active = false;
    lockout_start_time = 0;
}

bool auth_lockout_is_active(void)
{
    if (!lockout_active) {
        return false;
    }

    int64_t elapsed =
        (k_uptime_get() - lockout_start_time) / 1000;

    if (elapsed >= AUTH_LOCKOUT_SECONDS) {
        auth_lockout_reset();
        return false;
    }

    return true;
}

uint32_t auth_lockout_remaining_seconds(void)
{
    if (!lockout_active) {
        return 0;
    }

    int64_t elapsed =
        (k_uptime_get() - lockout_start_time) / 1000;

    if (elapsed >= AUTH_LOCKOUT_SECONDS) {
        return 0;
    }

    return AUTH_LOCKOUT_SECONDS - elapsed;
}
