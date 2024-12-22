#include <iostream>
#include <stack>

struct Node {
    int data; 
    Node* next;
};
Node* head = nullptr;

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
};

void print() {
    Node* temp1 = head; 
    while (temp1 != nullptr) {
        std::cout << temp1 -> data << " ";
        temp1 = temp1 -> next; 
    }
    std::cout << std::endl;
};

void reverse() {
    if(head == nullptr) return;
    std::stack<struct Node*> s;
    Node* temp1 = head;
    while(temp1 != nullptr) {
        s.push(temp1);
        temp1 = temp1-> next;
    }
    temp1 = s.top(); 
    head = temp1; 
    s.pop(); 
    while(!s.empty()) {
        temp1->next = s.top();
        s.pop(); 
        temp1 = temp1 -> next; 
    }
    temp1->next = nullptr; 
}

int main() {
    insert(3);
    insert(7);
    insert(8);
    insert(3);
    print(); 
    reverse(); 
    print(); 
}