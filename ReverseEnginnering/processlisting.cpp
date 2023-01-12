#include <windows.h>
#include <tlhelp32.h>
#include <iostream>

int main( int argc, char* argv[] ) {
    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    
    // Example of how to list all running processes in system.
    while (Process32Next(hSnapshot, &pe32) == TRUE) {
        std::cout << "Process : " << (char*)pe32.szExeFile << std::endl;
    }
    
    // You can use these line below in order to check against a process name (ie: if a particular program is running)
    /* while (Process32Next(hSnapshot, &pe32) == TRUE) {
        std::cout << "Checking Process : " << (char*)pe32.szExeFile << " against : " << processName << std::endl;
        
        // Use #undef UNICODE at start of script if you want to avoid (char*) casting.
        if (strcmp((char*)pe32.szExeFile, processName) == 0) {
            std::cout << "Comparsion Successfull!" << std::endl;
            CloseHandle(hSnapshot);
            return 0;
        }
    } */

    CloseHandle(hSnapshot);

    return 0;
}
