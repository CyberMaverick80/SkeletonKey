#include <zephyr/logging/log.h>

#include "hal/storage_hal.h"

LOG_MODULE_REGISTER(storage_hal, LOG_LEVEL_INF);

void storage_hal_init(void)
{
    LOG_INF("Storage HAL initialized");
}
