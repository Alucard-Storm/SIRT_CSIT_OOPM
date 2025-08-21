/*
 * Experiment 3: Complex Numbers Using Operator Overloading and Type Conversion
 * 
 * This program implements a Complex class with operator overloading for
 * arithmetic operations and type conversion to display complex numbers.
 */

#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double real;      // Real part of complex number
    double imag;      // Imaginary part of complex number
    
public:
    // Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    
    // Display function
    void display() const {
        if (imag >= 0) {
            cout << real << " + " << imag << "i";
        } else {
            cout << real << " - " << abs(imag) << "i";
        }
    }
    
    // Operator overloading for addition
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }
    
    // Operator overloading for subtraction
    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }
    
    // Operator overloading for multiplication
    Complex operator*(const Complex& c) const {
        double newReal = real * c.real - imag * c.imag;
        double newImag = real * c.imag + imag * c.real;
        return Complex(newReal, newImag);
    }
    
    // Type conversion operator to double (magnitude)
    operator double() const {
        return sqrt(real * real + imag * imag);
    }
    
    // Friend function for input
    friend istream& operator>>(istream& in, Complex& c);
    
    // Friend function for output
    friend ostream& operator<<(ostream& out, const Complex& c);
};

// Input operator overloading
istream& operator>>(istream& in, Complex& c) {
    cout << "Enter real part: ";
    in >> c.real;
    cout << "Enter imaginary part: ";
    in >> c.imag;
    return in;
}

// Output operator overloading
ostream& operator<<(ostream& out, const Complex& c) {
    c.display();
    return out;
}

int main() {
    Complex c1, c2, result;
    
    cout << "=== Complex Number Calculator ===\n\n";
    
    // Input first complex number
    cout << "First complex number:\n";
    cin >> c1;
    
    // Input second complex number
    cout << "\nSecond complex number:\n";
    cin >> c2;
    
    cout << "\nResults:\n";
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    
    // Addition
    result = c1 + c2;
    cout << "c1 + c2 = " << result << endl;
    
    // Subtraction
    result = c1 - c2;
    cout << "c1 - c2 = " << result << endl;
    
    // Multiplication
    result = c1 * c2;
    cout << "c1 * c2 = " << result << endl;
    
    // Type conversion demonstration
    cout << "Magnitude of c1: " << (double)c1 << endl;
    cout << "Magnitude of c2: " << (double)c2 << endl;
    
    return 0;
}
