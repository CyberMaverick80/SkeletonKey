#include <zephyr/logging/log.h>

#include "hal/input_hal.h"

LOG_MODULE_REGISTER(input_hal, LOG_LEVEL_INF);

void input_hal_init(void)
{
    LOG_INF("Input HAL initialized");
}
