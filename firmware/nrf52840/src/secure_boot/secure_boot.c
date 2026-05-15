#include "secure_boot.h"
#include <zephyr/sys/printk.h>

bool secure_boot_validate(void)
{
    printk("Secure Boot Validation (stub)\n");

    // TODO: signature verification of firmware image
    return true;
}
