//string reversal with stack
#include <iostream>
#include <stack>

void reverse(char *c) {
    std::stack<char> s; 
    int n = strlen(c);

    for (size_t i{}; i<n; i++) {
        s.push(c[i]);
    }

    for (size_t i{}; i<n; i++) {
        c[i] = s.top(); 
        s.pop();
    }
}

int main() {
    char c[51];
    std::cout << "enter string" << std::endl; 
    std::cin >> c; 
    reverse(c);
    printf("result = %s \n", c);
    return 0; 
}