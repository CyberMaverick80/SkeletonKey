#include <zephyr/kernel.h>

#include "secure_ui_renderer.h"
#include "hal/display/display_hal.h"

void secure_ui_render_text(const char *text)
{
    display_hal_render_text(text);
}

void secure_ui_render_locked(void)
{
    secure_ui_render_text("LOCKED");
}

void secure_ui_render_auth(void)
{
    secure_ui_render_text("AUTH");
}

void secure_ui_render_home(void)
{
    secure_ui_render_text("HOME");
}
