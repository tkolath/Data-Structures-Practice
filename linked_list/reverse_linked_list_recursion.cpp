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
        temp2 = temp2->next;
    }
    temp2 -> next = temp1; 
}

void print() {
    Node* temp1 = head; 
    while (temp1 != nullptr) {
        std::cout << temp1->data << " ";
        temp1 = temp1 -> next;
    }
    std::cout << std::endl;
}

void reverse_list(Node* temp1) {
    if (temp1-> next == nullptr) {
        head = temp1;
        return; 
    }
    reverse_list(temp1->next);
    temp1->next->next = temp1;
    temp1->next = nullptr; 
}

int main() {
    int x;
    insert(3); 
    insert(2); 
    insert(8); 
    insert(5); 
    insert(3); 
    insert(9); 
    print();
    reverse_list(head);
    std::cout << "Reversed List Using Recursion -> " << std::endl;
    print();
    return 0;
}