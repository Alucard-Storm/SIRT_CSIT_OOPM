// Write a program that store five student records in a file

#include <iostream>
#include <fstream>
using namespace std;

class Student {
    int roll_no;
    char name[20];
    float marks;

    public:
    void write() {
        fstream outFile("student.txt", ios::out); // Open file in write mode

        Student students[5]; // Array to hold 5 student records

        cout << "Enter details of 5 Students" << endl;
        for (int i = 0; i < 5; ++i) {  // Loop to get details of each student
            cout << "\nStudent " << i + 1 << ":" << endl;
            
            cout << "Enter Student Roll Number : ";
            cin >> students[i].roll_no;

            cout << "Enter Student Name : ";
            cin >> students[i].name;

            cout << "Enter Student Marks: ";
            cin >> students[i].marks;

            outFile << "Student Roll Number " << students[i].roll_no << ", " << "Student Name " << students[i].name << ", " << "Student makrs " << students[i].marks << "\n"; // Write to file
        }

        outFile.close(); // Close the file
    }

    void read() {
        ifstream inFile("student.txt"); // Open file in read mode
        string line;

        cout << "\nStudent Records from file:" << endl;
        while (getline(inFile, line)) { // Read each line from the file
            cout << line << endl; // Display the line
        }

        inFile.close(); // Close the file
    }
};

int main() {
    Student s;
    s.write();
    s.read();
}