#include "secure_ui_state.h"

static secure_ui_screen_t current_screen = SECURE_UI_SCREEN_BOOT;

void secure_ui_state_init(void)
{
    current_screen = SECURE_UI_SCREEN_BOOT;
}

void secure_ui_set_screen(secure_ui_screen_t screen)
{
    current_screen = screen;
}

secure_ui_screen_t secure_ui_get_screen(void)
{
    return current_screen;
}
