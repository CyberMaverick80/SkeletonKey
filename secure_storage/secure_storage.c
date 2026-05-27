#include <string.h>

#include <zephyr/logging/log.h>

#include "secure_storage.h"

LOG_MODULE_REGISTER(secure_storage, LOG_LEVEL_INF);

/*
 * Temporary in-memory secure storage.
 * Real encrypted persistence comes later.
 */

static uint8_t storage_buffer[256];

int secure_storage_init(void)
{
    memset(storage_buffer, 0, sizeof(storage_buffer));

    LOG_INF("Secure storage initialized");

    return 0;
}

int secure_storage_write(
    const char *key,
    const uint8_t *data,
    size_t length)
{
    ARG_UNUSED(key);

    if (!data || length > sizeof(storage_buffer)) {

        return -1;
    }

    memcpy(storage_buffer, data, length);

    LOG_INF("Secure storage write complete");

    return 0;
}

int secure_storage_read(
    const char *key,
    uint8_t *buffer,
    size_t length)
{
    ARG_UNUSED(key);

    if (!buffer || length > sizeof(storage_buffer)) {

        return -1;
    }

    memcpy(buffer, storage_buffer, length);

    LOG_INF("Secure storage read complete");

    return 0;
}
