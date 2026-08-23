#pragma once

class Stack
{
private:
	char* data;
	int index;
	int capacity;
public:
	Stack(int size);
	~Stack();
	void push(char ch);
	char pop();
	char top();
	bool isEmpty();
	int size();
};

