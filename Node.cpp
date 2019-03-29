#include "Node.h"

class Node {

public:
	int id;
	std::string info;
	Node *parent;
	std::vector<Node *> children;


	Node::Node(Node *parent) : parent(parent)
	{
	}


	void add_child(Node *child) {
		children.push_back(child);
	}

};

