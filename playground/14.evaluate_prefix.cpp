#include<iostream>
#include<stack>
#include<string>

bool IsNumericDigit(char C) 
{
	if(C >= '0' && C <= '9') return true;
	return false;
}

bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/') return true;
	return false;
}

int PerformOperation(char operation, int operand1, int operand2)
{
	if(operation == '+') return operand1 +operand2;
	else if(operation == '-') return operand1 - operand2;
	else if(operation == '*') return operand1 * operand2;
	else if(operation == '/') return operand1 / operand2;

	else std::cout<<"Unexpected Error \n";
	return -1; 
}


int EvaluatePrefix(std::string expression)
{
	std::stack<int> S;

	for(int i = expression.length() -1 ;i >= 0;i--) {
		if(expression[i] == ' ' || expression[i] == ',') continue;
		else if(IsOperator(expression[i])) {
			int operand1 = S.top(); S.pop();
            int operand2 = S.top(); S.pop();
			int result = PerformOperation(expression[i], operand1, operand2);
			S.push(result);
		}
		else if(IsNumericDigit(expression[i])){
			int operand = 0; int multiplier = 1;
			while(i>= 0 && IsNumericDigit(expression[i])) {
				operand = multiplier * (expression[i] - '0') + operand; 
                multiplier = multiplier * 10;
				i--;
			}
			i++;
			S.push(operand);
		}
	}
	return S.top();
}

int main() 
{
	std::string expression; 
	std::cout<<"Enter Prefix Expression \n";
	std::getline(std::cin,expression);
	int result = EvaluatePrefix(expression);
	std::cout<<"Output = "<<result<<"\n";
}

//test
//- + * 2 3 * 5 4 9