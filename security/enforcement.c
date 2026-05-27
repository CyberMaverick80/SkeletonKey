#include "security/enforcement.h"
#include "state.h"

#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(enforcement, LOG_LEVEL_INF);

void enforcement_init(void)
{
    LOG_INF("Hard Security Enforcement Layer initialized");
}

/* Internal helper */
static bool is_unlocked(void)
{
    return (state_get() == STATE_UNLOCKED);
}

bool enforcement_is_locked(void)
{
    return !is_unlocked();
}

sec_result_t enforcement_check_usb(void)
{
    if (!is_unlocked()) {
        LOG_WRN("USB access denied: device not unlocked");
        return SEC_DENY;
    }

    LOG_INF("USB access permitted");
    return SEC_ALLOW;
}

sec_result_t enforcement_check_keygen(void)
{
    if (state_get() == STATE_LOCKED ||
        state_get() == STATE_TAMPER) {

        LOG_ERR("Key generation blocked by security state");
        return SEC_DENY;
    }

    LOG_INF("Key generation permitted");
    return SEC_ALLOW;
}

sec_result_t enforcement_check_firmware_update(void)
{
    if (state_get() != STATE_UNLOCKED) {
        LOG_WRN("Firmware update denied: insecure state");
        return SEC_DENY;
    }

    LOG_INF("Firmware update permitted");
    return SEC_ALLOW;
}
