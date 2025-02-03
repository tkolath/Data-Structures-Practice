#include <iostream>
#include <stack>
#include <string>

bool is_operator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '$') return true; 
    return false; 
}

bool is_operand(char c) {
    if (c >= '0' && c <= '9') return true; 
    if (c >= 'a' && c <= 'z') return true; 
    if (c >= 'A' && c <= 'Z') return true; 
    return false;
}

bool is_right_associative(char c) {
    if (c == '$') return true; 
    return false; 
}

int get_operator_weight(char c) {
    int weight = -1;
    switch(c) {
        case '+':
        case '-':
            weight = 1;
        case '*':
        case '/': 
            weight = 2;
        case '$':
            weight = 3;
    }
    return weight;
}

int has_higher_precedence(char op1, char op2) {
    int op1_weight = get_operator_weight(op1);
    int op2_weight = get_operator_weight(op2);

    if (op1_weight == op2_weight) {
        if(is_right_associative(op1)) return false;
        else return true;
    }
    return op1_weight > op2_weight ? true : false; 
}

std::string infix_to_postfix(std::string expression) {
    std::stack <char> s; 
    std::string postfix = "";
    for (int i = 0; i < expression.length(); i++) {
        if(expression[i] == ' ' || expression[i] == ',') continue; 
        else if (is_operator(expression[i])) {
            while (!s.empty() && s.top() != '(' && has_higher_precedence(s.top(), expression[i])) {
                postfix += s.top(); 
                s.pop(); 
            }
            s.push(expression[i]);
        }
        else if (is_operand(expression[i])) {
            postfix += expression[i];
        }
        else if (expression[i] == '(') {
            s.push(expression[i]);
        }
        else if (expression[i] == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
    }
    while (!s.empty()) {
        postfix += s.top(); 
        s.pop();
    }
    return postfix;
}

int main() {
    std::string expression; 
    std::cout << "Enter infix expression\n";
    std::getline(std::cin, expression);
    std::string postfix = infix_to_postfix(expression);
    std::cout << "Output: " << postfix << std::endl; 
}

// ((A + B) * C - D) * E -> AB + C * D - E *