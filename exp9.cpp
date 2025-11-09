// Write a program to create a stack using virtual function

#include <iostream>
using namespace std;

class Stack {
public:
    virtual void push(int x) = 0; // pure virtual function push
    virtual int pop() = 0;  // pure virtual function pop
    virtual bool isEmpty() = 0; // pure virtual function isEmpty
    virtual void display() {} // virtual function display
    virtual ~Stack() {} // virtual destructor
};

class ArrayStack : public Stack {
private:
    int* arr; // dynamic array to hold stack elements
    int top; // index of the top element
    int capacity; // maximum capacity of the stack
    
public:
    ArrayStack(int size) {
        arr = new int[size]; // allocate memory for stack
        capacity = size; // set stack capacity
        top = -1; // initialize top to -1
    }

    void push(int x) override { // override push function
        if (top == capacity - 1) { // check for stack overflow
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x; // increment top and add element
    }

    int pop() override { // override pop function
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        cout << "Popped element: ";
        return arr[top--]; // return top element and decrement top
    }

    void display() override { // override display function
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout <<  arr[i] << " "; // print stack elements
        }
        cout << endl;
    }

    bool isEmpty() override { // override isEmpty function
        return top == -1; // return true if stack is empty
    }

    ~ArrayStack() { // destructor to free memory
        delete[] arr; // free allocated memory
    }
};

int main() {
    ArrayStack* stack = new ArrayStack(5);
    
    stack->push(10);
    stack->push(20);
    stack->push(30);
    
    stack->display();
    
    cout << stack->pop() << endl;
    cout << stack->pop() << endl;
    
    cout << stack->isEmpty() << endl; // 0 (false)
    
    cout << stack->pop() << endl;
    
    cout << stack->isEmpty() << endl; // 1 (true)
    
    delete stack;
}