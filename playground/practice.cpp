//queue array
#include <iostream>
#define MAX_SIZE 3
class queue {
private:
    int rear, front;
    int A[MAX_SIZE];

public:
    queue() {
        rear = front = -1;
    }

    bool is_empty()
    {
        return (rear == -1 && front == -1);
    }

    bool is_full()
    {
        return (rear + 1) % MAX_SIZE == front;
    }

    bool enqueue(int x) {
        std::cout << "Queueing: " << x << std::endl;
        if (is_full())
        {
            std::cout << "Queue Max Size Reached" << std::endl; 
            return false;
        }
        if (is_empty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }
        A[rear] = x;
        return true; 
    }

    bool dequeue()
    {
        std::cout << "Dequeuing..." << std::endl; 
        if (is_empty())
        {
            std::cout << "Error: Cannot Dequeue Empty Queue\n";
            return false;
        }
        front = (front + 1) % MAX_SIZE;
        return true;
    }

    int Front()
    {
        if (is_empty()) 
        {
            std::cout << "Cannot return front of empty queue\n";
            return -1; 
        }
        return A[front];
    }
    
    void print()
    {
        std::cout << "Current Queue: ";
        int count = (rear + MAX_SIZE - front) % MAX_SIZE + 1;
        for (int i = 0; i < count; i++)
        {
            int index = (front + i) % MAX_SIZE;
            std::cout << A[index] << " ";
        } 
        std::cout << std::endl; 
    }
};

int main()
{
    queue q; 
    q.enqueue(5); q.print(); 
    q.enqueue(1); q.print(); 
    q.enqueue(8); q.print(); 
    std::cout << "Is full : " << std::boolalpha << q.is_full() << std::endl; 
    q.dequeue(); q.print(); 
}