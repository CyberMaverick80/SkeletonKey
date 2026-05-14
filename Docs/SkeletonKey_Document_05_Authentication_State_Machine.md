# SkeletonKey Master Specification (v1.0)

## Document 05 — Authentication State Machine

---

# 1. Purpose

Defines authentication states, transitions, retry behavior, lock logic, and session lifecycle rules.

---

# 2. Authentication Philosophy

The authentication system must:
- Fail securely
- Resist brute-force attacks
- Prevent unauthorized persistence
- Enforce deterministic transitions

---

# 3. Core States

| State | Description |
|---|---|
| LOCKED | Device inaccessible |
| AUTH_IN_PROGRESS | Authentication underway |
| UNLOCKED | Authentication successful |
| SESSION_ACTIVE | Protected session active |
| LOCKOUT | Retry delay enforced |
| TAMPER_RESPONSE | Tamper-triggered response |

---

# 4. State Transition Flow

LOCKED
↓
AUTH_IN_PROGRESS
↓
UNLOCKED
↓
SESSION_ACTIVE
↓
LOCKED

---

# 5. Retry Protection

Repeated failures trigger:
- Increasing retry delays
- Temporary lockout
- Security event logging

---

# 6. Timeout Handling

Timeout events:
- Destroy session keys
- Zeroize buffers
- Return device to LOCKED

---

# 7. Critical Rules

- No persistent sessions
- No hidden unlock states
- No authentication bypasses
- All failures fail closed
