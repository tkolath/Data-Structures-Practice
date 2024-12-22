#include <iostream>

struct Node{
    int data;
    Node* link;
};

Node* top = nullptr; 

void push(int x) {
    Node* temp1 = new Node();
    temp1 -> data = x;
    temp1 -> link = top; 
    top = temp1;
}

void pop() {
    Node* temp1 = top;
    if (top == nullptr) return;
    top = top -> link; 
    delete temp1; 
    temp1 = nullptr; 
}

void Top() {
    if (top == nullptr) return;
    std::cout << top -> data;
}

bool is_empty() {
    if (top == nullptr) return true; 
    return false;
}

void print() {
    Node* temp1 = top;
    while (temp1 != nullptr) {
        std::cout << temp1 -> data << " ";
        temp1 = temp1 -> link; 
    }
    std::cout << std::endl; 
}

int main() {
    push(5); print(); 
    push(1); print(); 
    push(8); print(); 
    pop(); print(); 
    Top(); 
    // is_empty();  
    std::cout << std::endl << std::boolalpha << is_empty() << std::endl; 
    pop(); pop();
    std::cout << std::endl << std::boolalpha << is_empty() << std::endl; 

    std::cout << std::endl;



    return 0; 
}