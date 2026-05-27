#ifndef TRUST_H
#define TRUST_H

#include <stdint.h>

typedef enum {
    TRUST_UNKNOWN,
    TRUST_TRUSTED,
    TRUST_DEGRADED,
    TRUST_TAMPERED
} trust_state_t;

int trust_init(void);

/* Simulated boot verification */
trust_state_t trust_verify_boot(void);

/* Query current trust state */
trust_state_t trust_get_state(void);

#endif
