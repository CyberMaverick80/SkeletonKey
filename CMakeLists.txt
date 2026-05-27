cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(SkeletonKey)

# =========================================================
# Include directories
# =========================================================

target_include_directories(app PRIVATE
    .
    include
)

# =========================================================
# Main application
# =========================================================

target_sources(app PRIVATE
    src/main.c
)

# =========================================================
# Core systems
# =========================================================

target_sources(app PRIVATE
    core/core.c
    security/security.c
    security/firmware_update.c
    security/enforcement.c
)

# =========================================================
# Secure UI subsystem
# =========================================================

target_sources(app PRIVATE
    secure_ui/secure_ui.c
    secure_ui/secure_ui_renderer.c
    secure_ui/secure_ui_state.c
    secure_ui/secure_ui_events.c
    secure_ui/secure_ui_screens.c
)

# =========================================================
# Secure input subsystem
# =========================================================

target_sources(app PRIVATE
    input/secure_input.c
    input/secure_input_events.c
    input/secure_input_queue.c
)

# =========================================================
# Authentication subsystem
# =========================================================

target_sources(app PRIVATE
    security/auth/auth_state_machine.c
    security/auth/auth_session.c
    security/auth/auth_lockout.c
)

# =========================================================
# Session security enforcement
# =========================================================

target_sources(app PRIVATE
    security/session/session_guard.c
    security/session/session_timeout.c
    security/session/session_validation.c
)

# =========================================================
# PIN authentication subsystem
# =========================================================

target_sources(app PRIVATE
    security/auth/pin/pin_manager.c
)

# =========================================================
# HAL layer
# =========================================================

target_sources(app PRIVATE
    hal/display/display_hal.c
    hal/display/display_backend_sim.c

    hal/input/input_hal.c

    hal/usb/usb_hal.c

    hal/storage/storage_hal.c

    hal/feedback/feedback_hal.c
)

# =========================================================
# Communication & services
# =========================================================

target_sources(app PRIVATE
    usb/usb.c
    ui/ui.c
    storage/storage.c
    events/events.c
)

# =========================================================
# State & session systems
# =========================================================

target_sources(app PRIVATE
    state/state.c
    session/session.c
    auth/auth.c
)

# =========================================================
# Policy engine
# =========================================================

target_sources(app PRIVATE
    policy/policy.c
    policy/policy_engine.c
    policy/policy_rule_engine.c
)

# =========================================================
# Crypto & secure storage
# =========================================================

target_sources(app PRIVATE
    crypto/crypto_service.c
    secure_storage/secure_storage.c
)

# =========================================================
# Identity & trust systems
# =========================================================

target_sources(app PRIVATE
    key/key_manager.c
    trust/trust.c
)
