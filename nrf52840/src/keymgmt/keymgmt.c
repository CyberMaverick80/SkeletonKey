#include "keymgmt.h"
#include "rot/rot.h"
#include <zephyr/sys/printk.h>

static uint8_t session_key[32];

void keymgmt_init(void)
{
    printk("Key Management Initialized\n");
    keymgmt_generate_session_key();
}

bool keymgmt_generate_session_key(void)
{
    return rot_get_random(session_key, sizeof(session_key));
}
