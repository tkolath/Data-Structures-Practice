//Queue - Linked List implementation
#include <iostream>

struct Node {
	int data;
	struct Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

void Enqueue(int x) {
	Node* temp = new Node(); 
	temp -> data = x; 
	temp -> next = nullptr;
	if(front == nullptr && rear == nullptr){
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

void Dequeue() {
	Node* temp = front;
	if(front == nullptr) {
		std::cout << "Queue is Empty\n";
		return;
	}
	if(front == rear) {
		front = rear = nullptr;
	}
	else {
		front = front->next;
	}
	delete temp;
    temp = nullptr; 
}

int Front() {
	if(front == NULL) {
		printf("Queue is empty\n");
		return;
	}
	return front->data;
}

void Print() {
	Node* temp = front;
	while(temp != NULL) {
		std::cout << temp->data << " ";
		temp = temp->next;
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

