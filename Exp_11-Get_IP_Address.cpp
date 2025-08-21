/*
 * Experiment 11: Get IP Address of the System
 * 
 * This program demonstrates how to retrieve the IP address of the system
 * using different methods including system commands and network libraries.
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #pragma comment(lib, "ws2_32.lib")
#else
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <netdb.h>
#endif

using namespace std;

class IPAddressFinder {
private:
    string localIP;
    string publicIP;
    string hostname;
    
public:
    // Constructor
    IPAddressFinder() {
        localIP = "";
        publicIP = "";
        hostname = "";
    }
    
    // Function to get local IP address using system commands
    string getLocalIPUsingSystem() {
        string command;
        string result = "";
        
        #ifdef _WIN32
            // Windows command to get local IP
            command = "ipconfig | findstr /i \"IPv4\"";
        #else
            // Linux/Unix command to get local IP
            command = "hostname -I | awk '{print $1}'";
        #endif
        
        // Execute system command and capture output
        FILE* pipe = popen(command.c_str(), "r");
        if (pipe) {
            char buffer[128];
            while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
                result += buffer;
            }
            pclose(pipe);
        }
        
        // Clean up the result
        if (!result.empty()) {
            #ifdef _WIN32
                // Extract IP from Windows ipconfig output
                size_t pos = result.find(":");
                if (pos != string::npos) {
                    result = result.substr(pos + 1);
                    // Remove extra whitespace and newlines
                    result.erase(0, result.find_first_not_of(" \t\r\n"));
                    result.erase(result.find_last_not_of(" \t\r\n") + 1);
                }
            #else
                // Remove newline from Linux output
                result.erase(result.find_last_not_of(" \t\r\n") + 1);
            #endif
        }
        
        return result;
    }
    
    // Function to get local IP address using socket programming
    string getLocalIPUsingSocket() {
        string localIP = "";
        
        #ifdef _WIN32
            // Initialize Winsock for Windows
            WSADATA wsaData;
            if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
                return "Failed to initialize Winsock";
            }
        #endif
        
        // Create socket
        int sock = socket(AF_INET, SOCK_DGRAM, 0);
        if (sock < 0) {
            #ifdef _WIN32
                WSACleanup();
            #endif
            return "Failed to create socket";
        }
        
        // Connect to a remote address (doesn't actually send data)
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(80);
        addr.sin_addr.s_addr = inet_addr("8.8.8.8");  // Google DNS
        
        if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
            #ifdef _WIN32
                closesocket(sock);
                WSACleanup();
            #else
                close(sock);
            #endif
            return "Failed to connect socket";
        }
        
        // Get local address
        socklen_t addrLen = sizeof(addr);
        if (getsockname(sock, (struct sockaddr*)&addr, &addrLen) < 0) {
            #ifdef _WIN32
                closesocket(sock);
                WSACleanup();
            #else
                close(sock);
            #endif
            return "Failed to get socket name";
        }
        
        // Convert to string
        char ipStr[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &addr.sin_addr, ipStr, INET_ADDRSTRLEN);
        localIP = string(ipStr);
        
        // Cleanup
        #ifdef _WIN32
            closesocket(sock);
            WSACleanup();
        #else
            close(sock);
        #endif
        
        return localIP;
    }
    
    // Function to get hostname
    string getHostname() {
        char hostname[256];
        if (gethostname(hostname, sizeof(hostname)) == 0) {
            return string(hostname);
        }
        return "Unknown hostname";
    }
    
    // Function to get public IP using external service (simplified)
    string getPublicIP() {
        // Note: In a real application, you would make an HTTP request to a service
        // like "http://ipinfo.io/ip" or "http://checkip.amazonaws.com/"
        // For this demonstration, we'll show the concept
        
        cout << "Note: Getting public IP requires internet connection and external service." << endl;
        cout << "This is a simplified demonstration." << endl;
        
        return "Public IP lookup not implemented (requires HTTP client)";
    }
    
    // Function to display all IP information
    void displayAllIPInfo() {
        cout << "\n=== System IP Address Information ===" << endl;
        cout << string(50, '=') << endl;
        
        // Get hostname
        hostname = getHostname();
        cout << "Hostname: " << hostname << endl;
        
        // Get local IP using system command
        localIP = getLocalIPUsingSystem();
        cout << "Local IP (System): " << localIP << endl;
        
        // Get local IP using socket
        string socketIP = getLocalIPUsingSocket();
        cout << "Local IP (Socket): " << socketIP << endl;
        
        // Get public IP
        publicIP = getPublicIP();
        cout << "Public IP: " << publicIP << endl;
        
        cout << string(50, '=') << endl;
    }
    
    // Function to check if IP is valid
    bool isValidIP(const string& ip) {
        if (ip.empty()) return false;
        
        // Simple validation for IPv4 format
        int dots = 0;
        for (char c : ip) {
            if (c == '.') dots++;
            else if (c < '0' || c > '9') return false;
        }
        
        return dots == 3;  // IPv4 has 3 dots
    }
    
    // Function to get network interface information
    void getNetworkInterfaces() {
        cout << "\n=== Network Interface Information ===" << endl;
        cout << string(50, '=') << endl;
        
        #ifdef _WIN32
            cout << "Windows system detected." << endl;
            cout << "Use 'ipconfig /all' for detailed interface information." << endl;
        #else
            cout << "Unix/Linux system detected." << endl;
            cout << "Use 'ifconfig' or 'ip addr' for detailed interface information." << endl;
        #endif
        
        // Display basic interface info
        cout << "Primary local IP: " << localIP << endl;
        cout << "Hostname: " << hostname << endl;
    }
};

int main() {
    cout << "=== System IP Address Finder ===\n\n";
    
    IPAddressFinder ipFinder;
    
    // Display all IP information
    ipFinder.displayAllIPInfo();
    
    // Display network interface information
    ipFinder.getNetworkInterfaces();
    
    // Additional information
    cout << "\n=== Additional Information ===" << endl;
    cout << "1. Local IP: Internal network address of your machine" << endl;
    cout << "2. Public IP: External address visible to the internet" << endl;
    cout << "3. Hostname: Name of your computer on the network" << endl;
    
    cout << "\n=== Program completed successfully ===" << endl;
    cout << "Note: Some features may require appropriate permissions and network access." << endl;
    
    return 0;
}
