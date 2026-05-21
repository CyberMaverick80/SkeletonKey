#ifndef SECURE_UI_H
#define SECURE_UI_H

#include "secure_ui/secure_ui_state.h"

void secure_ui_init(void);
void secure_ui_show_locked(void);
void secure_ui_show_auth(void);
void secure_ui_show_home(void);

#endif
