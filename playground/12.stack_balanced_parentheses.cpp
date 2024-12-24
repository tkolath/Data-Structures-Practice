#include <iostream>
#include <stack>
#include <string>

bool are_pair(char opening, char closing){
    if(opening == '(' && closing ==')') return true;
    else if (opening == '{' && closing == '}') return true;
    else if (opening == '[' && closing == ']') return true;
    return false;
}

bool balanced_paranthesis(std::string exp) {
    std::stack <char> s;
    for (size_t i{}; i<exp.length(); i++) {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') s.push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if(s.empty() || !are_pair(s.top(), exp[i])) return false;
            else s.pop();  
        }
    }
    return s.empty() ? true:false;
}

int main() {
    std::string expression; 
    std::cout << "Enter an expression : ";
    std::cin >> expression;
    if(balanced_paranthesis(expression)) {
        std::cout << "Balanced\n";
    }
    else {
        std::cout << "Not Balanced\n";
    }
}