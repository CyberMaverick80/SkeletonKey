#ifndef CRYPTO_SERVICE_H
#define CRYPTO_SERVICE_H

#include <stddef.h>
#include <stdint.h>

void crypto_service_init(void);

int crypto_random_generate(
    uint8_t *buffer,
    size_t length);

int crypto_hash_data(
    const uint8_t *input,
    size_t input_len,
    uint8_t *output,
    size_t output_len);

#endif
