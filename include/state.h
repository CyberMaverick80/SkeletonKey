#ifndef STATE_H
#define STATE_H

#ifdef __cplusplus
extern "C" {
#endif

/* =========================================================
 * SYSTEM STATE DEFINITIONS
 * ========================================================= */

typedef enum {

    STATE_BOOT = 0,
    STATE_LOCKED,
    STATE_AUTH_REQUIRED,
    STATE_UNLOCKED,
    STATE_RECOVERY,
    STATE_TAMPER

} sk_state_t;

/* =========================================================
 * STATE MANAGEMENT API
 * ========================================================= */

void state_init(void);

void state_set(sk_state_t new_state);

sk_state_t state_get(void);

const char *state_to_string(sk_state_t state);

#ifdef __cplusplus
}
#endif

#endif /* STATE_H */
