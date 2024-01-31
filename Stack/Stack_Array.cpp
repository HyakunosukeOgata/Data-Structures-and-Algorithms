#include "Stack_Array.h"
#include <iostream>

// Method to double the capacity of the stack
void Stack_Array::DoubleCapacity(){
    capacity *= 2;                         // Double the current capacity
    int *newStack = new int[capacity];     // Create a new stack with doubled capacity
    
    // Copy elements from the old stack to the new stack
    for (int i = 0 ; i < capacity/2; i++) {  
        newStack[i] = stack[i];
    }
    
    delete [] stack;            // Delete the old stack
    stack = newStack;           // Point stack to the new stack
}

// Method to add an element to the stack
void Stack_Array::Push(int x){
    // Double the capacity if the stack is full
    if (top == capacity - 1) {  
        DoubleCapacity();
    }
    stack[++top] = x;           // Place the new element on top of the stack
}

// Method to remove the top element from the stack
void Stack_Array::Pop(){
    // Check if the stack is empty
    if (IsEmpty()) {         
        std::cout << "Stack is empty.\n";
        return;
    }
    top--;                      // Decrease top to remove the top element
}

// Method to check if the stack is empty
bool Stack_Array::IsEmpty(){
    return (top == -1);         // Return true if top is -1, indicating an empty stack
}

// Method to get the top element of the stack
int Stack_Array::Top(){
    // Check if the stack is empty
    if (IsEmpty()) {    
        std::cout << "Stack is empty.\n";
        return -1;
    }
    return stack[top];          // Return the top element of the stack
}

// Method to get the current number of elements in the stack
int Stack_Array::getSize(){
    return top+1;               // Return the number of elements in the stack
}
