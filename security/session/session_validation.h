#ifndef SESSION_VALIDATION_H
#define SESSION_VALIDATION_H

#include <stdbool.h>

/* =========================================================
 * Session validation API
 * ========================================================= */

void session_validation_init(void);

bool session_validation_is_valid(void);

#endif
