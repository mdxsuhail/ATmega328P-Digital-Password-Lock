# 🔐 ATmega328P Digital Password Lock

A simple **digital password lock system based on the ATmega328P microcontroller**. The project demonstrates password-based access control using a keypad, LCD display, and LED status indicator.

## 📌 Project Overview

This project implements a basic electronic security system where the user enters a password using a keypad.

The **ATmega328P** processes the entered password and determines whether access should be granted or denied.

A **16×2 LCD (LM016L)** is used to display system messages, while a green LED provides a visual indication of the system state. The circuit diagrams use an ATmega328P, keypad, LCD, LED, and resistors.

## ⚙️ Features

* 🔢 Password entry using keypad
* 🔐 Password-based access control
* 🖥️ 16×2 LCD display
* 💡 LED status indication
* ⚡ ATmega328P-based embedded system
* 🚫 Access control for incorrect passwords
* 🔄 ON/OFF lock-state operation

## 🧩 Hardware Components

| Component         | Quantity |
| ----------------- | -------: |
| ATmega328P        |        1 |
| 16×2 LCD (LM016L) |        1 |
| 4×4 Keypad        |        1 |
| Green LED         |        1 |
| 10 kΩ Resistors   |        2 |
| Power Supply      |        1 |

The circuit diagram identifies the ATmega328P as the main microcontroller and the LM016L as the LCD module.

## 🔄 Working Principle

1. The system is powered on.
2. The ATmega328P initializes the LCD, keypad, and output devices.
3. The LCD prompts the user to enter the password.
4. The user enters the password using the keypad.
5. The ATmega328P compares the entered password with the stored password.
6. If the password is correct, access is granted.
7. If the password is incorrect, access is denied.
8. The LCD displays the corresponding status.
9. The LED indicates the current lock/access state.

## 🖥️ Circuit Diagrams

### 🔓 ON / Access State

The ON-state circuit is provided in:

`on.pdf`

### 🔒 OFF / Locked State

The OFF-state circuit is provided in:

`off.pdf`

## 🏗️ System Architecture

```text
        ┌──────────────────┐
        │     Keypad       │
        └────────┬─────────┘
                 │
                 ▼
        ┌──────────────────┐
        │    ATmega328P    │
        │                  │
        │ Password Check   │
        │ Access Control   │
        └───────┬──────────┘
                │
        ┌───────┴────────┐
        ▼                ▼
┌──────────────┐  ┌──────────────┐
│   16×2 LCD   │  │  LED Status  │
│   Display    │  │  Indicator   │
└──────────────┘  └──────────────┘
```

## 💻 Software

The microcontroller program handles:

* Keypad input
* Password storage
* Password comparison
* LCD control
* Lock/access status
* LED control

## 📂 Repository Structure

```text
ATmega328P-Digital-Password-Lock/
│
├── README.md
├── on.pdf
├── off.pdf
│
├── src/
│   └── main.c
│
└── circuit/
    ├── on.pdf
```

## 🎯 Learning Objectives

This project demonstrates fundamental concepts of:

* Embedded systems
* ATmega328P programming
* Digital I/O
* Keypad interfacing
* LCD interfacing
* Password authentication
* Basic electronic security systems
* Microcontroller-based access control

## 🛠️ Development Tools

Possible development/simulation tools include:

* AVR-GCC
* Microchip/Atmel development tools
* Proteus
* VS Code

## 📊 Project Status

**Status:** Completed — Academic Embedded Systems Project

## 👨‍💻 Author

**Mohammed Suhail**

Electronics and Communication Engineering

---

⭐ If you found this project useful, consider giving the repository a star.
