#ifndef TRUST_H
#define TRUST_H

#include <stdint.h>
#include <stddef.h>

void trust_init(void);

int trust_verify_boot(const uint8_t *runtime_hash,
                      const uint8_t *expected_hash,
                      size_t len);

#endif /* TRUST_H */
