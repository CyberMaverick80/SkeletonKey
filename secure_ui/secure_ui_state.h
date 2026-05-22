#ifndef SECURE_UI_STATE_H
#define SECURE_UI_STATE_H

#include "secure_ui_types.h"

void secure_ui_state_init(void);

void secure_ui_set_screen(secure_ui_screen_t screen);

secure_ui_screen_t secure_ui_get_screen(void);

#endif
