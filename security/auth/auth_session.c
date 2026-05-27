#include "security/auth/auth_session.h"

static bool session_active = false;

void auth_session_init(void)
{
    session_active = false;
}

void auth_session_start(void)
{
    session_active = true;
}

void auth_session_end(void)
{
    session_active = false;
}

bool auth_session_is_active(void)
{
    return session_active;
}
