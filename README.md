# cpp-input-monitor
A lightweight system monitoring tool exploring Windows API and bit manipulation for security analysis.
# C++ System Monitor & Input Analysis Tool

**Status:** 🚧 In Development

### Project Overview
This project is an educational exploration into OS-level input handling and memory management. It utilizes the Windows API to monitor system events, mimicking the behavior of user-space input capture tools used in security auditing.

### Technical Highlights
* **Bitwise Manipulation:** uses bitwise AND (`&`) masking to isolate key states from the `GetAsyncKeyState` return value.
* **Low-Level IO:** Direct interaction with `windows.h` for hardware polling.
* **Optimization:** Minimal CPU footprint design.

### Disclaimer
This software is developed strictly for educational purposes to understand how input interception works in a Windows environment.
