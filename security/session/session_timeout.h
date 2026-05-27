#ifndef SESSION_TIMEOUT_H
#define SESSION_TIMEOUT_H

/* =========================================================
 * Session timeout API
 * ========================================================= */

void session_timeout_init(void);

void session_timeout_refresh(void);

void session_timeout_check(void);

#endif
