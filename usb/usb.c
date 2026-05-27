#include <zephyr/logging/log.h>
#include "usb.h"

LOG_MODULE_REGISTER(usb, LOG_LEVEL_INF);

void usb_init(void)
{
    LOG_INF("USB subsystem initialized");
}
