# SkeletonKey Master Specification (v1.0)

## Document 04 — Cryptographic Flow

---

# 1. Purpose

Defines the complete cryptographic architecture of SkeletonKey.

This includes:
- key hierarchy,
- encryption standards,
- derivation methods,
- session security,
- randomness generation,
- secure memory handling,
- and hardware-rooted trust.

---

# 2. Security Objectives

The cryptographic architecture must:

- Prevent plaintext secret exposure
- Ensure authenticated encryption
- Prevent replay attacks
- Prevent nonce reuse
- Eliminate persistent derived-key storage
- Bind secrets to hardware identity

---

# 3. Cryptographic Primitives

| Function | Algorithm |
|---|---|
| Hashing | SHA-256 |
| Key Derivation | HKDF-SHA256 |
| Encryption | AES-256-GCM |
| PIN Derivation | PBKDF2 |
| TOTP | RFC6238 |

---

# 4. Key Hierarchy

ATECC Root Key
↓
Device Binding Key
↓
Vault Encryption Key
↓
Record Keys
↓
Session Keys

---

# 5. Encryption Model

Every vault record uses:
- AES-256-GCM
- Unique nonce
- Independent RecordKey

Provides:
- Confidentiality
- Integrity
- Tamper detection

---

# 6. Session Security

Session keys are:
- Ephemeral
- RAM-only
- Destroyed on disconnect

Replay protection uses:
- Session IDs
- Nonces
- Authenticated requests

---

# 7. Randomness Generation

Entropy sources:
- nRF52840 RNG
- ATECC entropy contribution

Used for:
- Nonces
- Session IDs
- Salts

---

# 8. Secure Memory Handling

Sensitive buffers:
- Never logged
- Never cached
- Always zeroized

Example:

```c
secure_zero(buffer, len);
```

---

# 9. Critical Rules

- Never reuse nonces
- Never store derived keys
- Always verify auth tags
- Always zeroize sensitive memory
