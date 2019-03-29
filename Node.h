#pragma once
#include <string>
#include <vector>

class Node
{
public:
	Node(Node *parent);

	void add_child(Node *child);
};

