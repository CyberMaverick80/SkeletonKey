#include <zephyr/logging/log.h>
#include "core.h"

LOG_MODULE_REGISTER(core, LOG_LEVEL_INF);

void core_init(void)
{
    LOG_INF("Core subsystem initialized");
}
