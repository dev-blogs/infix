#pragma once
#include "LinkedList.h"

class Stack
{
private:
	LinkedList* data;
public:
	Stack();
	~Stack();
	void push(char ch);
	char pop();
	char top();
	bool isEmpty();
};

