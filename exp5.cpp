// Write a program which defines a class with constructor and destructor which will count number of object created and destroyed

#include <iostream>
using namespace std;

class ObjectCount {
private:
    static int count;   // declaring variable count to keep count of the object

public:
    ObjectCount() {      // constructor
        count++;
        cout << "Object created. Total: " << count << endl;
    }

    ~ObjectCount() {     // destructor
        count--;
        cout << "Object destroyed. Remaining: " << count << endl;
    }

    static void showCount() { // static function can access static variable
        cout << "Currently alive objects: " << count << endl;
    }
};

// initialize count variable
int ObjectCount::count = 0;

int main() {
    ObjectCount a, b;   // Creating object a and b to call constructor
    {
        ObjectCount c;  // Creating object c
        ObjectCount::showCount();   // Getting count of the objects created so far
    }                   // object c is deleted using destructor as it's scope ends here
    ObjectCount::showCount();       // Getting current object count

    ObjectCount d;      // Creating object d
    ObjectCount::showCount();       // Getting current object count
}
