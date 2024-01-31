#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H 

// Class for implementing a stack using an array
class Stack_Array{
private:
    int top;                // Index of the top element in the stack
    int capacity;           // Current capacity of the stack array
    int *stack;             // Pointer to the stack array
    void DoubleCapacity();  // Private method to double the capacity of the stack

public:
    // Constructor to initialize the stack
    // Sets top to -1 indicating an empty stack and initializes the capacity to 1
    Stack_Array():top(-1),capacity(1){    
        stack = new int[capacity]; // Allocating memory for the stack
    }
    void Push(int x);       // Method to add an element to the top of the stack
    void Pop();             // Method to remove the top element from the stack
    bool IsEmpty();         // Method to check if the stack is empty
    int Top();              // Method to get the top element of the stack
    int getSize();          // Method to get the current number of elements in the stack
};

#endif // STACK_ARRAY_H
