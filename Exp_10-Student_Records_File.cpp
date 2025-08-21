/*
 * Experiment 10: Student Records File Management
 * 
 * This program demonstrates file handling operations to store and retrieve
 * five student records in a text file.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    string branch;
    int year;
    double cgpa;
    
public:
    // Default constructor
    Student() {
        name = "";
        rollNo = 0;
        branch = "";
        year = 0;
        cgpa = 0.0;
    }
    
    // Parameterized constructor
    Student(string n, int roll, string b, int y, double gpa) {
        name = n;
        rollNo = roll;
        branch = b;
        year = y;
        cgpa = gpa;
    }
    
    // Function to input student data
    void inputData() {
        cout << "\n=== Enter Student Details ===" << endl;
        
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
        
        cout << "CGPA: ";
        cin >> cgpa;
        cin.ignore();  // Clear input buffer
    }
    
    // Function to display student data
    void displayData() const {
        cout << setw(20) << left << name;
        cout << setw(10) << rollNo;
        cout << setw(15) << branch;
        cout << setw(8) << year;
        cout << setw(8) << fixed << setprecision(2) << cgpa << endl;
    }
    
    // Function to write student data to file
    void writeToFile(ofstream& file) const {
        file << name << "|" << rollNo << "|" << branch << "|" << year << "|" << cgpa << endl;
    }
    
    // Function to read student data from file
    void readFromFile(ifstream& file) {
        string line;
        if (getline(file, line)) {
            size_t pos = 0;
            string token;
            string delimiter = "|";
            
            // Parse name
            pos = line.find(delimiter);
            name = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
            
            // Parse roll number
            pos = line.find(delimiter);
            token = line.substr(0, pos);
            rollNo = stoi(token);
            line.erase(0, pos + delimiter.length());
            
            // Parse branch
            pos = line.find(delimiter);
            branch = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
            
            // Parse year
            pos = line.find(delimiter);
            token = line.substr(0, pos);
            year = stoi(token);
            line.erase(0, pos + delimiter.length());
            
            // Parse CGPA
            cgpa = stod(line);
        }
    }
    
    // Getter functions
    string getName() const { return name; }
    int getRollNo() const { return rollNo; }
    string getBranch() const { return branch; }
    int getYear() const { return year; }
    double getCGPA() const { return cgpa; }
};

// Function to display header for student records
void displayHeader() {
    cout << "\n" << string(80, '=') << endl;
    cout << setw(20) << left << "NAME";
    cout << setw(10) << "ROLL NO";
    cout << setw(15) << "BRANCH";
    cout << setw(8) << "YEAR";
    cout << setw(8) << "CGPA" << endl;
    cout << string(80, '=') << endl;
}

// Function to write student records to file
void writeStudentRecords(const string& filename, Student students[], int count) {
    ofstream file(filename);
    
    if (!file.is_open()) {
        cout << "Error: Could not open file " << filename << " for writing!" << endl;
        return;
    }
    
    cout << "\nWriting " << count << " student records to file..." << endl;
    
    // Write header to file
    file << "STUDENT RECORDS" << endl;
    file << string(50, '-') << endl;
    
    // Write each student record
    for (int i = 0; i < count; i++) {
        students[i].writeToFile(file);
    }
    
    file.close();
    cout << "Student records successfully written to " << filename << endl;
}

// Function to read and display student records from file
void readStudentRecords(const string& filename) {
    ifstream file(filename);
    
    if (!file.is_open()) {
        cout << "Error: Could not open file " << filename << " for reading!" << endl;
        return;
    }
    
    cout << "\nReading student records from file..." << endl;
    
    // Skip header lines
    string header;
    getline(file, header);  // Skip "STUDENT RECORDS"
    getline(file, header);  // Skip separator line
    
    // Read and display student records
    Student student;
    int count = 0;
    
    displayHeader();
    
    while (!file.eof()) {
        student.readFromFile(file);
        if (file.good()) {  // Check if read was successful
            student.displayData();
            count++;
        }
    }
    
    file.close();
    
    cout << string(80, '=') << endl;
    cout << "Total records read: " << count << endl;
}

// Function to search student by roll number
void searchStudentByRoll(const string& filename, int rollNo) {
    ifstream file(filename);
    
    if (!file.is_open()) {
        cout << "Error: Could not open file " << filename << " for reading!" << endl;
        return;
    }
    
    // Skip header lines
    string header;
    getline(file, header);
    getline(file, header);
    
    // Search for student
    Student student;
    bool found = false;
    
    while (!file.eof()) {
        student.readFromFile(file);
        if (file.good() && student.getRollNo() == rollNo) {
            cout << "\nStudent found!" << endl;
            displayHeader();
            student.displayData();
            cout << string(80, '=') << endl;
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "Student with Roll No " << rollNo << " not found!" << endl;
    }
    
    file.close();
}

int main() {
    cout << "=== Student Records File Management System ===\n\n";
    
    const string filename = "student_records.txt";
    const int numStudents = 5;
    Student students[numStudents];
    
    // Input student data
    cout << "Enter details for " << numStudents << " students:\n";
    for (int i = 0; i < numStudents; i++) {
        cout << "\nStudent " << (i + 1) << ":";
        students[i].inputData();
    }
    
    // Display entered data
    cout << "\n=== Entered Student Data ===" << endl;
    displayHeader();
    for (int i = 0; i < numStudents; i++) {
        students[i].displayData();
    }
    cout << string(80, '=') << endl;
    
    // Write to file
    writeStudentRecords(filename, students, numStudents);
    
    // Read from file and display
    readStudentRecords(filename);
    
    // Search functionality
    cout << "\n=== Search Student by Roll Number ===" << endl;
    int searchRoll;
    cout << "Enter roll number to search: ";
    cin >> searchRoll;
    searchStudentByRoll(filename, searchRoll);
    
    // File operations summary
    cout << "\n=== File Operations Summary ===" << endl;
    cout << "1. Created file: " << filename << endl;
    cout << "2. Wrote " << numStudents << " student records" << endl;
    cout << "3. Successfully read records from file" << endl;
    cout << "4. Demonstrated search functionality" << endl;
    
    cout << "\n=== Program completed successfully ===" << endl;
    cout << "Check " << filename << " for stored records." << endl;
    
    return 0;
}
