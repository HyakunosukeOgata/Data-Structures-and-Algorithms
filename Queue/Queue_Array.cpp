#include "Queue_Array.h"
#include <iostream>

// Double the capacity of the queue when it's full.
void Queue_Array::Doublecapacity() {
    capacity *= 2; // Double the current capacity.
    int *newQueue = new int[capacity]; // Create a new queue with the updated capacity.

    int j = -1;
    // Copy elements from the old queue to the new queue.
    for (int i = front + 1; i <= back; i++) {
        j++;
        newQueue[j] = queue[i];
    }

    front = -1; // Reset front.
    back = j; // Set back to the last element in the new queue.
    delete [] queue; // Delete the old queue.
    queue = newQueue; // Point to the new queue.
}

// Add an element to the back of the queue.
void Queue_Array::Push(int x) {
    if (IsFull()) {
        Doublecapacity(); // Double the capacity if the queue is full.
    }
    queue[++back] = x; // Increment 'back' and add the new element.
}

// Check if the queue is empty.
bool Queue_Array::IsEmpty() {
    return (front == back); // Queue is empty if front and back are equal.
}

// Check if the queue is full.
bool Queue_Array::IsFull() {
    return (back + 1 == capacity); // Queue is full if back is at the last position of the array.
}

// Remove an element from the front of the queue.
void Queue_Array::Pop() {
    if (IsEmpty()) {
        std::cout << "Queue is empty.\n"; // Print message if the queue is empty.
        return;
    }
    front++; // Increment 'front' to remove the front element.
}

// Get the element at the front of the queue.
int Queue_Array::getFront() {
    if (IsEmpty()) {
        std::cout << "Queue is empty.\n"; // Print message if the queue is empty.
        return -1;
    }
    return queue[front + 1]; // Return the front element.
}

// Get the element at the back of the queue.
int Queue_Array::getBack() {
    if (IsEmpty()) {
        std::cout << "Queue is empty.\n"; // Print message if the queue is empty.
        return -1;
    }
    return queue[back]; // Return the back element.
}

// Get the current size of the queue.
int Queue_Array::getSize() {
    return (back - front); // Size is calculated as the difference between back and front.
}

// Get the current capacity of the queue.
int Queue_Array::getCapacity() {
    return capacity; // Return the capacity of the queue.
}
