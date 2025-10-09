// Write a program to find the area of circle, rectangle and triangle using function overloading

#include<iostream>
using namespace std;

class Shape {
    public:
    void area(int a) {                  // function with 1 argument
        int area = 3.14 * a * a;
        cout<<"Radius of Circle is "<<a<<" and its Area is "<<area<<endl;
    }
    void area(int a, int b) {           // function with 2 arguments
        int area = a * b;
        cout<<"Length and width of the Rectangle is "<<a<<" & "<<b<<" and it's Area is "<<area<<endl;
    }
    void area(int a, int b, char c) {   //function with 3 arguments where char c is dummy
        int area = 0.5 * a * b;
        cout<<"Heigh and Base of the Triangle is "<<a<<" & "<<b<<" and it's Area is "<<area<<endl;
    }
};

int main() {
    Shape obj;
    int a, b, c;
    cout<<"Enter the radius of the Circle ";
    cin>>a;
    obj.area(a);            //calling function using 1 argument
    cout<<"Enter the length and width of the rectangle ";
    cin>>a>>b;
    obj.area(a,b);          //calling function using 2 arguments
    cout<<"Enter the height and base of the Triangle ";
    cin>>a>>b;
    obj.area(a,b,'z');    // calling function using 3 arguments with a dummy char to satisfy conditio
}