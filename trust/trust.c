#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <string.h>
#include "trust.h"

LOG_MODULE_REGISTER(trust, LOG_LEVEL_INF);

void trust_init(void)
{
    LOG_INF("Trust system initialized");
}

int trust_verify_boot(const uint8_t *runtime_hash,
                      const uint8_t *expected_hash,
                      size_t len)
{
    if (memcmp(runtime_hash, expected_hash, len) == 0) {
        LOG_INF("Boot trust: TRUSTED");
        return 1;
    }

    LOG_ERR("Boot trust: TAMPERED");
    return -1;
}
