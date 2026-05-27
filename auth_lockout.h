#ifndef AUTH_LOCKOUT_H
#define AUTH_LOCKOUT_H

#include <stdbool.h>
#include <stdint.h>

void auth_lockout_init(void);

void auth_lockout_record_failure(void);
void auth_lockout_reset(void);

bool auth_lockout_is_active(void);

uint32_t auth_lockout_remaining_seconds(void);

#endif
