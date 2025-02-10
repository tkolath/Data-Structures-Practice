//queue linked list
#include <iostream>

struct Node {
    int data;
    Node* next; 
};

Node* front = nullptr;
Node* rear = nullptr; 

void Enqueue(int x) {
    Node* temp1 = new Node(); 
    temp1 -> data = x;
    temp1 -> next = nullptr;
    if (front == nullptr && rear == nullptr)
    {
        front = rear = temp1; 
        return; 
    }
    rear -> next = temp1; 
    rear = temp1; 
}

void Dequeue()
{
    Node* temp1 = front; 
    if (front == nullptr)
    {
        std::cout << "Error: Empty Queue\n";
        return;
    }
    if (front == rear)
    {
        front = rear = nullptr; 
    }
    else
    {
        front = front -> next; 
    }
    delete temp1; 
    temp1 = nullptr; 
}

int Front()
{
    if (front == nullptr)
    {
        std::cout << "Empty Queue\n" << std::endl;
        return -1;
    }
    return front -> data; 
}


void Print() 
{
    Node* temp1 = front;
    while (temp1 != nullptr)
    {
        std::cout << temp1 -> data << " ";
        temp1 = temp1 -> next;
    }
    std::cout << std::endl;
}
int main(){
	Enqueue(2); Print(); 
	Enqueue(4); Print();
	Enqueue(6); Print();
	Dequeue();  Print();
	Enqueue(8); Print();
}