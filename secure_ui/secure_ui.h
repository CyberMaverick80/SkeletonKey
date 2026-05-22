#ifndef SECURE_UI_H
#define SECURE_UI_H

#include "secure_ui_types.h"

void secure_ui_init(void);

void secure_ui_show_locked(void);
void secure_ui_show_auth(void);
void secure_ui_show_home(void);

void secure_ui_process_event(secure_ui_event_t event);

#endif
