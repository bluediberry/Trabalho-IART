#pragma once
#include <string>
#include <vector>
#include "Coord.h"

class Node
{
public:
	Node(Node *parent);

	void add_child(Node *child);
};

