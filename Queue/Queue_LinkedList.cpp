#include "Queue_LinkedList.h"
#include <iostream>

void Queue_List::Push(int x){
    
    if (IsEmpty()) {
        front = new QueueNode(x);
        back = front;
        size++;
        return;
    }
    
    QueueNode *newNode = new QueueNode(x);
    back->next = newNode;
    back = newNode;         // update back pointer
    size++;
}

void Queue_List::Pop(){
    
    if (IsEmpty()) {
        std::cout << "Queue is empty.\n";
        return;
    }
    
    QueueNode *deletenode = front;
    front = front->next;    // update front pointer
    delete deletenode;
    deletenode = 0;
    size--;
}

int Queue_List::getFront(){
    
    if (IsEmpty()) {
        std::cout << "Queue is empty.\n";
        return -1;
    }
    
    return front->data;
}

int Queue_List::getBack(){
    
    if (IsEmpty()) {
        std::cout << "Queue is empty.\n";
        return -1;
    }
    
    return back->data;
}

bool Queue_List::IsEmpty(){
    
//    return (size == 0);
    return ((front && back) == 0);
}

int Queue_List::getSize(){
    
    return size;
}