#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#include <stdbool.h>
#include <stdint.h>

/* =========================================================
 * CORE SUBSYSTEMS
 * ========================================================= */

#include "core.h"
#include "security.h"
#include "usb.h"
#include "ui.h"
#include "storage.h"

/* =========================================================
 * EVENT SYSTEM
 * ========================================================= */

#include "events.h"

/* =========================================================
 * HAL LAYER
 * ========================================================= */

#include "hal/display_hal.h"
#include "hal/input_hal.h"
#include "hal/usb_hal.h"
#include "hal/storage_hal.h"
#include "hal/feedback_hal.h"

/* =========================================================
 * SYSTEM SERVICES
 * ========================================================= */

#include "state.h"
#include "session.h"
#include "auth.h"
#include "secure_ui.h"
#include "policy.h"
#include "crypto_service.h"
#include "secure_storage.h"
#include "key_manager.h"
#include "trust.h"

/* =========================================================
 * SECURE INPUT SUBSYSTEM
 * ========================================================= */

#include "input/secure_input.h"
#include "input/secure_input_queue.h"
#include "input/secure_input_types.h"

/* =========================================================
 * SECURITY FLOWS
 * ========================================================= */

#include "security/firmware_update.h"

#include "security/auth/pin/pin_manager.h"
#include "security/auth/auth_session.h"
#include "security/auth/auth_lockout.h"
#include "security/auth/auth_state_machine.h"

/* =========================================================
 * POLICY ENGINE
 * ========================================================= */

#include "policy_engine.h"

LOG_MODULE_REGISTER(system, LOG_LEVEL_INF);

/* =========================================================
 * POLICY ENFORCEMENT
 * ========================================================= */

static bool policy_allow_action(policy_action_t action)
{
    policy_decision_t decision =
        policy_engine_evaluate(action);

    if (decision == POLICY_ALLOW) {
        return true;
    }

    LOG_WRN("Policy denied action: %d", action);

    return false;
}

/* =========================================================
 * SECURITY FLOWS
 * ========================================================= */

static void system_usb_flow(void)
{
    if (!policy_allow_action(POLICY_ACTION_USB_ACCESS)) {
        return;
    }

    LOG_INF("Initializing USB subsystem");

    usb_init();

    LOG_INF("USB subsystem enabled");
}

static void system_key_generation_flow(void)
{
    if (!policy_allow_action(POLICY_ACTION_KEY_GENERATION)) {
        return;
    }

    key_id_t key_id =
        key_manager_generate(KEY_TYPE_DEVICE);

    LOG_INF("Device key generated: %u", key_id);
}

static void system_firmware_flow(void)
{
    if (!policy_allow_action(POLICY_ACTION_FIRMWARE_UPDATE)) {
        return;
    }

    LOG_INF("Firmware update permitted");

    firmware_update_start();
}

/* =========================================================
 * AUTHENTICATION FLOW
 * ========================================================= */

static bool authenticate_demo_user(void)
{
    char entered_pin[] = "1234";

    if (auth_lockout_is_locked()) {

        LOG_WRN("Authentication locked out");

        return false;
    }

    bool authenticated =
        pin_manager_verify(entered_pin);

    pin_manager_clear_buffer(
        entered_pin,
        sizeof(entered_pin)
    );

    if (authenticated) {

        LOG_INF("PIN verified");

        auth_session_start();

        auth_state_transition(
            AUTH_STATE_AUTHENTICATED
        );

        return true;
    }

    LOG_WRN("Invalid PIN");

    auth_lockout_increment();

    auth_state_transition(
        AUTH_STATE_FAILED
    );

    return false;
}

/* =========================================================
 * MAIN
 * ========================================================= */

int main(void)
{
    LOG_INF("=== SkeletonKey Firmware Boot ===");

    /* -------------------------------------------------
     * Core initialization
     * ------------------------------------------------- */

    core_init();
    security_init();
    storage_init();
    ui_init();

    /* -------------------------------------------------
     * Secure UI
     * ------------------------------------------------- */

    secure_ui_init();

    /* -------------------------------------------------
     * Secure Input
     * ------------------------------------------------- */

    secure_input_init();

    /* -------------------------------------------------
     * State system
     * ------------------------------------------------- */

    state_init();

    /* -------------------------------------------------
     * Policy engine
     * ------------------------------------------------- */

    policy_engine_init();

    /* -------------------------------------------------
     * Authentication systems
     * ------------------------------------------------- */

    pin_manager_init();

    auth_session_init();

    auth_lockout_init();

    auth_state_machine_init();

    /* -------------------------------------------------
     * Session system
     * ------------------------------------------------- */

    session_init();

    /* -------------------------------------------------
     * Initial UI state
     * ------------------------------------------------- */

    state_set(STATE_LOCKED);

    secure_ui_show_locked();

    k_sleep(K_SECONDS(2));

    state_set(STATE_AUTH_REQUIRED);

    secure_ui_show_auth();

    k_sleep(K_SECONDS(2));

    /* -------------------------------------------------
     * Demo authentication flow
     * ------------------------------------------------- */

    if (authenticate_demo_user()) {

        session_start();

        secure_ui_show_home();

    } else {

        secure_ui_show_locked();
    }

    /* -------------------------------------------------
     * Boot event
     * ------------------------------------------------- */

    sk_event_t boot_event = {
        .type = EVENT_SYSTEM_BOOT
    };

    event_dispatch(&boot_event);

    /* -------------------------------------------------
     * Security flows
     * ------------------------------------------------- */

    system_usb_flow();

    system_key_generation_flow();

    system_firmware_flow();

    LOG_INF("System initialization complete");

    /* =================================================
     * Runtime loop
     * ================================================= */

    while (1) {

        /* ---------------------------------------------
         * Simulated secure input events
         * --------------------------------------------- */

        secure_input_queue_push(
            SECURE_INPUT_EVENT_UNLOCK
        );

        secure_input_process();

        k_sleep(K_SECONDS(2));

        secure_input_queue_push(
            SECURE_INPUT_EVENT_LOCK
        );

        secure_input_process();

        k_sleep(K_SECONDS(2));

        /* ---------------------------------------------
         * Session management
         * --------------------------------------------- */

        if (session_is_active()) {

            LOG_INF("Secure session active");

            session_refresh();

            policy_engine_refresh();

        } else {

            LOG_WRN("No active session");
        }

        k_sleep(K_SECONDS(1));
    }

    return 0;
}
