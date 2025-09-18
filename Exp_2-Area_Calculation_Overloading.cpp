/*
 * Experiment 2: Area Calculation Using Function Overloading
 * 
 * This program demonstrates function overloading by calculating areas
 * of different shapes (circle, rectangle, triangle) using the same function name.
 */

#include <iostream>
#include <cmath>
using namespace std;

// Function overloading for area calculation
// Area of circle
double area(double radius) {
    return 3.14159 * radius * radius;  // π * r²
}

// Area of rectangle
double area(double length, double width) {
    return length * width;  // l * w
}

// Area of triangle
double area(double base, double height, char shape) {
        return 0.5 * base * height;  // ½ * b * h
}

int main() {
    double radius, length, width, base, height;
    int choice;
    
    cout << "=== Area Calculator ===\n";
    cout << "1. Circle\n";
    cout << "2. Rectangle\n";
    cout << "3. Triangle\n";
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    
    switch (choice) {
        case 1:
            // Calculate area of circle
            cout << "Enter radius of circle: ";
            cin >> radius;
            cout << "Area of circle: " << area(radius) << " square units" << endl;
            break;
            
        case 2:
            // Calculate area of rectangle
            cout << "Enter length: ";
            cin >> length;
            cout << "Enter width: ";
            cin >> width;
            cout << "Area of rectangle: " << area(length, width) << " square units" << endl;
            break;
            
        case 3:
            // Calculate area of triangle
            cout << "Enter base: ";
            cin >> base;
            cout << "Enter height: ";
            cin >> height;
            cout << "Area of triangle: " << area(base, height, 't') << " square units" << endl;
            break;
            
        default:
            cout << "Invalid choice!" << endl;
    }
    
    return 0;
}
