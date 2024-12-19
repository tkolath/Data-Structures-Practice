//insert at the n-th node
#include <iostream>

struct Node {
    int data;
    Node* next; 
};

Node* head; 

void insert(int data, int n) {
    Node* temp1 = new Node(); 
    temp1 -> data = data; 
    temp1 -> next = nullptr; 
    if (n==1) {
        temp1 -> next = head; 
        head = temp1;
        return;
    }
    Node* temp2 = head; 
    for (size_t i {}; i < n-2; i++) {
        temp2 = temp2 -> next; 
    }
    temp1 -> next = temp2 -> next; 
    temp2 -> next = temp1; 
}

void print() {
    Node* temp1 = head; 
    while (temp1 != nullptr) {
        std::cout << temp1 -> data << " ";
        temp1 = temp1->next;
    }
    std::cout << std::endl;
}

int main() {
    head = nullptr; 
    insert(6,1);
    insert(3,1);
    insert(7,2);
    insert(2,3);
    insert(9,5);
    insert(4,2); // 347369
    print(); 

    return 0;
}