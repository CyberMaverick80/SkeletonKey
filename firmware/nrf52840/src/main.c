#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

void main(void)
{
    printk("SkeletonKey NRF52840 Secure Node Booting...\n");

    while (1) {
        printk("Secure heartbeat: NRF52840 active\n");
        k_sleep(K_SECONDS(5));
    }
}
