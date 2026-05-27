#include "security/auth/auth_lockout.h"

static int failed_attempts = 0;

static const int max_attempts = 5;

void auth_lockout_init(void)
{
    failed_attempts = 0;
}

void auth_lockout_increment(void)
{
    failed_attempts++;
}

void auth_lockout_reset(void)
{
    failed_attempts = 0;
}

bool auth_lockout_is_locked(void)
{
    return failed_attempts >= max_attempts;
}
