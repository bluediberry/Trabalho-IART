#include "Node.h"

class Node {

public:
//	int id;
	Coord position; //state
	Node *parent; //parent node
	char direction; //operator
	int depth; // depth of the node
	int cost; // path cost

	std::vector<Node *> children;


	Node::Node(Node *parent) : parent(parent)
	{
	}


	void add_child(Node *child) {
		children.push_back(child);
	}

};

