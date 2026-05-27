#include <string.h>

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#include "auth.h"

LOG_MODULE_REGISTER(auth, LOG_LEVEL_INF);

#define MAX_AUTH_ATTEMPTS 3

static const char *valid_pin = "1234";

static int remaining_attempts = MAX_AUTH_ATTEMPTS;

static bool locked_out = false;

void auth_init(void)
{
    LOG_INF("Authentication framework initialized");
}

bool auth_verify_pin(const char *pin)
{
    if (locked_out) {

        LOG_ERR("Authentication locked out");

        return false;
    }

    if (strcmp(pin, valid_pin) == 0) {

        LOG_INF("PIN authentication successful");

        remaining_attempts = MAX_AUTH_ATTEMPTS;

        return true;
    }

    remaining_attempts--;

    LOG_WRN("Invalid PIN (%d attempts remaining)",
        remaining_attempts);

    if (remaining_attempts <= 0) {

        locked_out = true;

        LOG_ERR("Authentication lockout triggered");
    }

    return false;
}

int auth_remaining_attempts(void)
{
    return remaining_attempts;
}

bool auth_is_locked_out(void)
{
    return locked_out;
}
