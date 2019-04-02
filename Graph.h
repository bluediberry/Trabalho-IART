#pragma once

#include <vector>
#include <queue>
#include <list>
#include <limits>
#include <cmath>
#include "Coord.h"

using namespace std;

class Edge;

class Vertex {
public:
    int state; //state
    vector<Edge> adj;  // outgoing edges
    bool visited;          // auxiliary field
    Coord position;
    //Node *parent; //parent node
    char direction; //operator
    int depth = 0; // depth of the node
    int cost; // path cost
    friend class Graph;
    
    
    void addEdge(Vertex *dest, double w);
    
    Vertex(int state, vector<Edge> adj, bool visited, Coord position, char direction, int depth) {
        this->state = state;
        this->adj = adj;
        this->position = position;
        this->direction = direction;
        this->depth = depth;
    }
    
    /* Vertex(Coord position, char direction, int depth) {
     this->position = position;
     this->direction = direction;
     this->depth = depth;
     }*/
    
    
    Coord getPosition() {
        return this->position;
    }
    
    char getDirection() {
        return this->direction;
    }
    
    void addDepth() {
        this->depth++;
    }
    int getDepth() {
        return this->depth;
    }
    friend class Graph;
};


class Edge {
    double weight;         // edge weight
public:
    Vertex* dest;      // destination vertex
    Edge(Vertex *d, double w);
    friend class Graph;
    friend class Vertex;
    Vertex getDest();
};

Edge::Edge(Vertex *d, double w) {
    this->dest = d;
    this->weight = w;
}

Vertex Edge::getDest(){ return *dest;}

class Graph {
    vector<Vertex *> vertexSet;    // vertex set
    
    
public:
    int state;
    Vertex *findVertex(Vertex v);
    Vertex * addVertex(Coord position, char direction, int depth);
    bool addEdge(Vertex sourc, Vertex dest, double w);
    int getNumVertex();
    vector<Vertex *> getVertexSet();
    
    
};

void Vertex::addEdge(Vertex *dest, double w) {
    this->adj.push_back(Edge(dest, w));
}


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


Vertex * Graph::addVertex(Coord position, char direction, int depth) {
    this->state++;
    vector<Edge> e;
    Vertex *v = new Vertex(state, e, false, position, direction, depth);
    this->vertexSet.push_back(v);
    return v;
}

bool Graph::addEdge(Vertex sourc, Vertex dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == NULL || v2 == NULL)
        return false;
    v1->addEdge(v2, w);
    return true;
}





