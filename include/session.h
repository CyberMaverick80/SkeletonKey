#ifndef SESSION_H
#define SESSION_H

#include <stdbool.h>

void session_init(void);

void session_start(void);

void session_end(void);

void session_refresh(void);

bool session_is_active(void);

#endif
