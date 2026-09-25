#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList()
{
	top = nullptr;
}

void LinkedList::insertFirst(char data)
{
	Node* node = new Node(data);
	
	if (top == nullptr)
	{
		top = node;
		return;
	}

	node->next = top;
	top = node;
}

char LinkedList::deleteFirst()
{
	Node* temp = top;

	if (top->next == nullptr)
	{
		top = nullptr;
	}
	else
	{
		top = top->next;
	}

	char tempData = temp->getData();
	delete temp;
	return tempData;
}

bool LinkedList::isEmpty()
{
	return top == nullptr;
}

char LinkedList::printTop()
{
	return top->getData();
}

void LinkedList::print()
{
	Node* current = top;
	while (current != nullptr)
	{
		std::cout << current->getData() << std::endl;
		current = current->next;
	}
	std::cout << std::endl;
}