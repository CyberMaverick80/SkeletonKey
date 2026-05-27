#include <zephyr/logging/log.h>

#include "hal/feedback_hal.h"

LOG_MODULE_REGISTER(feedback_hal, LOG_LEVEL_INF);

void feedback_hal_init(void)
{
    LOG_INF("Feedback HAL initialized");
}
