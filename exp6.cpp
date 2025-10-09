// Write a program to implement single and multiple inheritances taking student as the sample base class

#include<iostream>
using namespace std;

class Class_A {     // base class A
    public:
    Class_A() {
        cout<<"Constructor of class A"<<endl;
    }
};

class Class_B {     // base class B
    public:
    Class_B() {
        cout<<"Constructor of class B"<<endl;
    }
};

class Class_C : public Class_A, public Class_B {    // derived class c, derived from A and B
    public:
    Class_C() {
        cout<<"Constructor of class C"<<endl;
    }
};

int main() {
    Class_C obj;
}