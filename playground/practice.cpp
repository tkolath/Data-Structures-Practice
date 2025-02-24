//queue array
#include <iostream>
#define MAX_SIZE 5

class Queue {
private:
    int A[MAX_SIZE];
    int front, rear; 
public:
    Queue() {
        front = rear = -1; 
    }

    bool is_empty() {
        return (front == -1 && rear == -1);
    }

    bool is_full() {
        return (rear + 1) % MAX_SIZE == front;
    }

    void enqueue(int x) {
        std::cout << "Queueing: " << x << std::endl; 
        if (is_full()) {
            std::cout << "Error: Queue is full" << std::endl; 
            return; 
        }
        else if (is_empty()) {
            front = rear = 0; 
        }
        else {
            rear = (rear + 1) % MAX_SIZE;
        }
        A[rear] = x;
    }

    void dequeue() {
        std::cout << "Dequeuing \n";
        if (is_empty()) {
            std::cout << "Error: Cannot dequeue empty queue" << std::endl; 
        }
        else if (front == rear) {
            front = rear = -1; 
        }
        else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    int Front() {
        if (is_empty()) {
            std::cout << "Error: cannot return top of empty Queue" << std::endl; 
        }
        return A[front];
    }

    void print() {
        std::cout << "Current Queue: \n" << std::endl; 
        int count = (front + MAX_SIZE - front) % MAX_SIZE + 1;
        for (int i = 0; i < count; i++) {
            int index = (front + i) % MAX_SIZE; 
            std::cout << A[index] << " ";
        }
        std::cout << std::endl; 
    }
};

int main() {
    Queue q; 
    q.enqueue(5); q.print();
    q.enqueue(1); q.print();
    q.enqueue(8); q.print();
    std::cout << q.is_full() << std::endl; 
    q.enqueue(3); q.print();
    q.enqueue(7); q.print();
    std::cout << q.is_full() << std::endl; 
    q.dequeue(); 
}