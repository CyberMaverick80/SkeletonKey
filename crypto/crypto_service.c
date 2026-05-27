#include <string.h>

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/random/random.h>

#include "crypto_service.h"

LOG_MODULE_REGISTER(crypto_service, LOG_LEVEL_INF);

void crypto_service_init(void)
{
    LOG_INF("Cryptographic service initialized");
}

int crypto_random_generate(
    uint8_t *buffer,
    size_t length)
{
    if (!buffer || length == 0) {

        return -1;
    }

    sys_rand_get(buffer, length);

    LOG_INF("Generated %d bytes of random data",
        (int)length);

    return 0;
}

int crypto_hash_data(
    const uint8_t *input,
    size_t input_len,
    uint8_t *output,
    size_t output_len)
{
    if (!input || !output) {

        return -1;
    }

    /*
     * Placeholder hash implementation.
     * Real SHA-256 integration comes later.
     */

    memset(output, 0xAA, output_len);

    LOG_INF("Data hashing completed");

    return 0;
}
