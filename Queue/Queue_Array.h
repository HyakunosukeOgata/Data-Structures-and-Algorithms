#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

// Class definition for Queue_Array
class Queue_Array {
    private:
        int capacity; // The capacity of the queue
        int front;    // The index representing the front of the queue
        int back;     // The index representing the back of the queue
        int *queue;   // Pointer to the array used for storing queue elements
        void Doublecapacity(); // Private method to double the queue's capacity

    public:
        // Constructor to initialize the queue with a certain capacity
        Queue_Array() : capacity(5), front(-1), back(-1) {
            queue = new int[capacity];
        };

        // Method to add an element to the queue
        void Push(int x);

        // Method to remove the front element from the queue
        void Pop();

        // Method to check if the queue is empty
        bool IsEmpty();

        // Method to check if the queue is full
        bool IsFull();

        // Method to get the element at the front of the queue
        int getFront();

        // Method to get the element at the back of the queue
        int getBack();

        // Method to get the current number of elements in the queue
        int getSize();

        // Method to get the current capacity of the queue
        int getCapacity();
};

#endif // QUEUE_ARRAY_H
