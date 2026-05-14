# SkeletonKey Master Specification (v1.0)

## Document 03 — Security Model

---

## 1. Security Objectives

### Confidentiality
- Credentials cannot be extracted even if device is stolen or storage is removed

### Integrity
- Data and firmware cannot be modified undetected

### Authentication Assurance
- Only authenticated users can unlock the device

### Device Identity Integrity
- Each device is cryptographically unique and unclonable

### Session Isolation
- Sessions are short-lived and fully cleared after use

---

## 2. Non-Guarantees

- No protection against malicious signed firmware
- No protection against nation-state invasive hardware attacks
- No protection if user reveals PIN
- No protection from compromised host after credential injection

---

## 3. Threat Model

### Level 1 — Opportunistic
- Device theft, PIN guessing  
Defense: encryption, lockout

### Level 2 — Technical
- Flash dumping, replay attempts  
Defense: ATECC, encrypted vault, nonce usage

### Level 3 — Advanced
- Side-channel, glitch attacks  
Defense: secure element, ephemeral keys

### Level 4 — Nation-State
- Chip-level attacks  
Reality: resistance only

---

## 4. Root of Trust

ATECC608B secure element

### Key Hierarchy
Device Root Key → Device Binding Key → VEK → Record Keys

Rule: Keys are derived, never stored

---

## 5. Authentication Model

### Factors
- Fingerprint (primary)
- PIN (fallback)

### PIN Security
- Hashed/derived validation
- Rate limited with lockout

### Biometric
- Match-only response
- No raw storage

---

## 6. Session Security

- Created after authentication
- Bound to interface and time
- Stored in RAM only
- Destroyed on timeout or tamper

---

## 7. Data Protection

### At Rest
- AES-256-GCM encryption
- Per-record keys

### In Memory
- Temporary only
- Zeroized after use

---

## 8. Interface Security

### USB
- Treated as hostile

### BLE
- Encrypted, limited commands

### NFC
- Trigger only

---

## 9. Anti-Attack Mechanisms

- Replay protection (nonces)
- Brute force limits
- Tamper detection and response
- Debug interface disabled

---

## 10. Secure Boot

ROM → Bootloader → Firmware

- Signed firmware only
- Anti-rollback enforced

---

## 11. Failure Handling

- Fail secure
- Lock on error
- Abort on integrity issues

---

## 12. Worst-Case Scenarios

- Stolen device → encrypted
- Storage removed → unusable
- Firmware dumped → no keys
- Compromised host → post-injection risk

---

## 13. Design Principles

- Zero trust
- Minimal attack surface
- Derive keys
- Encrypt everything
- Zeroize memory
- Fail closed
