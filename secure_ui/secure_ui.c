#include "secure_ui.h"
#include "secure_ui_state.h"
#include "secure_ui_screens.h"
#include "secure_ui_events.h"

void secure_ui_init(void)
{
    secure_ui_state_init();

    secure_ui_render_screen(
        secure_ui_get_screen()
    );
}

void secure_ui_show_locked(void)
{
    secure_ui_set_screen(
        SECURE_UI_SCREEN_LOCKED
    );

    secure_ui_render_screen(
        SECURE_UI_SCREEN_LOCKED
    );
}

void secure_ui_show_auth(void)
{
    secure_ui_set_screen(
        SECURE_UI_SCREEN_AUTH
    );

    secure_ui_render_screen(
        SECURE_UI_SCREEN_AUTH
    );
}

void secure_ui_show_home(void)
{
    secure_ui_set_screen(
        SECURE_UI_SCREEN_HOME
    );

    secure_ui_render_screen(
        SECURE_UI_SCREEN_HOME
    );
}

void secure_ui_process_event(secure_ui_event_t event)
{
    secure_ui_handle_event(event);
}
