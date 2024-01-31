#ifndef QUEUE_LINKEDLIST_H
#define QUEUE_LINKEDLIST_H

// Struct representing a node in the queue
struct QueueNode {
    int data;          // Data stored in the node
    QueueNode *next;   // Pointer to the next node in the queue
    QueueNode(): data(0), next(nullptr) {}     // Default constructor initializing the node with default values
    QueueNode(int x): data(x), next(nullptr) {} // Constructor initializing the node with a specified integer value
};

// Class representing a queue implemented using a linked list
class Queue_List {
private:
    QueueNode *front; // Pointer to the front node of the queue
    QueueNode *back;  // Pointer to the back node of the queue
    int size;         // The current size (number of elements) of the queue

public:
    Queue_List(): front(nullptr), back(nullptr), size(0) {}; // Constructor initializing an empty queue

    void Push(int x); // Method to add an element to the back of the queue
    void Pop();       // Method to remove the front element from the queue
    bool IsEmpty();   // Method to check if the queue is empty
    int getFront();   // Method to get the value of the front element
    int getBack();    // Method to get the value of the back element
    int getSize();    // Method to get the current size of the queue
};

#endif //QUEUE_LINKEDLIST_H
