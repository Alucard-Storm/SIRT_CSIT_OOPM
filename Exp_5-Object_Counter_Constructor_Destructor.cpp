/*
 * Experiment 5: Object Counter Using Constructor and Destructor
 * 
 * This program demonstrates the use of constructor and destructor to
 * count the number of objects created and destroyed.
 */

#include <iostream>
using namespace std;

class ObjectCounter {
private:
    static int createdCount;    // Static variable to count created objects
    static int destroyedCount;  // Static variable to count destroyed objects
    int objectId;               // Unique ID for each object
    
public:
    // Constructor - called when object is created
    ObjectCounter() {
        createdCount++;           // Increment creation counter
        objectId = createdCount;  // Assign unique ID
        cout << "Object " << objectId << " created. ";
        displayCount();
    }
    
    // Copy constructor - called when object is copied
    ObjectCounter(const ObjectCounter& obj) {
        createdCount++;           // Increment creation counter
        objectId = createdCount;  // Assign unique ID
        cout << "Object " << objectId << " created (copy of Object " << obj.objectId << "). ";
        displayCount();
    }
    
    // Destructor - called when object is destroyed
    ~ObjectCounter() {
        destroyedCount++;         // Increment destruction counter
        cout << "Object " << objectId << " destroyed. ";
        displayCount();
    }
    
    // Static function to display current counts
    static void displayCount() {
        cout << "Created: " << createdCount << ", Destroyed: " << destroyedCount << endl;
    }
    
    // Function to get object ID
    int getId() const {
        return objectId;
    }
    
    // Static function to get total counts
    static int getCreatedCount() {
        return createdCount;
    }
    
    static int getDestroyedCount() {
        return destroyedCount;
    }
};

// Initialize static variables
int ObjectCounter::createdCount = 0;
int ObjectCounter::destroyedCount = 0;

// Function to demonstrate object creation and destruction
void demonstrateObjects() {
    cout << "\n=== Creating objects in function scope ===\n";
    
    // Create objects in function scope
    ObjectCounter obj1;
    ObjectCounter obj2;
    
    cout << "\nFunction scope objects created.\n";
    // Objects will be destroyed when function ends
}

int main() {
    cout << "=== Object Counter Demonstration ===\n\n";
    
    // Display initial count
    cout << "Initial count: ";
    ObjectCounter::displayCount();
    
    // Create first object
    cout << "\nCreating first object:\n";
    ObjectCounter* obj1 = new ObjectCounter();
    
    // Create second object
    cout << "\nCreating second object:\n";
    ObjectCounter* obj2 = new ObjectCounter();
    
    // Create third object using copy constructor
    cout << "\nCreating third object (copy of first):\n";
    ObjectCounter* obj3 = new ObjectCounter(*obj1);
    
    // Display current count
    cout << "\nCurrent count: ";
    ObjectCounter::displayCount();
    
    // Demonstrate function scope objects
    demonstrateObjects();
    
    // Display count after function call
    cout << "\nCount after function call: ";
    ObjectCounter::displayCount();
    
    // Delete objects manually
    cout << "\nDeleting objects:\n";
    delete obj1;
    delete obj2;
    delete obj3;
    
    // Display final count
    cout << "\nFinal count: ";
    ObjectCounter::displayCount();
    
    // Summary
    cout << "\n=== Summary ===\n";
    cout << "Total objects created: " << ObjectCounter::getCreatedCount() << endl;
    cout << "Total objects destroyed: " << ObjectCounter::getDestroyedCount() << endl;
    
    return 0;
}
