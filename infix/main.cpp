#include <iostream>
#include <string>
#include "stack.h"

bool isOperand(char ch);
bool isOperator(char ch);
bool priority_less_then(char opTop, char opThis);
bool isBracket(char ch);

int main()
{
	Stack stack(10);
	std::string expression = "2+3*(4-5)";
	std::string output = "";
	std::cout << expression << std::endl;

	std::cout << "is opTop less then opThis: " << priority_less_then('*', '+') << std::endl;

	for (int i = 0; i < expression.size(); i++)
	{
		char element = expression[i];
		if (isOperand(element))
		{
			output.push_back(element);
		}
		else
		{
			if (stack.isEmpty())
			{
				stack.push(element);
			}
			else
			{				
				if (!stack.isEmpty())			
				{
					if (element == '(')
					{
						stack.push(element);
						continue;
					}
					else if (element == ')')
					{
						char el = stack.pop();
						while (el != '(' && !stack.isEmpty())
						{
							output.push_back(el);
							el = stack.pop();
						}
						continue;
					}

					char opTop = stack.pop();
					if (opTop == '(')
					{
						stack.push(opTop);
						stack.push(element);
						continue;
					}
					char opThis = element;
					if (!priority_less_then(opTop, opThis))
					{
						output.push_back(opTop);						
						stack.push(opThis);
					}
					else
					{
						stack.push(opTop);
						stack.push(opThis);
					}
				}				
			}
		}
	}
	while (!stack.isEmpty())
	{
		output.push_back(stack.pop());
	}

	std::cout << "output: " << output << std::endl;

	return 0;
}

bool isOperand(char ch)
{
	if (ch - '0' >= 0 && ch - '0' <= 9)
	{
		return true;
	}
	return false;
}

bool isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
	{
		return true;
	}
	return false;
}

bool priority_less_then(char opTop, char opThis)
{
	if ((opTop == '+' || opTop == '-') 
		&& (opThis == '*' || opThis == '/'))
	{
		return true;
	}
	return false;
}

bool isBracket(char ch)
{
	if (ch == '(' || ch == ')')
	{
		return true;
	}
	return false;
}