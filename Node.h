#pragma once
#include <string>
#include <vector>
#include "Coord.h"

class Node
{
public:
	Node(Node *parent);
	Coord position; //state
	Node *parent; //parent node
	char direction; //operator
	int depth; // depth of the node
	int cost; // path cost


private:
	std::vector<Node *> children;

	void add_child(Node *child);
};

