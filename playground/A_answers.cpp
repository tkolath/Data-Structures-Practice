#include <iostream>

//Implement a Linked List and Declare Head
struct Node {
    int data; 
    Node* next; 
};

Node* head = nullptr;

//Print Linked List
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
void DeleteNthNode(int n) {
    Node* temp1 = head; 
    if (n == 1) {
        head = temp1 -> next; 
        delete temp1; 
        temp1 = nullptr; 
        return; 
    }
    for (size_t i{}; i < n-2; i++) {
        temp1 = temp1 -> next; 
    }
    Node* temp2 = temp1 -> next; 
    temp1 -> next = temp2 -> next;
    delete temp2; 
    temp2 = nullptr; 
}

//Reverse Iteratively
void ReverseIteratively() {
    Node* current  = head; 
    Node* prev = nullptr;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current -> next; 
        current -> next = prev; 
        prev = current;
        current = next; 
    }
    head = prev; 
}

//Reverse List Recursively
void ReverseRecursively(Node* temp1) {
    if (temp1 -> next == nullptr) {
        head = temp1; 
        return; 
    }
    ReverseRecursively(temp1 -> next);
    temp1 -> next -> next = temp1; 
    temp1 -> next = nullptr; 
}

//Recursive Print
void RecursivePrint(Node* temp1) {
    if (temp1 == nullptr) return; 
    std::cout << temp1 -> data << " ";
    RecursivePrint(temp1 -> next);
}

//Reverse Recursive Print
void ReverseRecursivePrint(Node* temp1) {
    if (temp1 == nullptr) return;
    ReverseRecursivePrint(temp1 -> next);
    std::cout << temp1 -> data << " ";
}

//Implement Doubly Linked List and Declare head
struct Node2 {
    int data; 
    Node2* prev; 
    Node2* next; 
};

Node2* head2 = nullptr; 

//GetNewNode
Node2* GetNewNode(int data) {
    Node2* temp1 = new Node2(); 
    temp1 -> data = data;
    temp1 -> prev = temp1 -> next = nullptr; 
    return temp1; 
}

//Insert at Head of Doubly Linked List
void InsertHeadDoublyLinked(int data) {
    Node2* temp1 = GetNewNode(data); 
    if (head2 == nullptr) {
        head2 = temp1; 
        return;
    }
    temp1 -> next = head2;
    head2 -> prev  = temp1; 
    head2 = temp1; 
}

//Insert at Tail of Doubly Linked List
void InsertTailDoublyLinked(int data) {
    Node2* temp1 = GetNewNode(data);
    if (head2 == nullptr) {
        head2 = temp1; 
        return; 
    }
    Node2* temp2 = head2; 
    while(temp2 -> next != nullptr) {
        temp2 = temp2 -> next; 
    }
    temp2 -> next = temp1; 
    temp1 -> prev = temp2; 
}

//Print Doubly Linked List Forward
void PrintForwardDoublyLinked() {
    Node2* temp1 = head2; 
    while (temp1 != nullptr) {
        std::cout << temp1 -> data << " ";
        temp1 = temp1 -> next; 
    }
    std::cout << std::endl; 
}

//Print Doubly Linked List Backward
void PrintBackwardDoublyLinked() {
    Node2* temp1 = head2; 
    while (temp1 -> next != nullptr) {
        temp1 = temp1 -> next;
    }
    while (temp1 != nullptr) {
        std::cout << temp1 -> data << " ";
        temp1 = temp1 -> prev; 
    }
    std::cout << std::endl; 
}


int main() {
    InsertHead(5);
    InsertHead(1);
    InsertHead(8);
    std::cout << "Head Insertions: "; Print(); 
    InsertTail(3);
    InsertTail(7);
    InsertTail(8);
    std::cout << "Tail Insertions: "; Print();
    InsertNthNode(9,1);
    InsertNthNode(5,3);
    InsertNthNode(2,5);
    std::cout << "n-th Node Insertions: "; Print(); 
    DeleteNthNode(3);
    std::cout << "Deleted n-th Node: "; Print();
    ReverseIteratively(); 
    std::cout << "Iteratively Reversed Linked List: "; Print(); 
    ReverseRecursively(head);
    std::cout << "Iteratively Reversed Linked List: "; Print(); 
    std::cout << "Recursive Print: "; RecursivePrint(head); std::cout << "\n";
    std::cout << "Reverse Recursive Print: "; ReverseRecursivePrint(head); std::cout << "\n";
    InsertHeadDoublyLinked(1);
    InsertHeadDoublyLinked(7);
    InsertHeadDoublyLinked(3);
    InsertHeadDoublyLinked(8);
    std::cout << "Doubly Linked List Head Insertion: "; PrintForwardDoublyLinked();
    InsertTailDoublyLinked(1);
    InsertTailDoublyLinked(8);
    InsertTailDoublyLinked(2);
    InsertTailDoublyLinked(4);
    std::cout << "Doubly Linked List Tail Insertion: "; PrintForwardDoublyLinked();
    std::cout << "Doubly Linked List Print Backwards: "; PrintBackwardDoublyLinked();
}