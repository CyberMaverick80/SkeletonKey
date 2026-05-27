#include "hal/display/display_hal.h"
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(display_hal);

void display_hal_init(void) {}

void display_hal_clear(void) {}

void display_hal_render_text(const char *text)
{
    LOG_INF("DISPLAY: %s", text);
}
