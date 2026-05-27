#include <zephyr/logging/log.h>
#include "storage.h"

LOG_MODULE_REGISTER(storage, LOG_LEVEL_INF);

void storage_init(void)
{
    LOG_INF("Storage subsystem initialized");
}
