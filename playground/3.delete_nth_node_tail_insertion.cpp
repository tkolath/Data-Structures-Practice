//add node to the end of the list
//delete the n-th node
#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* head; 

void insert(int data) {
    Node* temp1 = new Node();
    temp1 -> data = data; 
    temp1 -> next = nullptr; 
    if (head == nullptr) {
        temp1 -> next = head; 
        head = temp1; 
        return;
    }
    Node* temp2 = head; 
    while (temp2 -> next != nullptr) {
        temp2 = temp2 -> next; 
    }
    temp2 -> next = temp1;
}

void delete_node (int n) {
    Node* temp1 = head; 
    if (n==1) {
        head = temp1 -> next; 
        delete temp1; 
        temp1 = nullptr; 
        return; 
    }
    for (size_t i{}; i < n-2; i++) {
        temp1 = temp1 -> next; 
    }
    Node* temp2 = temp1 -> next; 
    temp1 -> next = temp2 -> next; 
    delete temp2; 
    temp2 = nullptr;    
}

void print() {
    Node* temp1 = head; 
    while (temp1 != nullptr) {
        std::cout << temp1 -> data << " ";
        temp1 = temp1 -> next; 
    }
    std::cout << std::endl; 
}


int main() {
    insert(3);
    insert(8);
    insert(4);
    insert(1);
    insert(2);
    insert(9);
    print();
    delete_node(6);
    print(); 
    return 0;
}