#include <iostream>
#define MAX_SIZE 101

int a[MAX_SIZE];
int top = -1;

void push(int x) {
    if (top == MAX_SIZE - 1) {
        std::cout << "Stack overflow" << std::endl;
        return; 
    }
    a[++top] = x;
}

void pop() {
    if (top == -1) {
        std::cout << "Error: No Element to Pop" << std::endl; 
        return; 
    }
    top--; 
}

int Top() {
    return a[top];
}

void print() {
    std::cout << "Stack : ";
    for (size_t i {}; i <= top; i++) {
        std::cout << a[i] << " "; 
    } 
    std::cout << std::endl; 
}

int main() {
    push(2); print();
    push(5); print();
    push(10); print();
    pop(); print();
    push(12); print();

    return 0; 
}