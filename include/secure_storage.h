#ifndef SECURE_STORAGE_H
#define SECURE_STORAGE_H

#include <stddef.h>
#include <stdint.h>

int secure_storage_init(void);

int secure_storage_write(
    const char *key,
    const uint8_t *data,
    size_t length);

int secure_storage_read(
    const char *key,
    uint8_t *buffer,
    size_t length);

#endif
