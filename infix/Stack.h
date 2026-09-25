#pragma once
#include "LinkedList.h"

class Stack
{
private:
	LinkedList* data;
	int index;
	int capacity;
public:
	Stack();
	~Stack();
	void push(char ch);
	char pop();
	char top();
	bool isEmpty();
	int size();
};

