#ifndef AUTH_SESSION_H
#define AUTH_SESSION_H

#include <stdbool.h>
#include <stdint.h>

void auth_session_init(void);

void auth_session_start(void);
void auth_session_end(void);

bool auth_session_is_active(void);

uint32_t auth_session_get_uptime(void);

#endif
