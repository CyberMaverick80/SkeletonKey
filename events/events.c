#include <zephyr/logging/log.h>

#include "events.h"

LOG_MODULE_REGISTER(events, LOG_LEVEL_INF);

void event_dispatch(sk_event_t *event)
{
    switch (event->type) {

    case EVENT_SYSTEM_BOOT:
        LOG_INF("EVENT_SYSTEM_BOOT");
        break;

    case EVENT_USB_CONNECTED:
        LOG_INF("EVENT_USB_CONNECTED");
        break;

    case EVENT_USB_DISCONNECTED:
        LOG_INF("EVENT_USB_DISCONNECTED");
        break;

    case EVENT_AUTH_SUCCESS:
        LOG_INF("EVENT_AUTH_SUCCESS");
        break;

    case EVENT_AUTH_FAILURE:
        LOG_INF("EVENT_AUTH_FAILURE");
        break;

    case EVENT_STORAGE_UNLOCKED:
        LOG_INF("EVENT_STORAGE_UNLOCKED");
        break;

    default:
        LOG_WRN("Unknown event");
        break;
    }
}
