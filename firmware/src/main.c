#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

int main(void)
{
    printk("SkeletonKey firmware booted successfully.\n");

    while (1) {
        k_sleep(K_SECONDS(5));
        printk("SkeletonKey heartbeat...\n");
    }

    return 0;
}
