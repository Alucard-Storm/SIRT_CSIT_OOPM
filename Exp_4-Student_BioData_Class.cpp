/*
 * Experiment 4: Student Bio-Data Using Class and Object
 * 
 * This program demonstrates the use of classes and objects to store
 * and display student bio-data information.
 */

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    // Private data members
    string name;
    int rollNo;
    string branch;
    int year;
    string email;
    string phone;
    
public:
    // Constructor to initialize student data
    Student(string n, int roll, string b, int y, string e, string p) {
        name = n;
        rollNo = roll;
        branch = b;
        year = y;
        email = e;
        phone = p;
    }
    
    // Default constructor
    Student() {
        name = "";
        rollNo = 0;
        branch = "";
        year = 0;
        email = "";
        phone = "";
    }
    
    // Function to input student data
    void inputData() {
        cout << "\n=== Enter Student Details ===\n";
        
        cout << "Name: ";
        getline(cin, name);
        
        cout << "Roll Number: ";
        cin >> rollNo;
        cin.ignore();  // Clear input buffer
        
        cout << "Branch: ";
        getline(cin, branch);
        
        cout << "Year: ";
        cin >> year;
        cin.ignore();  // Clear input buffer
        
        cout << "Email: ";
        getline(cin, email);
        
        cout << "Phone: ";
        getline(cin, phone);
    }
    
    // Function to display student bio-data
    void displayBioData() const {
        cout << "\n========================================\n";
        cout << "           STUDENT BIO-DATA\n";
        cout << "========================================\n";
        cout << "Name        : " << name << endl;
        cout << "Roll Number : " << rollNo << endl;
        cout << "Branch      : " << branch << endl;
        cout << "Year        : " << year << endl;
        cout << "Email       : " << email << endl;
        cout << "Phone       : " << phone << endl;
        cout << "========================================\n";
    }
    
    // Function to update student data
    void updateData() {
        cout << "\n=== Update Student Details ===\n";
        inputData();
    }
};

int main() {
    int choice, numStudents;
    
    cout << "=== Student Bio-Data Management System ===\n";
    cout << "Enter number of students: ";
    cin >> numStudents;
    cin.ignore();  // Clear input buffer
    
    // Create array of Student objects
    Student students[numStudents];
    
    // Input data for all students
    for (int i = 0; i < numStudents; i++) {
        cout << "\nStudent " << (i + 1) << ":";
        students[i].inputData();
    }
    
    // Menu for operations
    do {
        cout << "\n=== Menu ===\n";
        cout << "1. Display all students\n";
        cout << "2. Display specific student\n";
        cout << "3. Update student data\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                // Display all students
                cout << "\n=== All Students Bio-Data ===\n";
                for (int i = 0; i < numStudents; i++) {
                    students[i].displayBioData();
                }
                break;
                
            case 2:
                // Display specific student
                int studentIndex;
                cout << "Enter student number (1-" << numStudents << "): ";
                cin >> studentIndex;
                if (studentIndex >= 1 && studentIndex <= numStudents) {
                    students[studentIndex - 1].displayBioData();
                } else {
                    cout << "Invalid student number!\n";
                }
                break;
                
            case 3:
                // Update student data
                cout << "Enter student number (1-" << numStudents << "): ";
                cin >> studentIndex;
                cin.ignore();  // Clear input buffer
                if (studentIndex >= 1 && studentIndex <= numStudents) {
                    students[studentIndex - 1].updateData();
                } else {
                    cout << "Invalid student number!\n";
                }
                break;
                
            case 4:
                cout << "Thank you for using the system!\n";
                break;
                
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);
    
    return 0;
}
