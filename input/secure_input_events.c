#include "secure_input_events.h"

#include "../secure_ui/secure_ui.h"

void secure_input_process_event(
    secure_input_event_t event
)
{
    switch (event)
    {
        case SECURE_INPUT_EVENT_LOCK:

            secure_ui_show_locked();

            break;

        case SECURE_INPUT_EVENT_UNLOCK:

            secure_ui_show_home();

            break;

        default:

            break;
    }
}
