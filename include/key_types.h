#ifndef KEY_TYPES_H
#define KEY_TYPES_H

#include <stdint.h>

typedef uint32_t key_id_t;

typedef enum {
    KEY_TYPE_DEVICE,
    KEY_TYPE_SESSION,
    KEY_TYPE_SIGNING
} key_type_t;

#endif
