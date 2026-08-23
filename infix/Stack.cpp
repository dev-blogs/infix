#include "Stack.h"
#include <stdexcept>

Stack::Stack(int capacity) 
	: index(0), capacity(capacity)
{
	data = new char[capacity];
}

Stack::~Stack()
{
	delete[] data;
}

void Stack::push(char value)
{
	if (index == capacity)
	{
		throw std::runtime_error("Stack is full");
	}
	data[index++] = value;
}

char Stack::pop()
{
	if (index == 0)
	{
		throw std::runtime_error("Stack is empty");
	}
	return data[--index];
}

char Stack::top()
{
	if (index == 0)
	{
		throw std::runtime_error("Stack is empty");
	}
	return data[index - 1];
}

int Stack::size()
{
	return index;
}

bool Stack::isEmpty()
{
	return index == 0;
}
