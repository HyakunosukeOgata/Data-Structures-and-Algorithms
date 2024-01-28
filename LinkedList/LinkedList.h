#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Forward declaration of the LinkedList class
class LinkedList;

// Class representing a node in the linked list
class ListNode{
    private:
        int value;       // Stores the value of the node
        ListNode* next;  // Pointer to the next node in the list

    public:
        // Default constructor initializing the node with default values
        ListNode() : value(0), next(nullptr){}      
        
        // Constructor initializing the node with a specified integer value
        ListNode(int v) : value(v), next(nullptr){} 
        
        // Declare LinkedList as a friend class to allow direct access to ListNode's members
        friend class LinkedList;                    
};


// Class representing a singly linked list
class LinkedList{
    private:
        ListNode* first; // Pointer to the first node of the linked list

    public:
        // Constructor: Initializes the linked list as empty
        LinkedList() : first(nullptr){};    

        // Method to print all elements in the linked list
        void Print();                       
        
        // Method to add an element at the end of the linked list
        void Push_back(int x);              
        
        // Method to add an element at the beginning of the linked list
        void Push_front(int x);             
        
        // Method to delete all nodes with a value equal to x in the linked list
        void Delete(int x);                 
        
        // Method to clear the linked list, deleting all nodes
        void Clear();                       
        
        // Method to reverse the linked list
        void Reverse();                     
};

#endif // LINKEDLIST_H
