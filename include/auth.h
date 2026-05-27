#ifndef AUTH_H
#define AUTH_H

#include <stdbool.h>

void auth_init(void);

bool auth_verify_pin(const char *pin);

int auth_remaining_attempts(void);

bool auth_is_locked_out(void);

#endif
