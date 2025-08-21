/*
 * Experiment 7: Adding Private Data Members Using Friend Function
 * 
 * This program demonstrates the use of friend functions to access
 * and manipulate private data members of a class.
 */

#include <iostream>
using namespace std;

// Forward declaration of class B
class ClassB;

// Class A with private data members
class ClassA {
private:
    int privateData1;
    int privateData2;
    
public:
    // Constructor
    ClassA(int data1, int data2) {
        privateData1 = data1;
        privateData2 = data2;
    }
    
    // Display function
    void displayData() {
        cout << "ClassA - Data1: " << privateData1 << ", Data2: " << privateData2 << endl;
    }
    
    // Friend function declaration - can access private members
    friend int addPrivateData(const ClassA& objA, const ClassB& objB);
    friend void modifyPrivateData(ClassA& obj, int newData1, int newData2);
    friend void swapPrivateData(ClassA& obj1, ClassA& obj2);
};

// Class B with private data members
class ClassB {
private:
    int privateData3;
    int privateData4;
    
public:
    // Constructor
    ClassB(int data3, int data4) {
        privateData3 = data3;
        privateData4 = data4;
    }
    
    // Display function
    void displayData() {
        cout << "ClassB - Data3: " << privateData3 << ", Data4: " << privateData4 << endl;
    }
    
    // Friend function declaration
    friend int addPrivateData(const ClassA& objA, const ClassB& objB);
    friend void modifyPrivateData(ClassB& obj, int newData3, int newData4);
};

// Friend function to add private data from both classes
int addPrivateData(const ClassA& objA, const ClassB& objB) {
    // Can access private members of both classes
    int sum = objA.privateData1 + objA.privateData2 + 
              objB.privateData3 + objB.privateData4;
    return sum;
}

// Friend function to modify private data of ClassA
void modifyPrivateData(ClassA& obj, int newData1, int newData2) {
    // Can directly modify private members
    obj.privateData1 = newData1;
    obj.privateData2 = newData2;
    cout << "Modified ClassA private data using friend function." << endl;
}

// Friend function to modify private data of ClassB
void modifyPrivateData(ClassB& obj, int newData3, int newData4) {
    // Can directly modify private members
    obj.privateData3 = newData3;
    obj.privateData4 = newData4;
    cout << "Modified ClassB private data using friend function." << endl;
}

// Friend function to swap private data between two ClassA objects
void swapPrivateData(ClassA& obj1, ClassA& obj2) {
    // Can access and swap private members
    int temp1 = obj1.privateData1;
    int temp2 = obj1.privateData2;
    
    obj1.privateData1 = obj2.privateData1;
    obj1.privateData2 = obj2.privateData2;
    
    obj2.privateData1 = temp1;
    obj2.privateData2 = temp2;
    
    cout << "Swapped private data between two ClassA objects." << endl;
}

// Standalone function (not a friend) - cannot access private members
void demonstrateNonFriendAccess() {
    cout << "\n=== Non-Friend Function Demonstration ===" << endl;
    cout << "This function cannot access private members of any class." << endl;
    cout << "It can only work with public members and functions." << endl;
}

int main() {
    cout << "=== Friend Function Demonstration ===\n\n";
    
    // Create objects
    ClassA objA1(10, 20);
    ClassA objA2(30, 40);
    ClassB objB(50, 60);
    
    // Display initial data
    cout << "Initial data:" << endl;
    objA1.displayData();
    objA2.displayData();
    objB.displayData();
    
    // Demonstrate friend function adding private data
    cout << "\n=== Adding Private Data ===" << endl;
    int totalSum = addPrivateData(objA1, objB);
    cout << "Sum of all private data: " << totalSum << endl;
    
    // Demonstrate friend function modifying private data
    cout << "\n=== Modifying Private Data ===" << endl;
    modifyPrivateData(objA1, 100, 200);
    modifyPrivateData(objB, 500, 600);
    
    // Display modified data
    cout << "\nAfter modification:" << endl;
    objA1.displayData();
    objB.displayData();
    
    // Demonstrate friend function swapping private data
    cout << "\n=== Swapping Private Data ===" << endl;
    cout << "Before swap:" << endl;
    objA1.displayData();
    objA2.displayData();
    
    swapPrivateData(objA1, objA2);
    
    cout << "After swap:" << endl;
    objA1.displayData();
    objA2.displayData();
    
    // Demonstrate non-friend function
    demonstrateNonFriendAccess();
    
    // Summary
    cout << "\n=== Summary ===" << endl;
    cout << "Friend functions can:" << endl;
    cout << "1. Access private members of the class" << endl;
    cout << "2. Modify private members directly" << endl;
    cout << "3. Work with multiple classes" << endl;
    cout << "4. Provide controlled access to private data" << endl;
    
    return 0;
}
