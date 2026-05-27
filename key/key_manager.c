#include <string.h>
#include <zephyr/logging/log.h>

#include "key_manager.h"
#include "secure_storage.h"
#include "crypto_service.h"

LOG_MODULE_REGISTER(key_manager, LOG_LEVEL_INF);

/* Simple in-memory key registry for now */
#define MAX_KEYS 8

typedef struct {
    key_id_t id;
    key_type_t type;
    uint8_t material[32];
    int in_use;
} key_entry_t;

static key_entry_t key_store[MAX_KEYS];

static key_id_t next_id = 1;

void key_manager_init(void)
{
    // initialization logic

}

key_id_t key_manager_generate(key_type_t type)
{
    key_id_t id = next_id++;

    // TODO: real key generation logic
    return id;
}

int key_sign(key_id_t key,
             const uint8_t *data,
             size_t len,
             uint8_t *signature,
             size_t sig_len)
{
    ARG_UNUSED(key);

    if (!data || !signature || sig_len < 32) {
        return -1;
    }

    /* Placeholder signing using hash (upgrade later to real crypto) */
    return crypto_hash_data(data, len, signature, sig_len);
}

int key_get_public_hash(key_id_t key,
                        uint8_t *out,
                        size_t out_len)
{
    for (int i = 0; i < MAX_KEYS; i++) {

        if (key_store[i].in_use &&
            key_store[i].id == key) {

            return crypto_hash_data(
                key_store[i].material,
                sizeof(key_store[i].material),
                out,
                out_len);
        }
    }

    return -1;
}

int key_manager_persist(key_id_t key)
{
    /* Minimal persistence: store ID only for now */
    return secure_storage_write(
        "key_registry",
        (uint8_t *)&key,
        sizeof(key));
}
