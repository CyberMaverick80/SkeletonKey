# SkeletonKey Trust Model → Firmware Module Mapping (nRF52840) v1.0

## 1. Overview

This document maps the SkeletonKey security trust model directly into a firmware architecture for the nRF52840 platform.

It defines how each trust assumption becomes an actual firmware module, ensuring that the implementation matches the intended security design.

Target hardware:
- nRF52840 secure-capable ARM Cortex-M4 SoC

---

## 2. System Principle

SkeletonKey follows a strict security-first architecture:

- The system has a single Root of Trust (RoT)
- All cryptographic and identity operations originate from hardware-backed capabilities
- No module may bypass security boundaries
- External input is never trusted

---

## 3. Firmware Architecture Overview

### Top-Level Structure

firmware/
├── nrf52840/
│ ├── src/
│ │ ├── rot/
│ │ ├── identity/
│ │ ├── keymgmt/
│ │ ├── secure_boot/
│ │ ├── state/
│ │ └── interface/
└── common/

---

## 4. Module Breakdown

## 4.1 Root of Trust (rot/)

### Purpose
Hardware abstraction layer for all security-critical operations.

### Responsibilities
- Access hardware entropy (TRNG)
- Perform cryptographic operations via hardware support
- Interface with secure key storage (if available)
- Provide device-unique identifiers
- Ensure no raw hardware calls occur outside this module

### Rule
All cryptographic operations must pass through this layer.

---

## 4.2 Identity Module (identity/)

### Purpose
Defines and manages the device’s cryptographic identity.

### Responsibilities
- Generate identity on first secure boot
- Maintain device identity keypair
- Derive device ID from hardware root
- Prevent identity modification after provisioning

### Rule
Device identity is immutable after initialization.

---

## 4.3 Key Management Module (keymgmt/)

### Purpose
Manages all cryptographic keys derived from the root identity.

### Responsibilities
- Derive session keys
- Manage key lifecycle (creation, rotation future)
- Provide secure key handles (not raw keys)
- Enforce zero plaintext key exposure

### Rule
Keys must never exist in raw form in application memory.

---

## 4.4 Secure Boot Module (secure_boot/)

### Purpose
Ensures firmware integrity before system execution.

### Responsibilities
- Validate firmware integrity at boot
- Enforce secure boot chain
- Prevent execution of unverified code
- Trigger lock/recovery state on failure

### Rule
If validation fails, system must not continue boot.

---

## 4.5 System State Machine (state/)

### Purpose
Controls all system execution states.

### States
- BOOT
- INITIALIZING
- SECURE_CHECK
- OPERATIONAL
- LOCKED
- RECOVERY (future)

### Responsibilities
- Control transitions between states
- Enforce state-based access rules
- Prevent unauthorized state changes

### Rule
All system behavior is governed by state.

---

## 4.6 Interface Layer (interface/)

### Purpose
Handles all external communication (future expansion).

### Responsibilities
- Validate all incoming external input
- Enforce authentication before processing commands
- Encrypt and decrypt communication payloads
- Block unauthenticated access paths

### Rule
External input is always untrusted until validated.

---

## 5. Common Security Layer (common/)

### Purpose
Shared definitions used across firmware modules.

### Contains
- Message formats
- Protocol definitions
- Cryptographic schemas
- System constants (non-secret only)

### Rule
This layer must contain no secrets and no hardware calls.

---

## 6. Boot Sequence Flow

The system follows a strict initialization order:

1. Boot execution begins
2. Root of Trust initializes
3. Identity module loads or generates identity
4. Key management initializes derived keys
5. Secure boot validation is enforced
6. State machine enters operational mode
7. Interface layer becomes active (if enabled)

If any step fails:
→ System transitions to LOCKED state

---

## 7. Security Rules (Non-Negotiable)

### Rule 1: No bypass paths
No module may bypass Root of Trust operations.

### Rule 2: No raw key exposure
Cryptographic keys must never be exposed in plaintext outside secure contexts.

### Rule 3: State machine enforcement
All actions must be validated against current system state.

### Rule 4: Interface isolation
External data must never directly influence system logic without validation.

---

## 8. Threat Model Assumptions

- Physical access is considered a high-risk threat
- Firmware tampering must be detectable
- External interfaces are fully untrusted
- Memory exposure is considered a potential attack vector

---

## 9. Design Outcome

This mapping produces a firmware system that is:

- Minimal in attack surface
- Strictly hardware-rooted in trust
- Deterministic in execution flow
- Fully auditable through module separation

---

## 10. Version

v1.0 — Initial trust model to firmware mapping for nRF52840 architecture
