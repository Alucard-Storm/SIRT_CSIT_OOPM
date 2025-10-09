// Write a program to add two private data members using friend function

#include<iostream>
using namespace std;

class Friend {
    private:
    int a;      // private variable a
    int b;      // private variable b

    public:
    friend void add(Friend& obj);   // declaration of friend function add
};

void add(Friend& obj) {             // Definition of friend function add
    cout<<"Enter the value of a and b"<<endl;
    cin>>obj.a>>obj.b;
    int c = obj.a + obj.b;
    cout<<"Sum of "<<obj.a<<" and "<<obj.b<<" is "<<c<<endl;
}

int main() {
    Friend z;
    add(z);     // Calling friend function
}