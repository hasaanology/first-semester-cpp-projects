# Bitwise Security Controller Decoder

## Overview
This project simulates a digital security controller that monitors exhibition rooms in a museum[cite: 5]. Instead of transmitting individual sensor readings, the system packs multiple security states into a single integer payload called `roomSignal`[cite: 5]. This program decodes that integer and evaluates the data to generate a prioritized security report[cite: 5].

## Technical Constraints & Skills Demonstrated
This script was built under strict algorithmic constraints to demonstrate memory-efficient data extraction and low-level memory manipulation:
* **Bitwise Operations:** All data is extracted directly using bitwise shifts and masks[cite: 5]. 
* **No Type Casting:** The integer is strictly evaluated in its raw numerical form and never converted into a binary string for easier parsing[cite: 5].
* **No Advanced Structures:** The solution strictly avoids loops, arrays, strings, or helper functions[cite: 5].
* **Basic Cryptography:** Includes logic to reverse an XOR encryption (using a secret value of 5) applied to the incoming incident code[cite: 5].

## Data Payload Structure (`roomSignal`)
The integer's bits are allocated as follows:
* **Bits 0-3:** Independent sensor flags (Main door open, Window open, Motion detected, Emergency button pressed)[cite: 5].
* **Bits 4-6:** Zone identifier (Values 0–7)[cite: 5].
* **Bits 7-8:** Access level (Values 0–3)[cite: 5].
* **Bits 9-12:** Incident code (XOR-encoded)[cite: 5].
* **Bit 13:** Maintenance mode status[cite: 5].
* **Bits 14-15:** Unused and intentionally ignored[cite: 5].

## Decision Logic
The system evaluates the decoded data and triggers one of the following alerts in this exact order of priority[cite: 5]:
1. **EMERGENCY:** Triggered immediately if the emergency button is active[cite: 5].
2. **MAINTENANCE:** Triggered if the maintenance bit is active[cite: 5].
3. **UNAUTHORIZED ACCESS:** Triggered if a door or window is breached while the access level is 0[cite: 5].
4. **SECURITY ALERT:** Triggered if motion is detected alongside a decoded incident code of 9 or higher[cite: 5].
5. **ROOM SECURE:** Triggered if all sensors are inactive and the incident code is exactly 0[cite: 5].
6. **MONITOR REQUIRED:** Default fallback state for any other combination[cite: 5].

## Environment & Execution
* **Language:** C++ 
* **Tools:** Developed for standard compilation via `g++` 

**To run via terminal:**
```bash
g++ bitwise_security_decoder.cpp -o decoder
./decoder