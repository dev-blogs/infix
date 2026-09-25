#include "Node.h"

Node::Node(char data)
{
	this->data = data;
	next = nullptr;
}

char Node::getData()
{
	return data;
}