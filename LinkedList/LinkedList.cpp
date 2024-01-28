#include "LinkedList.h"

// Prints all the elements in the linked list.
void LinkedList::Print() {
    ListNode* curr = first; // Start from the first node of the list
    while(curr != nullptr) {
        printf("%d, ", curr->value); // Print the value of the current node
        curr = curr->next;           // Move to the next node
    }
}

// Adds an element at the end of the linked list.
void LinkedList::Push_back(int x) {
    ListNode* new_Node = new ListNode(x); // Create a new node
    if (first == nullptr) {
        first = new_Node;  // If the list is empty, make the new node the first node
        return;
    }
    ListNode* curr = first;
    while(curr->next != nullptr) {
        curr = curr->next;  // Traverse to the last node of the list
    }
    curr->next = new_Node;  // Append the new node at the end of the list
}

// Adds an element at the beginning of the linked list.
void LinkedList::Push_front(int x) {
    ListNode* new_node = new ListNode(x); // Create a new node
    new_node->next = first;               // New node points to the current first node
    first = new_node;                     // Update first to the new node
}

// Deletes all nodes with a value equal to x from the linked list.
void LinkedList::Delete(int x) {
    // Delete nodes from the beginning of the list
    while (first != nullptr && first->value == x) {
        ListNode* tmp = first;
        first = first->next;
        delete tmp;
    }

    // Return if the list is empty
    if (first == nullptr) return;

    ListNode* curr = first;
    // Traverse and delete nodes with value equal to x
    while (curr->next != nullptr) {
        if (curr->next->value == x) {
            ListNode* tmp = curr->next;
            curr->next = curr->next->next;
            delete tmp;
        } else {
            curr = curr->next;
        }
    }
}

// Clears the linked list, deleting all nodes.
void LinkedList::Clear() {
    // Loop while the list is not empty
    while (first != nullptr) {
        ListNode* current = first; // Set current pointer to the current first node

        first = first->next; // Move first to the next node

        delete current; // Delete the current node
        current = nullptr; // Set current to nullptr to avoid dangling pointer
    }
    // When the loop ends, the list is completely cleared
}

// Reverses the linked list.
void LinkedList::Reverse() {
    // Check if the list is empty or has only one node, no need to reverse
    if (first == nullptr || first->next == nullptr) {
        return;
    }

    ListNode *previous = nullptr,    // To track the previous node of the current node
             *current = first,        // Start from the beginning node and traverse the list
             *preceding = first->next; // Save the next node of the current node

    // Traverse through the list
    while (preceding != nullptr) {
        current->next = previous;    // Reverse the link of the current node
        previous = current;          // Move previous to the current position
        current = preceding;         // Move current to the preceding position
        preceding = preceding->next; // Move preceding to the next node
    }

    // After the last iteration, link the last node to the previous node
    current->next = previous;
    // Update first to point to the new first node (the original end node of the list)
    first = current;
}

