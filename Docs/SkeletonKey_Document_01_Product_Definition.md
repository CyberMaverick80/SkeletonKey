# SkeletonKey Master Specification (v1.0)

## Document 01 — Product Definition

## 1. Purpose

SkeletonKey is a self-contained hardware security device that:
- Stores credentials entirely on-device
- Authenticates users via biometric + PIN fallback
- Automatically provides credentials to external systems
- Generates and manages 2FA (TOTP) codes
- Acts as a hardware root-of-trust identity token

No cloud dependency. No external password manager required. No unprotected secrets outside the device.

---

## 2. Core Philosophy

### Zero-Trust by Default
Nothing is trusted without cryptographic verification.

### Secrets Never Leave Secure Boundaries
Master keys are hardware-bound via secure element. Vault keys are derived, not stored.

### Offline-First Security
Device functions fully without internet connectivity.

### User Simplicity, Internal Complexity
Single user action (touch/PIN) maps to layered cryptographic operations.

### Deterministic Security Behavior
All operations follow strict state machine transitions.

---

## 3. Core Features (v1 Locked Scope)

### Credential Vault
- Encrypted storage of usernames, passwords, TOTP secrets
- SPI NAND flash (~100MB)

### Authentication
- Primary: Fingerprint
- Fallback: PIN

### USB HID Injection
- Acts as keyboard
- Auto-types credentials and TOTP

### BLE (Secondary)
- Device management and optional interaction

### NFC (Intent Trigger)
- Tap-to-unlock or initiate authentication

### FIDO2 / WebAuthn
- Hardware-backed authentication keys

### Secure Firmware Updates
- Signed firmware only
- Anti-rollback protection

### Tamper Awareness
- Hall sensor + voltage + debug detection
- Response: lock, wipe volatile secrets, optional key destruction

---

## 4. System Roles

- Password Manager
- 2FA Authenticator (TOTP)
- Hardware Security Key (FIDO2)
- Identity Token Device

---

## 5. Supported Platforms

- Windows
- Linux
- macOS
- Android
- iOS

Via:
- USB HID
- BLE
- NFC

---

## 6. Hardware Foundation

### Core Components
- nRF52840-QIAA-R7
- ATECC608B secure element
- W25N01GV SPI NAND
- PN7160 NFC controller
- 3.7V 300mAh LiPo battery

### Interfaces
- USB-C + USB-A
- BLE
- NFC

---

## 7. Non-Goals (v1)

- No cloud sync
- No mobile app dependency
- No WiFi connectivity
- No multi-device sync
- No remote unlock

---

## 8. Security Boundaries

### Trusted Zone
- Secure element (ATECC608B)
- Derived cryptographic keys
- Encrypted vault in protected memory

### Untrusted Zone
- USB/BLE/NFC hosts
- External input sources
- Non-secure firmware components

---

## 9. User Flow

1. Device connection (USB/NFC/BLE)
2. Enter UNLOCK_PENDING
3. User authenticates (fingerprint or PIN)
4. Vault key derived
5. User selects credential
6. Device injects credentials via USB HID
7. Session timeout → lock

---

## 10. MVP Definition

### Required
- PIN authentication
- Encrypted vault storage
- USB HID injection
- TOTP generation
- ATECC integration

### Optional (v1.1)
- Fingerprint
- BLE
- NFC
- FIDO2 expansion
