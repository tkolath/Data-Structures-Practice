//implement linkedlist, insert at beginning
#include <iostream>

struct Node{
    int data;
    Node* next;
};
Node* head; 

void insert(int data) {
    Node* temp1 = new Node();
    temp1 -> data = data; 
    temp1 -> next = head; 
    head = temp1;
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
    int n, x; 
    head = nullptr; 
    std::cout << "How many nodes in this linked list? " << std::endl; 
    std::cin >> n; 
    for (size_t i {}; i < n; i++) {
        std::cout << "Number to Insert? " << std::endl; 
        std::cin >> x;
        insert(x);
        print();
    }
    return 0;
}