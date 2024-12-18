//linked list: // reverse the linked list // print using recursion forwards and backwards
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
    temp2 -> next= temp1; 
}

void print(Node* head) {
    Node* temp1 = head; 
    if (temp1 == nullptr) return; 
    std::cout << temp1 -> data << " ";
    print(temp1->next);
}


void reverse_list(){
    Node* curr = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    while (curr != nullptr) {
        next = curr -> next; 
        curr -> next = prev; 
        prev = curr;
        curr = next;
    }
    head = prev; 
}

void reverse_print(Node* head) {
    Node* temp1 = head; 
    if (temp1 == nullptr) return;
    reverse_print(temp1 -> next);
    std::cout << temp1 -> data << " "; 
}

int main() {
    head = nullptr;
    int n;
    insert(5);
    insert(2);
    insert(9);
    insert(5);
    insert(2);
    print(head);
    std::cout << std::endl;
    std::cout << "Reversed List : " ;
    // reverse_list();
    // print(head);
    reverse_print(head);  
    return 0;
}