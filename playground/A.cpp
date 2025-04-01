#include <iostream>

//Implement a Linked List
struct Node {
    int data; 
    Node* next; 
};

Node* head = nullptr;

void Print() {
    Node* temp1 = head; 
    while (temp1 != nullptr) {
        std::cout << temp1 -> data << " ";
        temp1 = temp1 -> next; 
    }
    std::cout << std::endl; 
}
//Insert at the Begining
void InsertHead(int data) {
    Node* temp1 = new Node(); 
    temp1 -> data = data; 
    temp1 -> next = head; 
    head = temp1;
}

//Insert at Tail
void InsertTail(int data) {
    Node* temp1 = new Node(); 
    temp1 -> data = data; 

    Node* temp2 = head; 
    while(temp2 -> next != nullptr) {
        temp2 = temp2 -> next; 
    }
    temp2 -> next = temp1;
}

//Insert at the n-th Node
void InsertNthNode(int data, int n) {
    Node* temp1 = new Node(); 
    temp1 -> data = data; 

    if (n == 1) {
        temp1 -> next = head; 
        head = temp1; 
        return; 
    }
    Node* temp2 = head; 
    for (size_t i{}; i < n-2; i++) {
        temp2 = temp2 -> next; 
    }
    temp1 -> next = temp2 -> next; 
    temp2 -> next = temp1; 

}

//Delete the n-th Node

int main() {
    InsertHead(5);
    InsertHead(1);
    InsertHead(8);
    Print(); 
    InsertTail(3);
    InsertTail(7);
    InsertTail(8);
    Print();
    InsertNthNode(9,1);
    InsertNthNode(5,3);
    InsertNthNode(2,5);
    Print(); 
}