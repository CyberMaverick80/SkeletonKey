# SkeletonKey Formal Architecture Document (v1.0)

## 1. System Overview

SkeletonKey is a security-first embedded system designed around a single trusted hardware root-of-trust: the entity["product","nRF52840","Nordic Semiconductor Bluetooth LE SoC with ARM Cortex-M4 and cryptographic hardware"]. The system prioritizes minimal attack surface, deterministic trust boundaries, and hardware-backed identity operations.

The architecture is intentionally minimal, avoiding distributed compute nodes to reduce complexity and eliminate cross-device trust assumptions.

---

## 2. Design Principles

### 2.1 Security-First Design

* Security is the primary system constraint, not a feature layer.
* All system behaviors must be traceable to explicit trust assumptions.
* No implicit trust between subsystems.

### 2.2 Minimal Attack Surface

* Single compute and decision-making core.
* No secondary microcontrollers or external runtime dependencies in the base architecture.

### 2.3 Hardware Root of Trust

* All identity and cryptographic operations originate from the nRF52840 secure-capable hardware environment.
* Keys are never assumed to exist outside secure storage boundaries.

### 2.4 Deterministic Trust Boundaries

* Every subsystem has explicitly defined trust levels.
* No component communicates without defined protocol expectations.

---

## 3. Hardware Architecture

### 3.1 Primary Compute Unit

* Device: entity["product","nRF52840","Nordic Semiconductor nRF52840 SoC"]
* Role: Root of Trust (RoT)
* Responsibilities:

  * Identity generation and storage
  * Cryptographic operations
  * Secure boot execution
  * System state enforcement
  * Peripheral control (if applicable)

### 3.2 Removed Components

* ESP32 subsystem removed to reduce attack surface and eliminate multi-node trust complexity.

---

## 4. Firmware Architecture

### 4.1 Directory Structure

```
firmware/
├── nrf52840/      # Core trusted firmware
└── common/        # Shared security and protocol definitions
```

### 4.2 nRF52840 Firmware Responsibilities

* Secure boot initialization
* Device identity provisioning
* Cryptographic key handling
* System state machine
* Secure communication interface (future expansion)

### 4.3 Common Layer Responsibilities

* Protocol definitions
* Message schemas
* Cryptographic interface abstractions
* System-wide constants

---

## 5. Trust Model

### 5.1 Root of Trust Definition

The system trusts only the execution environment of the nRF52840. All other logic is subordinate to it.

### 5.2 Identity Model

* Each device instance possesses a unique cryptographic identity.
* Identity is bound to hardware-backed key storage.
* Identity cannot be exported in raw form.

### 5.3 Authentication Model

* All external interactions must be authenticated through hardware-backed cryptographic verification.
* No unauthenticated command execution is permitted in final system design.

---

## 6. Security Model

### 6.1 Threat Model Assumptions

* Physical access is considered a high-risk vector.
* Firmware integrity must be verifiable at boot.
* External interfaces are untrusted by default.

### 6.2 Key Management

* Keys are generated internally on first secure boot.
* Keys are stored in hardware-backed secure regions where available.
* No plaintext key export is permitted.

### 6.3 Secure Boot Concept

* Boot chain must validate firmware integrity before execution.
* Failure to validate results in halted or recovery state.

---

## 7. Communication Model (Future Phase)

* External communication layer is not yet implemented.
* All future protocols must conform to authenticated and encrypted transport expectations.
* No unauthenticated inbound command paths will be permitted.

---

## 8. Build System (Planned)

* Primary target: Zephyr RTOS
* Toolchain: ARM GCC or Zephyr SDK
* Build configuration isolated per hardware target

---

## 9. System State Machine (Conceptual)

1. Boot
2. Hardware initialization
3. Secure validation
4. Identity loading / generation
5. Operational state
6. Locked state (on failure or tamper detection)

---

## 10. Versioning

* v1.0: Initial formal architecture definition (nRF52840-only system)

---

## 11. Future Extensions (Controlled Scope)

* Secure display integration
* External authentication interfaces
* Secure backup / recovery mechanisms
* Optional expansion modules (strictly authenticated)

---

End of Document
