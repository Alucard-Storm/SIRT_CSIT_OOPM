/*
 * Experiment 9: Stack Implementation Using Virtual Functions
 * 
 * This program demonstrates the implementation of a stack data structure
 * using virtual functions and polymorphism for different stack types.
 */

#include <iostream>
using namespace std;

// Abstract base class for Stack
class Stack {
protected:
    int* data;      // Array to store stack elements
    int top;        // Index of top element
    int capacity;   // Maximum capacity of stack
    
public:
    // Constructor
    Stack(int size = 10) {
        capacity = size;
        data = new int[capacity];
        top = -1;  // Empty stack
    }
    
    // Virtual destructor
    virtual ~Stack() {
        delete[] data;
        cout << "Stack memory deallocated." << endl;
    }
    
    // Pure virtual functions - must be implemented by derived classes
    virtual void push(int value) = 0;
    virtual int pop() = 0;
    virtual int peek() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    virtual void display() = 0;
    
    // Common function to get stack size
    int getSize() const {
        return top + 1;
    }
    
    // Common function to get capacity
    int getCapacity() const {
        return capacity;
    }
};

// Derived class - Integer Stack
class IntStack : public Stack {
public:
    // Constructor
    IntStack(int size = 10) : Stack(size) {
        cout << "Integer Stack created with capacity " << capacity << endl;
    }
    
    // Implementation of push function
    void push(int value) override {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        data[++top] = value;
        cout << "Pushed " << value << " to stack" << endl;
    }
    
    // Implementation of pop function
    int pop() override {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from empty stack" << endl;
            return -1;
        }
        int value = data[top--];
        cout << "Popped " << value << " from stack" << endl;
        return value;
    }
    
    // Implementation of peek function
    int peek() override {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot peek" << endl;
            return -1;
        }
        return data[top];
    }
    
    // Implementation of isEmpty function
    bool isEmpty() override {
        return top == -1;
    }
    
    // Implementation of isFull function
    bool isFull() override {
        return top == capacity - 1;
    }
    
    // Implementation of display function
    void display() override {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        
        cout << "Stack contents (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << data[i];
            if (i > 0) cout << " -> ";
        }
        cout << endl;
    }
};

// Derived class - Bounded Stack (with additional safety features)
class BoundedStack : public Stack {
private:
    int minSize;  // Minimum size constraint
    
public:
    // Constructor
    BoundedStack(int size = 10, int min = 5) : Stack(size) {
        minSize = min;
        cout << "Bounded Stack created with capacity " << capacity << " and minimum size " << minSize << endl;
    }
    
    // Override push with additional safety
    void push(int value) override {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        data[++top] = value;
        cout << "Pushed " << value << " to bounded stack" << endl;
    }
    
    // Override pop with minimum size constraint
    int pop() override {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from empty stack" << endl;
            return -1;
        }
        if (getSize() <= minSize) {
            cout << "Cannot pop! Stack size would go below minimum (" << minSize << ")" << endl;
            return -1;
        }
        int value = data[top--];
        cout << "Popped " << value << " from bounded stack" << endl;
        return value;
    }
    
    // Implementation of peek function
    int peek() override {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot peek" << endl;
            return -1;
        }
        return data[top];
    }
    
    // Implementation of isEmpty function
    bool isEmpty() override {
        return top == -1;
    }
    
    // Implementation of isFull function
    bool isFull() override {
        return top == capacity - 1;
    }
    
    // Implementation of display function
    void display() override {
        if (isEmpty()) {
            cout << "Bounded Stack is empty!" << endl;
            return;
        }
        
        cout << "Bounded Stack contents (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << data[i];
            if (i > 0) cout << " -> ";
        }
        cout << " [Min size: " << minSize << "]" << endl;
    }
    
    // Additional function specific to bounded stack
    void setMinSize(int newMin) {
        if (newMin >= 0 && newMin <= capacity) {
            minSize = newMin;
            cout << "Minimum size set to " << minSize << endl;
        } else {
            cout << "Invalid minimum size!" << endl;
        }
    }
};

// Function to demonstrate stack operations
void demonstrateStack(Stack* stack, const string& stackType) {
    cout << "\n=== " << stackType << " Operations ===" << endl;
    
    // Push some elements
    cout << "\nPushing elements:" << endl;
    stack->push(10);
    stack->push(20);
    stack->push(30);
    stack->push(40);
    
    // Display stack
    stack->display();
    
    // Peek at top element
    cout << "\nTop element: " << stack->peek() << endl;
    
    // Pop elements
    cout << "\nPopping elements:" << endl;
    stack->pop();
    stack->pop();
    
    // Display updated stack
    stack->display();
    
    // Show stack status
    cout << "\nStack Status:" << endl;
    cout << "Size: " << stack->getSize() << endl;
    cout << "Capacity: " << stack->getCapacity() << endl;
    cout << "Empty: " << (stack->isEmpty() ? "Yes" : "No") << endl;
    cout << "Full: " << (stack->isFull() ? "Yes" : "No") << endl;
}

int main() {
    cout << "=== Stack Implementation Using Virtual Functions ===\n\n";
    
    // Create different types of stacks
    IntStack intStack(8);
    BoundedStack boundedStack(10, 3);
    
    // Demonstrate integer stack
    demonstrateStack(&intStack, "Integer Stack");
    
    // Demonstrate bounded stack
    demonstrateStack(&boundedStack, "Bounded Stack");
    
    // Test bounded stack constraints
    cout << "\n=== Testing Bounded Stack Constraints ===" << endl;
    cout << "Current size: " << boundedStack.getSize() << endl;
    cout << "Minimum size: 3" << endl;
    
    // Try to pop below minimum size
    cout << "\nTrying to pop below minimum size:" << endl;
    boundedStack.pop();
    boundedStack.pop();
    boundedStack.pop();
    
    // Show final state
    boundedStack.display();
    
    // Demonstrate polymorphism
    cout << "\n=== Polymorphism Demonstration ===" << endl;
    Stack* stacks[2];
    stacks[0] = &intStack;
    stacks[1] = &boundedStack;
    
    for (int i = 0; i < 2; i++) {
        cout << "\nStack " << (i + 1) << ":" << endl;
        stacks[i]->display();
        cout << "Size: " << stacks[i]->getSize() << endl;
    }
    
    cout << "\n=== Program completed successfully ===" << endl;
    return 0;
}
