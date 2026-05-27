#ifndef AUTH_SESSION_H
#define AUTH_SESSION_H

#include <stdbool.h>

/* Initialize auth session system */
void auth_session_init(void);

/* Start authenticated session */
void auth_session_start(void);

/* End authenticated session */
void auth_session_end(void);

/* Check session state */
bool auth_session_is_active(void);

#endif
