#ifndef POLICY_ENGINE_H
#define POLICY_ENGINE_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* =========================
 * Policy Decisions
 * ========================= */

typedef enum {
    POLICY_DENY = 0,
    POLICY_ALLOW = 1
} policy_decision_t;

/* =========================
 * Policy Actions
 * ========================= */

typedef enum {
    POLICY_ACTION_USB_ACCESS = 0,
    POLICY_ACTION_KEY_GENERATION,
    POLICY_ACTION_FIRMWARE_UPDATE
} policy_action_t;

/* =========================
 * Engine Lifecycle
 * ========================= */

void policy_engine_init(void);

void policy_engine_refresh(void);

/* =========================
 * Policy Evaluation
 * ========================= */

policy_decision_t
policy_engine_evaluate(policy_action_t action);

#ifdef __cplusplus
}
#endif

#endif /* POLICY_ENGINE_H */
