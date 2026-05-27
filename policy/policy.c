#include <zephyr/logging/log.h>

#include "policy.h"
#include "session.h"
#include "state.h"

LOG_MODULE_REGISTER(policy, LOG_LEVEL_INF);

void policy_init(void)
{
    LOG_INF("Policy engine initialized");
}

bool policy_is_allowed(policy_operation_t operation)
{
    LOG_INF("Policy check: %s",
        policy_operation_to_string(operation));

    switch (operation) {

    case POLICY_OP_UNLOCK:

        return true;

    case POLICY_OP_USB_ACCESS:

        return session_is_active();

    case POLICY_OP_STORAGE_ACCESS:

        return session_is_active();

    case POLICY_OP_FACTORY_RESET:

        return false;

    case POLICY_OP_FIRMWARE_UPDATE:

        return state_get() == STATE_UNLOCKED;

    default:

        return false;
    }
}

const char *policy_operation_to_string(
    policy_operation_t operation)
{
    switch (operation) {

    case POLICY_OP_UNLOCK:
        return "UNLOCK";

    case POLICY_OP_USB_ACCESS:
        return "USB_ACCESS";

    case POLICY_OP_STORAGE_ACCESS:
        return "STORAGE_ACCESS";

    case POLICY_OP_FACTORY_RESET:
        return "FACTORY_RESET";

    case POLICY_OP_FIRMWARE_UPDATE:
        return "FIRMWARE_UPDATE";

    default:
        return "UNKNOWN";
    }
}
