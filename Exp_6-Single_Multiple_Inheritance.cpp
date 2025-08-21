/*
 * Experiment 6: Single and Multiple Inheritance Using Student as Base Class
 * 
 * This program demonstrates single and multiple inheritance by creating
 * different types of students with various specializations.
 */

#include <iostream>
#include <string>
using namespace std;

// Base class - Student
class Student {
protected:
    string name;
    int rollNo;
    string branch;
    int year;
    
public:
    // Constructor
    Student(string n, int roll, string b, int y) {
        name = n;
        rollNo = roll;
        branch = b;
        year = y;
    }
    
    // Virtual function for displaying student info
    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Branch: " << branch << endl;
        cout << "Year: " << year << endl;
    }
    
    // Virtual destructor
    virtual ~Student() {
        cout << "Student " << name << " destroyed." << endl;
    }
};

// Single inheritance - Engineering Student
class EngineeringStudent : public Student {
private:
    string specialization;
    double cgpa;
    
public:
    // Constructor
    EngineeringStudent(string n, int roll, string b, int y, string spec, double gpa) 
        : Student(n, roll, b, y) {
        specialization = spec;
        cgpa = gpa;
    }
    
    // Override display function
    void displayInfo() override {
        cout << "\n=== Engineering Student ===" << endl;
        Student::displayInfo();
        cout << "Specialization: " << specialization << endl;
        cout << "CGPA: " << cgpa << endl;
    }
    
    // Engineering specific function
    void showEngineeringDetails() {
        cout << "This student is studying " << specialization << " engineering." << endl;
    }
};

// Single inheritance - Medical Student
class MedicalStudent : public Student {
private:
    string hospital;
    int internshipYear;
    
public:
    // Constructor
    MedicalStudent(string n, int roll, string b, int y, string hosp, int intern) 
        : Student(n, roll, b, y) {
        hospital = hosp;
        internshipYear = intern;
    }
    
    // Override display function
    void displayInfo() override {
        cout << "\n=== Medical Student ===" << endl;
        Student::displayInfo();
        cout << "Hospital: " << hospital << endl;
        cout << "Internship Year: " << internshipYear << endl;
    }
    
    // Medical specific function
    void showMedicalDetails() {
        cout << "This student is doing internship at " << hospital << "." << endl;
    }
};

// Multiple inheritance - Research Student (inherits from both Engineering and Medical)
class ResearchStudent : public EngineeringStudent, public MedicalStudent {
private:
    string researchTopic;
    string supervisor;
    
public:
    // Constructor with multiple inheritance
    ResearchStudent(string n, int roll, string b, int y, string spec, double gpa,
                   string hosp, int intern, string topic, string sup)
        : EngineeringStudent(n, roll, b, y, spec, gpa),
          MedicalStudent(n, roll, b, y, hosp, intern) {
        researchTopic = topic;
        supervisor = sup;
    }
    
    // Override display function
    void displayInfo() override {
        cout << "\n=== Research Student ===" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Branch: " << branch << endl;
        cout << "Year: " << year << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "Hospital: " << hospital << endl;
        cout << "Internship Year: " << internshipYear << endl;
        cout << "Research Topic: " << researchTopic << endl;
        cout << "Supervisor: " << supervisor << endl;
    }
    
    // Research specific function
    void showResearchDetails() {
        cout << "Research topic: " << researchTopic << endl;
        cout << "Supervised by: " << supervisor << endl;
    }
};

int main() {
    cout << "=== Inheritance Demonstration ===\n\n";
    
    // Create base class object
    cout << "1. Base Class Student:" << endl;
    Student baseStudent("John Doe", 101, "Computer Science", 3);
    baseStudent.displayInfo();
    
    // Create single inheritance objects
    cout << "\n2. Single Inheritance Examples:" << endl;
    
    EngineeringStudent engStudent("Alice Smith", 201, "Mechanical", 2, "Robotics", 8.5);
    engStudent.displayInfo();
    engStudent.showEngineeringDetails();
    
    MedicalStudent medStudent("Bob Johnson", 301, "Medicine", 4, "City Hospital", 2);
    medStudent.displayInfo();
    medStudent.showMedicalDetails();
    
    // Create multiple inheritance object
    cout << "\n3. Multiple Inheritance Example:" << endl;
    ResearchStudent researchStudent("Carol Wilson", 401, "Biomedical", 5, 
                                   "Biomechanics", 9.0, "Research Hospital", 1,
                                   "Prosthetic Design", "Dr. Brown");
    researchStudent.displayInfo();
    researchStudent.showResearchDetails();
    
    // Demonstrate polymorphism
    cout << "\n4. Polymorphism Demonstration:" << endl;
    Student* students[4];
    students[0] = &baseStudent;
    students[1] = &engStudent;
    students[2] = &medStudent;
    students[3] = &researchStudent;
    
    for (int i = 0; i < 4; i++) {
        students[i]->displayInfo();
    }
    
    cout << "\n=== Program completed successfully ===" << endl;
    return 0;
}
