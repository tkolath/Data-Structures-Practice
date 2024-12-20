//implement a doubly linked list, inserting at head and tail
#include <iostream>

struct Node {
    int data; 
    Node* next; 
    Node* prev;
};

Node* head;

Node* NewNode(int data) {
    Node* temp1 = new Node(); 
    temp1 -> data = data; 
    temp1 -> next = nullptr; 
    temp1 -> prev = nullptr; 
    return temp1;
}

void insert_at_head(int data) {
    Node* temp1 = NewNode(data);
    if (head == nullptr) {
        head = temp1; 
        return; 
    }
    head -> prev = temp1; 
    temp1 -> next = head; 
    head = temp1; 
}


void insert_at_tail(int data) {
    Node* temp1 = NewNode(data);
    if (head == nullptr) {
        head = temp1; 
        return;
    }
    Node* temp2 = head; 
    while (temp2 -> next != nullptr) {
        temp2 = temp2 -> next; 
    }
    temp2 -> next = temp1; 
    temp1 -> prev = temp2; 
}

void print(){
    Node* temp1 = head;
    while (temp1 != nullptr) {
        std::cout << temp1 -> data << " ";
        temp1 = temp1 -> next; 
    }
    std::cout << std::endl;
}

void reverse_print() {
    Node* temp1 = head; 
    while (temp1 -> next != nullptr) {
        temp1 = temp1 -> next; 
    }
    while (temp1 != nullptr) {
        std::cout << temp1 -> data << " ";
        temp1 = temp1 -> prev;
    }
    std::cout <<std::endl; 
}


int main() {
    insert_at_head(5);
    insert_at_head(1);
    insert_at_head(8);
    print(); 
    insert_at_tail(3);
    insert_at_tail(7);
    insert_at_tail(8);
    print(); 
    reverse_print(); 
    return 0;
}