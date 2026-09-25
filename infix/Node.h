#pragma once
class Node
{
private:
	char data;
public:
	Node* next;

public:
	Node(char data);
	char getData();
};
