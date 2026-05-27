#include "interface.h"
#include <zephyr/sys/printk.h>

void interface_init(void)
{
    printk("Interface Layer Initialized (stub)\n");
}

void interface_process(void)
{
    // Future: authenticated command handling
}
