#ifndef STATE_H
#define STATE_H

typedef enum {
    STATE_BOOT,
    STATE_INITIALIZING,
    STATE_SECURE_CHECK,
    STATE_OPERATIONAL,
    STATE_LOCKED
} system_state_t;

void state_set_operational(void);
void state_set_locked(void);
void state_tick(void);

#endif
