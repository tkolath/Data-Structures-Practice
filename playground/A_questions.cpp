#include <iostream>

//Implement a Linked List and Declare Head
struct Node {


};

Node* head = nullptr; 

//Print Linked List
void Print() {

}
//Insert at the Begining
void InsertHead(int data) {

}

//Insert at Tail
void InsertTail(int data) {

}

//Insert at the n-th Node
void InsertNthNode(int data, int n) {

}

//Delete the n-th Node
void DeleteNthNode(int n) {

}

//Reverse Iteratively
void ReverseIteratively() {

}

//Reverse List Recursively
void ReverseRecursively(Node* temp1) {

}

//Recursive Print
void RecursivePrint(Node* temp1) {

}

//Reverse Recursive Print
void ReverseRecursivePrint(Node* temp1) {

}

//Implement Doubly Linked List and Declare head
struct Node2 {

};

Node2* head2 = nullptr; 

//GetNewNode
Node2* GetNewNode(int data) {

}

//Insert at Head of Doubly Linked List
void InsertHeadDoublyLinked(int data) {

}

//Insert at Tail of Doubly Linked List
void InsertTailDoublyLinked(int data) {

}

//Print Doubly Linked List Forward
void PrintForwardDoublyLinked() {

}

//Print Doubly Linked List Backward
void PrintBackwardDoublyLinked() {

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
    std::cout << "Recursively Reversed Linked List: "; Print(); 
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