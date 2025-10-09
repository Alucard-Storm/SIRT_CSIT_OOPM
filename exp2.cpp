// Write a program to find out the largest number using function

#include<iostream>
using namespace std;

int main() {
    int a, b, c;
    cout<<"Enter 3 numbers: ";
    cin>>a>>b>>c;

    if(a>b && a>c) {        // Comparing A with B and C
        cout<<a<<" is largest among the 3";
    }
    else if(b>a && b>c) {   // Comparing B with A and C
        cout<<b<<" is largest among the 3";
    }
    else {                  // If both previous conditions are false
        cout<<c<<" is largest among the 3";
    }
}