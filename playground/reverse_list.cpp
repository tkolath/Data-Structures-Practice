//reverse the linked list
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

void print() {
    Node* temp1 = head; 
    while (temp1 != nullptr) {
        std::cout << temp1 -> data << " ";
        temp1 = temp1 -> next;
    }
    std::cout << std::endl;
}

void reverse() {
    Node* current = head; 
    Node* next = nullptr; 
    Node* prev = nullptr;
    while(current != nullptr) {
        next = current -> next; 
        current -> next = prev; 
        prev = current;
        current = next;
    }
    head = prev;
}

int main() {
    insert(3);
    insert(7);
    insert(8);
    insert(3);
    insert(3);
    insert(6);
    insert(4);
    print(); 
    reverse(); 
    print();

    return 0;
}