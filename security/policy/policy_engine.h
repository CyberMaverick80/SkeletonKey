#ifndef POLICY_ENGINE_H
#define POLICY_ENGINE_H

#include <stdint.h>

typedef enum {
    POLICY_USB_ACCESS,
    POLICY_KEY_GENERATION,
    POLICY_FIRMWARE_UPDATE
} policy_request_t;

typedef enum {
    POLICY_DENY = 0,
    POLICY_ALLOW = 1
} policy_decision_t;

/* Core API */
policy_decision_t policy_evaluate(policy_request_t request);

/* Optional future hooks */
void policy_init(void);

#endif
