#include <iostream>
#include <stack>
#include <string>

bool is_operator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') return true;
    return false; 
}

bool is_numeric_digit(char c) {
    if (c >= '0' && c <= '9') return true; 
    return false;
}

int perform_operation(char operation, int operand1, int operand2) {
    if (operation == '+') return operand1 + operand2;
    else if (operation == '-') return operand1 - operand2; 
    else if (operation == '*') return operand1 * operand2; 
    else if (operation == '/') return operand1 / operand2; 

    else std::cout << "Unexpected Error\n";
    return -1; 
}

int evaluate_postfix(std::string expression){
    std::stack <int> s;
    for (size_t i{};i < expression.length(); i++){
        if (expression[i] == ' ' || expression[i] == ',') continue;
        else if (is_operator(expression[i])) {
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();
            int result = (perform_operation(expression[i], operand1, operand2));
            s.push(result);
        }
        else if (is_numeric_digit(expression[i])) {
            int operand = 0; 
            while (i < expression.length() && is_numeric_digit(expression[i])) {
                operand = (operand*10) + (expression[i]-'0');
                i++;
            }
            i--;
            s.push(operand);
        }
    } 
    return s.top();
}

int main() {
    std::string expression;
    std::cout << "Enter expression: " << std::endl; 
    std::getline(std::cin, expression);
    int result = evaluate_postfix(expression);
    std::cout << "Output : " << result << "\n";

}