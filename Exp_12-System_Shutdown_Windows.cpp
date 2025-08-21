/*
 * Experiment 12: System Shutdown on Windows Operating System
 * 
 * This program demonstrates how to shutdown, restart, or logoff the Windows system
 * using system commands and Windows API functions.
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>

using namespace std;

class SystemController {
private:
    bool isAdmin;
    string systemInfo;
    
public:
    // Constructor
    SystemController() {
        isAdmin = checkAdminPrivileges();
        systemInfo = getSystemInfo();
    }
    
    // Function to check if program has admin privileges
    bool checkAdminPrivileges() {
        BOOL isAdmin = FALSE;
        PSID adminGroup = NULL;
        SID_IDENTIFIER_AUTHORITY ntAuthority = SECURITY_NT_AUTHORITY;
        
        // Initialize the SID for the Administrators group
        if (AllocateAndInitializeSid(&ntAuthority, 2, SECURITY_BUILTIN_DOMAIN_RID,
                                   DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0, &adminGroup)) {
            // Check if the current user is a member of the Administrators group
            if (!CheckTokenMembership(NULL, adminGroup, &isAdmin)) {
                isAdmin = FALSE;
            }
            FreeSid(adminGroup);
        }
        
        return isAdmin == TRUE;
    }
    
    // Function to get system information
    string getSystemInfo() {
        string info = "";
        
        // Get Windows version
        OSVERSIONINFO osvi;
        ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
        osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
        
        if (GetVersionEx(&osvi)) {
            info += "Windows Version: " + to_string(osvi.dwMajorVersion) + "." + 
                   to_string(osvi.dwMinorVersion) + " (Build " + 
                   to_string(osvi.dwBuildNumber) + ")\n";
        }
        
        // Get computer name
        char computerName[MAX_COMPUTERNAME_LENGTH + 1];
        DWORD size = sizeof(computerName);
        if (GetComputerNameA(computerName, &size)) {
            info += "Computer Name: " + string(computerName) + "\n";
        }
        
        // Get user name
        char userName[256];
        size = sizeof(userName);
        if (GetUserNameA(userName, &size)) {
            info += "Current User: " + string(userName) + "\n";
        }
        
        return info;
    }
    
    // Function to shutdown system using system command
    bool shutdownSystem(int delaySeconds = 0, bool force = false) {
        if (!isAdmin) {
            cout << "Warning: Admin privileges required for system shutdown!" << endl;
            cout << "Some operations may not work without elevated permissions." << endl;
        }
        
        string command = "shutdown /s";
        
        if (delaySeconds > 0) {
            command += " /t " + to_string(delaySeconds);
        }
        
        if (force) {
            command += " /f";
        }
        
        cout << "Executing command: " << command << endl;
        cout << "System will shutdown in " << (delaySeconds > 0 ? to_string(delaySeconds) : "default") << " seconds." << endl;
        
        int result = system(command.c_str());
        return result == 0;
    }
    
    // Function to restart system using system command
    bool restartSystem(int delaySeconds = 0, bool force = false) {
        if (!isAdmin) {
            cout << "Warning: Admin privileges required for system restart!" << endl;
        }
        
        string command = "shutdown /r";
        
        if (delaySeconds > 0) {
            command += " /t " + to_string(delaySeconds);
        }
        
        if (force) {
            command += " /f";
        }
        
        cout << "Executing command: " << command << endl;
        cout << "System will restart in " << (delaySeconds > 0 ? to_string(delaySeconds) : "default") << " seconds." << endl;
        
        int result = system(command.c_str());
        return result == 0;
    }
    
    // Function to logoff current user
    bool logoffUser() {
        cout << "Logging off current user..." << endl;
        
        // Use ExitWindowsEx for user logoff
        if (ExitWindowsEx(EWX_LOGOFF, 0)) {
            cout << "Logoff initiated successfully." << endl;
            return true;
        } else {
            cout << "Failed to initiate logoff. Error code: " << GetLastError() << endl;
            return false;
        }
    }
    
    // Function to cancel pending shutdown
    bool cancelShutdown() {
        cout << "Cancelling any pending shutdown..." << endl;
        
        string command = "shutdown /a";
        int result = system(command.c_str());
        
        if (result == 0) {
            cout << "Shutdown cancelled successfully." << endl;
            return true;
        } else {
            cout << "No pending shutdown to cancel or operation failed." << endl;
            return false;
        }
    }
    
    // Function to hibernate system
    bool hibernateSystem() {
        if (!isAdmin) {
            cout << "Warning: Admin privileges may be required for hibernation!" << endl;
        }
        
        cout << "Hibernating system..." << endl;
        
        // Use SetSuspendState for hibernation
        if (SetSuspendState(TRUE, FALSE, FALSE)) {
            cout << "Hibernation initiated successfully." << endl;
            return true;
        } else {
            cout << "Failed to initiate hibernation. Error code: " << GetLastError() << endl;
            return false;
        }
    }
    
    // Function to display system status
    void displaySystemStatus() {
        cout << "\n=== System Status ===" << endl;
        cout << string(50, '=') << endl;
        cout << systemInfo;
        cout << "Admin Privileges: " << (isAdmin ? "Yes" : "No") << endl;
        
        // Check if hibernation is enabled
        DWORD hibernationEnabled = 0;
        if (GetPwrCapabilities) {
            SYSTEM_POWER_CAPABILITIES powerCaps;
            if (GetPwrCapabilities(&powerCaps)) {
                cout << "Hibernation Supported: " << (powerCaps.HiberFilePresent ? "Yes" : "No") << endl;
            }
        }
        
        cout << string(50, '=') << endl;
    }
    
    // Function to show shutdown options menu
    void showShutdownMenu() {
        cout << "\n=== System Control Options ===" << endl;
        cout << "1. Shutdown System" << endl;
        cout << "2. Restart System" << endl;
        cout << "3. Logoff User" << endl;
        cout << "4. Hibernate System" << endl;
        cout << "5. Cancel Pending Shutdown" << endl;
        cout << "6. Display System Status" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice (1-7): ";
    }
    
    // Function to get user confirmation
    bool getUserConfirmation(const string& action) {
        cout << "\nAre you sure you want to " << action << "? (y/n): ";
        char response;
        cin >> response;
        return (response == 'y' || response == 'Y');
    }
    
    // Function to get delay time from user
    int getDelayTime() {
        int delay;
        cout << "Enter delay in seconds (0 for immediate): ";
        cin >> delay;
        return (delay >= 0) ? delay : 0;
    }
};

int main() {
    cout << "=== Windows System Controller ===\n\n";
    
    SystemController controller;
    
    // Display initial system status
    controller.displaySystemStatus();
    
    int choice;
    bool exitProgram = false;
    
    while (!exitProgram) {
        controller.showShutdownMenu();
        cin >> choice;
        
        switch (choice) {
            case 1: {
                // Shutdown System
                if (controller.getUserConfirmation("shutdown the system")) {
                    int delay = controller.getDelayTime();
                    bool force;
                    cout << "Force shutdown? (y/n): ";
                    char forceResponse;
                    cin >> forceResponse;
                    force = (forceResponse == 'y' || forceResponse == 'Y');
                    
                    controller.shutdownSystem(delay, force);
                }
                break;
            }
            
            case 2: {
                // Restart System
                if (controller.getUserConfirmation("restart the system")) {
                    int delay = controller.getDelayTime();
                    bool force;
                    cout << "Force restart? (y/n): ";
                    char forceResponse;
                    cin >> forceResponse;
                    force = (forceResponse == 'y' || forceResponse == 'Y');
                    
                    controller.restartSystem(delay, force);
                }
                break;
            }
            
            case 3: {
                // Logoff User
                if (controller.getUserConfirmation("logoff the current user")) {
                    controller.logoffUser();
                }
                break;
            }
            
            case 4: {
                // Hibernate System
                if (controller.getUserConfirmation("hibernate the system")) {
                    controller.hibernateSystem();
                }
                break;
            }
            
            case 5: {
                // Cancel Pending Shutdown
                controller.cancelShutdown();
                break;
            }
            
            case 6: {
                // Display System Status
                controller.displaySystemStatus();
                break;
            }
            
            case 7: {
                // Exit Program
                cout << "Exiting program..." << endl;
                exitProgram = true;
                break;
            }
            
            default:
                cout << "Invalid choice! Please enter a number between 1-7." << endl;
        }
        
        if (!exitProgram) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
    }
    
    cout << "\n=== Program completed successfully ===" << endl;
    cout << "Note: Some operations may require administrator privileges." << endl;
    
    return 0;
}
