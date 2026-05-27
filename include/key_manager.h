#ifndef KEY_MANAGER_H
#define KEY_MANAGER_H

#include <stdint.h>

typedef enum {
    KEY_TYPE_DEVICE,
    KEY_TYPE_USER,
} key_type_t;

typedef uint32_t key_id_t;

void key_manager_init(void);

/* FIXED: takes a type */
key_id_t key_manager_generate(key_type_t type);

int key_manager_persist(key_id_t key);

#endif
