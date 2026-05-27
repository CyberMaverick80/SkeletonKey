#include <zephyr/logging/log.h>

#include "hal/usb_hal.h"

LOG_MODULE_REGISTER(usb_hal, LOG_LEVEL_INF);

void usb_hal_init(void)
{
    LOG_INF("USB HAL initialized");
}
