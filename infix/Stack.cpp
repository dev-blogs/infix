#include "Stack.h"
#include "LinkedList.h"
#include <stdexcept>

Stack::Stack()
{
	data = new LinkedList();
}

Stack::~Stack()
{
	delete data;
}

void Stack::push(char value)
{
	data->insertFirst(value);
}

char Stack::pop()
{
	if (data->isEmpty())
	{
		throw std::runtime_error("Stack is empty");
	}
	return data->deleteFirst();
}

char Stack::top()
{
	if (data->isEmpty())
	{
		throw std::runtime_error("Stack is empty");
	}
	return data->printTop();
}

bool Stack::isEmpty()
{
	return data->isEmpty();
}
