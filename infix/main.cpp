#include <iostream>
#include <string>
#include "stack.h"

bool isOperand(char ch);
bool isOperator(char ch);
int precedence(char op);
void processOperator(Stack& stack, std::string& output, char opThis);
void processClosingParenthesis(Stack& stack, std::string& output);
int calculate(std::string& postfix_expr, Stack& stack);
int charToInt(char ch);
char intToChar(int value);

int main()
{
    std::string expression = "2+3*(4+5)";
    std::string output;

    Stack stack(expression.size());

    std::cout << expression << std::endl;

    for (char element : expression)
    {
        if (isOperand(element))
        {
            output.push_back(element);
        }
        else if (element == '(')
        {
            stack.push(element);
        }
        else if (element == ')')
        {
            processClosingParenthesis(stack, output);
        }
        else if (isOperator(element))
        {
            processOperator(stack, output, element);
        }
    }

    while (!stack.isEmpty())
    {
        output.push_back(stack.pop());
    }

    std::cout << "output: " << output << std::endl;

    int result = calculate(output, stack);
    std::cout << "Result is: " << result << std::endl;

    return 0;
}

int calculate(std::string& postfix_expr, Stack& stack)
{
	for (char element : postfix_expr)
	{
		if (isOperand(element))
		{
			stack.push(element);
			continue;
		}

		int b = charToInt(stack.pop());
		int a = charToInt(stack.pop());		

		if (element == '+')
		{
			stack.push(intToChar(a + b));
		}
		else if (element == '-')
		{
			stack.push(intToChar(a - b));
		}
		else if (element == '*')
		{
			stack.push(intToChar(a * b));
		}
		else if (element == '/')
		{
			stack.push(intToChar(a / b));
		}
	}

	return charToInt(stack.pop());
}

int charToInt(char ch)
{
	return ch - '0';
}

char intToChar(int value)
{
	return char(value + '0');
}

bool isOperand(char ch)
{
	return ch >= '0' && ch <= '9';
}

bool isOperator(char ch)
{
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int precedence(char op)
{
	if (op == '+' || op == '-')
		return 1;

	if (op == '*' || op == '/')
		return 2;

	return 0;
}

void processOperator(Stack& stack, std::string& output, char opThis)
{
	while (!stack.isEmpty())
	{
		char opTop = stack.pop();

		if (opTop == '(')
		{
			stack.push(opTop);
			break;
		}

		if (precedence(opTop) < precedence(opThis))
		{
			stack.push(opTop);
			break;
		}

		output.push_back(opTop);
	}

	stack.push(opThis);
}

void processClosingParenthesis(Stack& stack, std::string& output)
{
    while (!stack.isEmpty())
    {
        char opTop = stack.pop();
        if (opTop == '(') break;
        output.push_back(opTop);
    }
}