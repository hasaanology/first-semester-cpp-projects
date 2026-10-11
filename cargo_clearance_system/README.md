# Automated Cargo Clearance System

## Overview
This project simulates an automated cargo-clearance system utilized by a multinational shipping company at an international port[cite: 7]. The program evaluates incoming shipments through a multi-stage decision pipeline to assign a final clearance decision before the cargo can enter the warehouse[cite: 7]. 

## Technical Constraints & Skills Demonstrated
This program was built to demonstrate complex, hierarchical business logic and dependency routing. It was developed under the following strict constraints:
* **Deeply Nested Logic:** The decision structure relies entirely on nested `if-else` statements, where the conditions evaluated at any stage strictly depend on the result of the previous stage[cite: 7].
* **No Logic Bypasses:** The use of single large compound conditions to bypass the intended decision tree is strictly prohibited[cite: 7]. 
* **Restricted Toolset:** The implementation successfully builds the required hierarchy without utilizing loops, arrays, helper functions, or `switch` statements[cite: 7].

## System Evaluation Parameters
The clearance engine receives and evaluates the following shipment data[cite: 7]:
* Documentation status & Importer type[cite: 7]
* Declared value & Weight category[cite: 7]
* Origin & Destination categories[cite: 7]
* Number of restricted items[cite: 7]
* Inspection & Insurance status[cite: 7]
* Priority level & Previous customs flags[cite: 7]

## Decision Pipeline
The system processes shipments through several dependent stages[cite: 7]:
1. **Documentation Stage:** Validates initial paperwork. Incomplete documentation is either rejected or checked for temporary clearance eligibility[cite: 7].
2. **Origin & Importer Verification:** Evaluates specific origin categories that require additional verification based on the importer type[cite: 7].
3. **Financial & Physical Inspection:** Routes high-value shipments and exceptionally heavy shipments into specialized inspection paths[cite: 7].
4. **Restriction & Security Checks:** Evaluates restricted items against destination rules, and triggers manual reviews if specific combinations of insurance statuses and prior customs flags occur[cite: 7]. 
5. **Priority Handling:** Applies priority processing rules while ensuring that priority status does not illegally override active customs restrictions[cite: 7].

## Environment & Execution
* **Language:** C++
* **Environment:** Developed and tested using Visual Studio Code and compiled via Ubuntu terminal.

**To compile and run:**
```bash
g++ cargo_clearance_system.cpp -o clearance_system
./clearance_system