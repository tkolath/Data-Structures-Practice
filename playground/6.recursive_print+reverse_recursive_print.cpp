//recursive print + reverse recursive print
#include <iostream> 

struct Node {
    int data;
    Node* next;
};

Node* insert(Node* head, int data) {
    Node* temp1 = new Node(); 
    temp1 -> data = data;
    temp1 -> next = nullptr;
    if (head == nullptr) {
        temp1 -> next = head; 
        head = temp1; 
        return head; 
    }
    Node* temp2 = head; 
    while (temp2 -> next != nullptr) {
        temp2 = temp2 -> next;
    }
    temp2 -> next = temp1; 
    return head; 
}

void print(Node* head) { 
    if (head == nullptr) return; 
    std::cout << head -> data << " ";
    print(head -> next);
}

void reverse_print(Node* head) {
    if (head == nullptr) return; 
    reverse_print(head -> next);
    std::cout << head -> data << " ";
}

int main() {
    Node* head = nullptr; 
    head = insert(head, 3);
    head = insert(head, 7);
    head = insert(head, 8);
    head = insert(head, 3);
    head = insert(head, 3);
    head = insert(head, 6);
    head = insert(head, 4);
    print(head);
    std::cout << std::endl; 
    std::cout << "Reversed Print : " << std::endl;
    reverse_print(head);
    std::cout << std::endl; 

    return 0; 
}