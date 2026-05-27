#ifndef POLICY_H
#define POLICY_H

#include <stdbool.h>

typedef enum {

    POLICY_OP_UNLOCK = 0,
    POLICY_OP_USB_ACCESS,
    POLICY_OP_STORAGE_ACCESS,
    POLICY_OP_FACTORY_RESET,
    POLICY_OP_FIRMWARE_UPDATE

} policy_operation_t;

void policy_init(void);

bool policy_is_allowed(policy_operation_t operation);

const char *policy_operation_to_string(
    policy_operation_t operation);

#endif
