#include "secure_ui_screens.h"
#include "secure_ui_renderer.h"

void secure_ui_render_screen(secure_ui_screen_t screen)
{
    switch (screen) {

    case SECURE_UI_SCREEN_BOOT:
        secure_ui_render_text("SkeletonKey Booting...");
        break;

    case SECURE_UI_SCREEN_LOCKED:
        secure_ui_render_text("Device Locked");
        break;

    case SECURE_UI_SCREEN_AUTH:
        secure_ui_render_text("Authenticate");
        break;

    case SECURE_UI_SCREEN_HOME:
        secure_ui_render_text("Welcome Home");
        break;

    case SECURE_UI_SCREEN_CONFIRM:
        secure_ui_render_text("Confirm Action");
        break;

    case SECURE_UI_SCREEN_ERROR:
        secure_ui_render_text("System Error");
        break;

    case SECURE_UI_SCREEN_SHUTDOWN:
        secure_ui_render_text("Shutting Down");
        break;

    default:
        secure_ui_render_text("Unknown Screen");
        break;
    }
}
