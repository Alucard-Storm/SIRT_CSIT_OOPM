/*
 * Experiment 1: Find Largest Number Using Function
 * 
 * This program demonstrates the use of functions to find the largest number
 * among three user-input numbers.
 */

#include <iostream>
using namespace std;

// Function declaration - finds the largest among three numbers
int findLargest(int a, int b, int c);

int main() {
    int num1, num2, num3;
    
    // Get input from user
    cout << "Enter first number: ";
    cin >> num1;
    
    cout << "Enter second number: ";
    cin >> num2;
    
    cout << "Enter third number: ";
    cin >> num3;
    
    // Call function to find largest number
    int largest = findLargest(num1, num2, num3);
    
    // Display result
    cout << "\nThe largest number is: " << largest << endl;
    
    return 0;
}

// Function definition - compares three numbers and returns the largest
int findLargest(int a, int b, int c) {
    // Assume first number is largest initially
    int largest = a;
    
    // Compare with second number
    if (b > largest) {
        largest = b;
    }
    
    // Compare with third number
    if (c > largest) {
        largest = c;
    }
    
    return largest;
}
