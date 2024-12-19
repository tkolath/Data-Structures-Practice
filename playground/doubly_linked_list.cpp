#include <iostream>

struct Node {
    int data; 
    Node* next; 
    Node* prev; 
};

Node* head;

Node* get_new_node(int x) {
    Node* temp1 = new Node(); 
    temp1 -> data = x; 
    temp1 -> next = nullptr; 
    temp1 -> prev = nullptr;
    return temp1; 
};

void insert_at_head(int x){
    Node* temp1 = get_new_node(x);
    if (head == nullptr) {
        head = temp1; 
        return;
    }
    head -> prev = temp1;
    temp1 -> next = head; 
    head = temp1;
};

void insert_at_tail(int x) {
    Node* temp1 = get_new_node(x);
    if (head == nullptr) {
        head = temp1;
        return;
    }
    Node* temp2 = head; 
    while (temp2-> next != nullptr) {
        temp2 = temp2 -> next;
    }
    temp2 -> next = temp1; 
    temp1 -> prev = temp2;
}

void print() {
    Node* temp1 = head; 
    std::cout << "forward : ";
    while (temp1 != nullptr) {
        std::cout << temp1->data << " ";
        temp1 = temp1 -> next; 
    }
    std::cout << std::endl;
}

void reverse_print(){
    Node* temp1 = head; 
    if (temp1 == nullptr) return; 
    while (temp1 -> next != nullptr) {
        temp1 = temp1 -> next;
    }
    std::cout << "Reverse : ";
    while(temp1 != nullptr) {
        std::cout << temp1 -> data << " ";
        temp1 = temp1 -> prev;
    }
    std::cout << std::endl; 
}

int main() {
    head = nullptr; 
    insert_at_head(2); print(); reverse_print();
    insert_at_head(4); print(); reverse_print();
    insert_at_head(6); print(); reverse_print();
    insert_at_tail(8); print(); reverse_print();
    insert_at_tail(10); print(); reverse_print();
    insert_at_tail(12); print(); reverse_print();
    return 0;
}