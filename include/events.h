#ifndef EVENTS_H
#define EVENTS_H

typedef enum {
    EVENT_NONE = 0,
    EVENT_SYSTEM_BOOT,
    EVENT_USB_CONNECTED,
    EVENT_USB_DISCONNECTED,
    EVENT_AUTH_SUCCESS,
    EVENT_AUTH_FAILURE,
    EVENT_STORAGE_UNLOCKED
} sk_event_type_t;

typedef struct {
    sk_event_type_t type;
} sk_event_t;

void event_dispatch(sk_event_t *event);

#endif
