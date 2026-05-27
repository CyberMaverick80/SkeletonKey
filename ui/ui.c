#include <zephyr/logging/log.h>
#include "ui.h"

LOG_MODULE_REGISTER(ui, LOG_LEVEL_INF);

void ui_init(void)
{
    LOG_INF("UI subsystem initialized");
}
