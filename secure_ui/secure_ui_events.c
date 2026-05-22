#include "secure_ui_events.h"
#include "secure_ui_state.h"
#include "secure_ui_screens.h"

void secure_ui_handle_event(secure_ui_event_t event)
{
    switch (event) {

    case SECURE_UI_EVENT_AUTH_SUCCESS:
        secure_ui_set_screen(SECURE_UI_SCREEN_HOME);
        break;

    case SECURE_UI_EVENT_AUTH_FAILURE:
        secure_ui_set_screen(SECURE_UI_SCREEN_LOCKED);
        break;

    default:
        break;
    }

    secure_ui_render_screen(secure_ui_get_screen());
}
