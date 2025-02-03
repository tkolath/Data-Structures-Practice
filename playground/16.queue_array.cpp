//queue array
#include <iostream>
#define MAX_SIZE 101

class Queue
{
private:
	int A[MAX_SIZE];
	int front, rear; 
public:
	Queue()
	{
		front = -1; 
		rear = -1;
	}

	bool IsEmpty()
	{
		return (front == -1 && rear == -1); 
	}

	bool IsFull()
	{
		return (rear+1)%MAX_SIZE == front ? true : false;
	}

	void Enqueue(int x)
	{
		std::cout<<"Enqueuing "<<x<<" \n";
		if(IsFull())
		{
			std::cout<<"Error: Queue is Full\n";
			return;
		}
		if (IsEmpty())
		{ 
			front = rear = 0; 
		}
		else
		{
		    rear = (rear+1)%MAX_SIZE;
		}
		A[rear] = x;
	}

	void Dequeue()
	{
		std::cout<<"Dequeuing \n";
		if(IsEmpty())
		{
			std::cout<<"Error: Queue is Empty\n";
			return;
		}
		else if(front == rear ) 
		{
			rear = front = -1;
		}
		else
		{
			front = (front+1)%MAX_SIZE;
		}
	}

	int Front()
	{
		if(front == -1)
		{
			std::cout<<"Error: cannot return front from empty queue\n";
			return -1; 
		}
		return A[front];
	}
	
	void Print()
	{
		int count = (rear+MAX_SIZE-front)%MAX_SIZE + 1;
		std::cout<<"Queue       : ";
		for(int i = 0; i <count; i++)
		{
			int index = (front+i) % MAX_SIZE;
			std::cout<<A[index]<<" ";
		}
		std::cout<<"\n\n";  
	}
};
int main()
{
   Queue Q;
   Q.Enqueue(2);  Q.Print();  
   Q.Enqueue(4);  Q.Print();  
   Q.Enqueue(6);  Q.Print();
   Q.Dequeue();	  Q.Print();
   Q.Enqueue(8);  Q.Print();
}