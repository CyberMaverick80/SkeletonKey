#include <zephyr/logging/log.h>
#include "security.h"

LOG_MODULE_REGISTER(security, LOG_LEVEL_INF);

void security_init(void)
{
    LOG_INF("Security subsystem initialized");
}
