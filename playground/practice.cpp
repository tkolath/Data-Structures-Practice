//evaluate postfix
#include <iostream>
#include <stack>
#include <string>

bool is_digit(char c) {
    if (c >= '0' && c <= '9') return true;
    return false;
}

bool is_operator(char c) {
    if (c == '+' || c== '-' || c == '*' || c == '/') return true; 
    return false;
}

int perform_operation(char c, int operand1, int operand2) {
    if (c == '+') return operand1 + operand2; 
    else if (c == '-') return operand1 - operand2; 
    else if (c == '*') return operand1 * operand2; 
    else if (c == '/') return operand1 / operand2;
    else std::cout << "Unexpected error \n";
    return -1;
}

int evaluate_postfix(std::string exp) {
    std::stack <int> s;
    for (int i{}; i<exp.length(); i++) {
        if (exp[i] == ' ' || exp[i] == ',') continue;
        else if (is_operator(exp[i])) {
            int operand2 = s.top(); s.pop(); 
            int operand1 = s.top(); s.pop(); 
            int result = perform_operation(exp[i], operand1, operand2);
            s.push(result);
        }
        else if (is_digit(exp[i])) {
            int operand = 0;
            while(i < exp.length() && is_digit(exp[i])) {
                operand = (operand * 10) + (exp[i] - '0');
                i++;
            }
            i--;
            s.push(operand);
        }
    }
    return s.top();
}

int evaluate_prefix(std::string exp) {
    std::stack <int> s;
    for (int i = exp.length(); i>=0; i--) {
        if (exp[i] == ' ' || exp[i] == ',') continue;
        else if (is_operator(exp[i])) {
            int operand1 = s.top(); s.pop(); 
            int operand2 = s.top(); s.pop(); 
            int result = perform_operation(exp[i], operand1, operand2);
            s.push(result);
        }
        else if (is_digit(exp[i])) {
            int operand = 0;
            while(i >= 0 && is_digit(exp[i])) {
                operand = (operand * 10) + (exp[i] - '0');
                i--;
            }
            i++;
            s.push(operand);
        }
    }
    return s.top();
}


int main() {
    std::string expression; 
    std::cout << "Enter expression : " << std::endl; 
    std::getline(std::cin, expression);
    int result = evaluate_prefix(expression);
    std::cout << "Output : " << result << std::endl;
}