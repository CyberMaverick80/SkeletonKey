#include "rot.h"
#include <zephyr/random/rand32.h>

void rot_init(void)
{
    // Placeholder for hardware security init
}

bool rot_get_random(uint8_t *buf, size_t len)
{
    if (!buf) return false;

    sys_rand_get(buf, len);
    return true;
}
