# SkeletonKey

**SkeletonKey** is a security-first hardware and firmware platform designed for secure authentication, device control, and future AI-assisted identity systems. It is built around a custom embedded system architecture using the nRF52840 SoC and a modular secure hardware stack.

---

## 🔐 Project Vision

SkeletonKey is designed to become a unified secure access system combining:

- Hardware-backed identity (Secure Element)
- Multi-protocol communication (BLE, USB, NFC)
- Secure credential storage and cryptographic operations
- Future AI-assisted authentication and policy control

The system is designed with **security-first principles**, ensuring that sensitive operations always occur in trusted hardware components.

---

## 🧠 Core Design Principles

- **Zero-trust by default**
- **Hardware-rooted security**
- **Modular architecture (replaceable subsystems)**
- **Minimal attack surface**
- **Deterministic firmware behavior**
- **Auditability and reproducibility**

---

## 🧩 System Architecture

SkeletonKey is composed of layered hardware and firmware components:

### 🔧 Core MCU
- **nRF52840-QIAA-R7**
  - BLE 5.x
  - USB 2.0 Full Speed
  - ARM Cortex-M4F

### 🔐 Secure Element
- **Microchip ATECC608A**
  - Hardware key storage
  - ECDSA / ECDH operations
  - Secure provisioning support

### 💾 Secure Storage
- **Winbond W25N01 (1Gb NAND Flash)**
  - Encrypted vault storage
  - Credential and configuration persistence

### 📡 NFC Interface
- **NXP PN7150**
  - NFC Type 2/4 support
  - Mobile device interaction layer

### 🔌 Connectivity
- USB-C (data + power)
- BLE (primary wireless interface)
- NFC (proximity authentication)

---

## 🧱 Firmware Stack

Built on **nRF Connect SDK (NCS)**

### Enabled Components (Initial Baseline)

- BLE stack (SoftDevice Controller / Zephyr BLE)
- USB device stack (HID + CDC support)
- I2C drivers (Secure Element + NFC + Flash)
- Flash storage (FAT / custom encrypted FS layer)
- Crypto integration (CryptoAuthLib for ATECC608A)

---

## 📂 Repository Structure
