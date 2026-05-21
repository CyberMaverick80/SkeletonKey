#include <zephyr/logging/log.h>

#include "secure_ui_renderer.h"
#include "hal/display_hal.h"

LOG_MODULE_REGISTER(secure_ui_renderer, LOG_LEVEL_INF);

void secure_ui_render_screen(secure_screen_t screen)
{
    switch (screen) {

    case SECURE_SCREEN_BOOT:
        display_render_text("BOOTING...");
        break;

    case SECURE_SCREEN_LOCKED:
        display_render_text("DEVICE LOCKED");
        break;

    case SECURE_SCREEN_AUTH:
        display_render_text("AUTH REQUIRED");
        break;

    case SECURE_SCREEN_HOME:
        display_render_text("WELCOME");
        break;

    case SECURE_SCREEN_WARNING:
        display_render_text("WARNING");
        break;

    case SECURE_SCREEN_FIRMWARE_UPDATE:
        display_render_text("FIRMWARE UPDATE");
        break;

    default:
        display_render_text("UNKNOWN SCREEN");
        break;
    }

    LOG_INF("Rendered secure screen: %d", screen);
}
