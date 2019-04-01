#pragma once

#include <vector>
#include <queue>
#include <list>
#include <limits>
#include <cmath>
#include "Coord.h"

using namespace std;

class Vertex {
public:
	int state; //state
	vector<Edge> adj;  // outgoing edges
	bool visited;          // auxiliary field
	Coord position;
	//Node *parent; //parent node
	char direction; //operator
	int depth; // depth of the node
	int cost; // path cost


	void addEdge(Vertex *dest, double w) {
		adj.push_back(Edge(dest, w));
	}

	Vertex(int state, vector<Edge> adj, bool visited, Coord position, char direction, int depth, int cost) {
		this->state = state;
		this->adj = adj;
		this->position = position;
		this->direction = direction;
		this->depth = depth;
		this->cost = cost;
	}

	Coord getPosition() {
		return this->position;
	}
	friend class Graph;
};


class Edge {
	Vertex * dest;      // destination vertex
	double weight;         // edge weight
public:
	Edge(Vertex *d, double w) {
		this->dest = d;
		this->weight = w;
	}
	friend class Graph;
	friend class Vertex;
};


class Graph {
	vector<Vertex *> vertexSet;    // vertex set


public:
	int state;
	Vertex *findVertex(Vertex v);
	bool addVertex(vector<Edge> adj, Coord position, char direction, int depth, int cost);
	bool addEdge(Vertex sourc, Vertex dest, double w);
	int getNumVertex();
	vector<Vertex *> getVertexSet();


};


int Graph::getNumVertex(){
	return vertexSet.size();
}


vector<Vertex *> Graph::getVertexSet() {
	return vertexSet;
}

Vertex * Graph::findVertex(Vertex v) {
	for (auto vx : vertexSet)
		if (vx->state == v.state)
			return vx;
	return NULL;
}


bool Graph::addVertex(vector<Edge> adj, Coord position, char direction, int depth, int cost) {
	this->state++;
	Vertex *v = new Vertex(state, adj, false, position, direction, depth, cost);
	vertexSet.push_back(v);
	return true;
}

bool Graph::addEdge(Vertex sourc, Vertex dest, double w) {
	auto v1 = findVertex(sourc);
	auto v2 = findVertex(dest);
	if (v1 == NULL || v2 == NULL)
		return false;
	v1->addEdge(v2, w);
	return true;
}





