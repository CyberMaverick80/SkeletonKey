# SkeletonKey Master Specification (v1.0)

## Document 02 — System Architecture

---

## 1. High-Level Architecture Overview

SkeletonKey consists of five core layers:

User Interaction Layer  
↓  
Interface Layer (USB / BLE / NFC)  
↓  
Execution Layer (State Machine + Arbitration)  
↓  
Security Layer (Crypto + ATECC)  
↓  
Storage Layer (Encrypted Vault)

---

## 2. Core System Components

### MCU (nRF52840)
- Central controller
- Runs Zephyr / NCS firmware
- Manages interfaces, state machine, crypto coordination

### Secure Element (ATECC608B)
- Hardware root of trust
- Stores device root keys and FIDO keys
- Performs key derivation and signing

### External Storage (W25N01GV SPI NAND)
- Stores encrypted vault
- No plaintext secrets ever stored

### Interfaces

#### USB (Primary)
- HID keyboard injection
- Highest priority interface

#### BLE (Secondary)
- GATT communication
- Management + optional interaction

#### NFC (Intent Trigger)
- Tap-based interaction
- Initiates unlock/authentication

### Power System
- 3.7V LiPo battery
- Charging + regulation

### Tamper Sensors
- Hall sensor
- Voltage anomaly detection
- Debug interface monitoring

---

## 3. Trust Boundaries

### Trusted
- ATECC608B
- Derived keys
- Decrypted credentials (temporary)
- Secure firmware paths

### Untrusted
- USB hosts
- BLE clients
- NFC readers
- External input

---

## 4. Data Flow

### Unlock Flow
User Input → Auth Manager → Security Core → ATECC → Key Derivation → Vault Validation → UNLOCKED

### Credential Retrieval
Select Record → Derive Record Key → Decrypt (AES-GCM) → Return Credential

### USB Injection
Credential → Interface Manager → HID Output

### TOTP Flow
Extract Secret → Generate Code → Output

### FIDO2 Flow
Challenge → ATECC Sign → Response

---

## 5. Interface Arbitration

### Priority
1. USB
2. NFC
3. BLE

### Rules
- Only one active interface
- USB overrides others
- BLE denied during active sessions

---

## 6. Execution Layer

### Components
- Auth Manager
- Arbitration Engine
- Session Manager

### Responsibilities
- State control
- Interface control
- Session lifecycle

---

## 7. Security Layer

- Key derivation
- Encryption/decryption
- ATECC interface
- Memory zeroization

---

## 8. Storage Layer

### Structure
VEK → HKDF → Record Key → AES-GCM encrypted record

### Notes
- Each record independently encrypted
- No plaintext indexing

---

## 9. Firmware Trust Chain

### Boot
ROM → Bootloader Verify → Firmware Verify → Execute

### Updates
Verify Signature → Check Version → Install → Reboot

---

## 10. Failure & Attack Handling

- PIN failures → lockout
- Tamper → zeroize + lock
- Vault corruption → reject unlock

---

## 11. System Constraints

- Offline capable
- Host not trusted
- Deterministic behavior
- Safe failure recovery
