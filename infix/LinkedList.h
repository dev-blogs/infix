#pragma once
#include "Node.h"

class LinkedList
{
private:
	Node* top;
public:
	LinkedList();
	void insertFirst(char data);
	char deleteFirst();
	bool isEmpty();
	char printTop();
	void print();
};

