#include <zephyr/logging/log.h>

#include "secure_ui.h"
#include "secure_ui_renderer.h"

LOG_MODULE_REGISTER(secure_ui, LOG_LEVEL_INF);

void secure_ui_init(void)
{
    secure_ui_render_screen(SECURE_SCREEN_BOOT);
}

void secure_ui_show_locked(void)
{
    secure_ui_render_screen(SECURE_SCREEN_LOCKED);
}

void secure_ui_show_auth(void)
{
    secure_ui_render_screen(SECURE_SCREEN_AUTH);
}

void secure_ui_show_home(void)
{
    secure_ui_render_screen(SECURE_SCREEN_HOME);
}
