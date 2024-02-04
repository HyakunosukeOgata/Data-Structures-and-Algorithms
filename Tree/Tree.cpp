#include <iostream>
#include <stack>
#include "Tree.h"

using namespace std;

// Implementation of insertNode function
void BinarySearchTree::insertNode(int data) {
    Tree_Node *newNode = new Tree_Node(data); // Create a new node
    // If tree is empty, make the new node the root
    if (!root) {
        root = newNode;
        return;
    }

    // Otherwise, find the correct position for the new node
    Tree_Node *temp = root;
    while (true) {
        // Navigate to the left or right depending on the data
        if (data < temp->data) {
            if (!temp->left) {
                temp->left = newNode;
                break;
            }
            temp = temp->left;
        } else {
            if (!temp->right) {
                temp->right = newNode;
                break;
            }
            temp = temp->right;
        }
    }
}

// Implementation of deleteNode function
void BinarySearchTree::deleteNode(int data) {
    root = deleteNodeRecursive(root, data); // Call helper function to delete
}

// Recursive helper function for node deletion
Tree_Node* BinarySearchTree::deleteNodeRecursive(Tree_Node* node, int data) {
    if (node == NULL) {
        cout << "Node not found." << endl;
        return node;
    }

    // Navigate to the node to be deleted
    if (data < node->data) {
        node->left = deleteNodeRecursive(node->left, data);
    } 
    else if (data > node->data) {
        node->right = deleteNodeRecursive(node->right, data);
    } 
    else {
        // Node with only one child or no child
        if (node->left == NULL) {
            Tree_Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == NULL) {
            Tree_Node* temp = node->left;
            delete node;
            return temp;
        }

        // Node with two children: Get the inorder successor
        Tree_Node* temp = minValueNode(node->right);

        // Copy the inorder successor's content to this node
        node->data = temp->data;

        // Delete the inorder successor
        node->right = deleteNodeRecursive(node->right, temp->data);
    }

    return node;
}

// Function to find the node with minimum value
Tree_Node* BinarySearchTree::minValueNode(Tree_Node* node) {
    Tree_Node* current = node;
    // Navigate to the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to lookup a value in the tree
bool BinarySearchTree::lookup(int data){
    if (root == NULL){
        cout << "Tree Empty please Insert values" << endl;
        return false;
    }
    Tree_Node *temp = root;
    // Traverse the tree
    while (temp != NULL){
        if (temp->data > data){
            temp = temp->left;
        }
        else if (temp->data < data){
            temp = temp->right;
        }
        else if (temp->data == data){
            return true; // Found the value
        }
    }
    return false; // Value not found
}

// Function to display the tree in inorder traversal
void BinarySearchTree::display(){
    stack<Tree_Node *> s;
    Tree_Node *temp = root;

    // Inorder traversal using a stack
    while (temp != NULL || s.empty() == false) {

        // Reach the leftmost Node of the current Node
        while (temp != NULL) {
            s.push(temp);
            temp = temp->left;
        }

        // Current must be NULL at this point
        temp = s.top();
        cout << temp->data << "  "; // Print the data
        s.pop();

        // We have visited the node and its left subtree. Now, it's right subtree's turn
        temp = temp->right;
    }
}