#ifndef TREE_H
#define TREE_H

// Define a class for tree nodes
class Tree_Node {
public:
    int data; // Data to be stored in the node
    Tree_Node *right; // Pointer to the right child
    Tree_Node *left; // Pointer to the left child
    Tree_Node(int data) : right(NULL), left(NULL), data(data) {}; // Constructor
};

// Define a class for Binary Search Tree
class BinarySearchTree {
    Tree_Node *root; // Root node of the tree
    Tree_Node* deleteNodeRecursive(Tree_Node* node, int data); // Helper function for deletion

public:
    BinarySearchTree() : root(0) {} // Constructor

    void insertNode(int data); // Function to insert a node
    void deleteNode(int data); // Function to delete a node
    Tree_Node* minValueNode(Tree_Node* node); // Helper function to find the minimum value node
    bool lookup(int data); // Function to lookup a value
    void display(); // Function to display the tree
};

#endif // TREE_H