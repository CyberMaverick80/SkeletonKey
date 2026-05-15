#include "identity.h"
#include "rot/rot.h"
#include <string.h>

static char device_id[32];

void identity_init(void)
{
    uint8_t entropy[16];
    rot_get_random(entropy, sizeof(entropy));

    // Simple placeholder derivation (replace with real crypto later)
    for (int i = 0; i < 16; i++) {
        sprintf(&device_id[i * 2], "%02X", entropy[i]);
    }
}

const char *identity_get_device_id(void)
{
    return device_id;
}
