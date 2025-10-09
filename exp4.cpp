// Write a program using class and object to print bio-data of the students.

#include<iostream>
using namespace std;

class Student {
    protected:
    char name[20],roll_no[12],branch[5],sem[3];     // char type array to store student details

    public:
    void input() {      // Input function to input student details
        cout<<"Enter Student Name : ";
        cin>>name;
        cout<<"Enter Student Roll No : ";
        cin>>roll_no;
        cout<<"Enter Student Branch No : ";
        cin>>branch;
        cout<<"Enter Student Semester : ";
        cin>>sem;
    }
    void display() {    // Display function to display student details
        cout<<"Name : "<<name<<endl;
        cout<<"Roll No : "<<roll_no<<endl;
        cout<<"Branch No : "<<branch<<endl;
        cout<<"Semester : "<<sem<<endl;
    }
};

int main() {
    Student s;
    s.input();
    s.display();
}