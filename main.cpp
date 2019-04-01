#include <iostream>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <unistd.h>
#include "Coord.h"
#include "Graph.h"

using namespace std;

const int MazeHeight = 18;
const int MazeWidth = 18;

char Maze[MazeWidth][MazeHeight] =
{
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 'T', 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1 },
    { 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1 },
    { 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1 },
    { 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 },
    { 1, 0, 0, 'R', 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1 },
    { 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1 },
    { 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

const int Wall = 1;
const int Free = 0;
const char Target = 'T';
const char Robot = 'R';


Coord StartingPoint(10,3);
Coord RobotPosition(StartingPoint);
Coord EndingPoint(3, 12);


void print_maze(){
    
    //cout << "Starting Point: "<< Maze[StartingPoint.X][StartingPoint.Y] << endl;
    for(int i = 0; i < MazeHeight-1; i++){
        for(int j = 0; j < MazeWidth; j++){
            if(Maze[i][j] == Wall){
                cout << " # ";
            }
            else if(Maze[i][j] == Free){
                cout << "   ";
            }
            else if(Maze[i][j] == Target){
                cout << " T ";
            }
            else if(Maze[i][j] == Robot){
                cout << " R ";
            }
            
        }
        
        cout << endl;
    }
}

vector<char> AvailableMoves(int x, int y) {
    vector<char> moves;
    if (Maze[x - 1][y] == Free || Maze[x - 1][y] == Target)
        moves.push_back('U');
    if (Maze[x + 1][y] == Free || Maze[x + 1][y] == Target)
        moves.push_back('D');
    if (Maze[x][y - 1] == Free || Maze[x][y - 1] == Target)
        moves.push_back('L');
    if (Maze[x][y + 1] == Free || Maze[x][y + 1] == Target)
        moves.push_back('R');
    return moves;
}

Coord NextPosition(Coord c, char move) {
    int newX = c.X;
    int newY = c.Y;
    if (move == 'U') {
        while (Maze[newX - 1][newY] == 0 || Maze[newX - 1][newY] == 'T')
            newX--;
    }
    if (move == 'D') {
        while (Maze[newX + 1][newY] == 0 || Maze[newX + 1][newY] == 'T')
            newX++;
    }
    if (move == 'L') {
        while (Maze[newX][newY - 1] == 0 || Maze[newX][newY - 1] == 'T')
            newY--;
    }
    if (move == 'R') {
        while (Maze[newX][newY + 1] == 0 || Maze[newX][newY] == 'T')
            newY++;
    }
    
    Coord newCoord(newX, newY);
    return newCoord;
}


void Left() {
    Maze[StartingPoint.X][StartingPoint.Y] = Robot;
    while (Maze[StartingPoint.X][StartingPoint.Y - 1] == 0 || Maze[StartingPoint.X][StartingPoint.Y - 1] == 'T') {
        Maze[StartingPoint.X][StartingPoint.Y] = Free;
        Maze[StartingPoint.X][StartingPoint.Y - 1] = 'R';
        StartingPoint.Y--;
    }
    print_maze();
    sleep(1);
}

void Right() {
    Maze[StartingPoint.X][StartingPoint.Y] = Robot;
    while (Maze[StartingPoint.X][StartingPoint.Y + 1] == 0|| Maze[StartingPoint.X][StartingPoint.Y + 1] == 'T') {
        Maze[StartingPoint.X][StartingPoint.Y] = Free;
        Maze[StartingPoint.X][StartingPoint.Y + 1] = 'R';
        StartingPoint.Y++;
    }
    print_maze();
    sleep(1);
}

void Up() {
    Maze[StartingPoint.X][StartingPoint.Y] = Robot;
    while (Maze[StartingPoint.X - 1][StartingPoint.Y] == 0 || Maze[StartingPoint.X - 1][StartingPoint.Y] == 'T') {
        Maze[StartingPoint.X][StartingPoint.Y] = Free;
        Maze[StartingPoint.X - 1][StartingPoint.Y] = 'R';
        StartingPoint.X--;
    }
    print_maze();
    sleep(1);
}

void Down() {
    Maze[StartingPoint.X][StartingPoint.Y] = Robot;
    while (Maze[StartingPoint.X + 1][StartingPoint.Y] == 0 || Maze[StartingPoint.X + 1][StartingPoint.Y] == 'T') {
        Maze[StartingPoint.X][StartingPoint.Y] = Free;
        Maze[StartingPoint.X + 1][StartingPoint.Y] = 'R';
        StartingPoint.X++;
    }
    print_maze();
    sleep(1);
}



void Solve()
{
    int n;
    n = rand()%4;
    
    switch (n) {
        case 0:
            Up();
            break;
            
        case 1:
            Down();
            break;
        case 2:
            Left();
            break;
        case 3:
            Right();
            break;
        default: {break;}
    }
}

void addChildren(Graph g, Coord position, int depth, int cost){
    
    vector<char> moves = AvailableMoves(position.X, position.Y);
    
    Vertex *v = new Vertex(position, NULL, depth, cost);
    
    while (depth < 10) {
        for (int i = 0; i < moves.size(); i++) {
            depth++;
            cost++;
            if (moves[i] == 'U') {
                g.addVertex(NextPosition(position, 'U'), NULL, depth, cost);
                Vertex *nextv = new Vertex(NextPosition(position, 'U'), NULL, depth, cost);
                g.addEdge(*v, *nextv, 1);
                addChildren(g, NextPosition(position, 'U'), depth, cost);
            }
            else if (moves[i] == 'D') {
                g.addVertex(NextPosition(position, 'D'), NULL, depth, cost);
                Vertex *nextv = new Vertex(NextPosition(position, 'D'), NULL, depth, cost);
                g.addEdge(*v, *nextv, 1);
                addChildren(g, NextPosition(position, 'D'), depth, cost);
            }
            else if (moves[i] == 'R') {
                g.addVertex(NextPosition(position, 'R'), NULL, depth, cost);
                Vertex *nextv = new Vertex(NextPosition(position, 'R'), NULL, depth, cost);
                g.addEdge(*v, *nextv, 1);
                addChildren(g, NextPosition(position, 'R'), depth, cost);
            }
            else if (moves[i] == 'L') {
                g.addVertex(NextPosition(position, 'L'), NULL, depth, cost);
                Vertex *nextv = new Vertex(NextPosition(position, 'L'), NULL, depth, cost);
                g.addEdge(*v, *nextv, 1);
                addChildren(g, NextPosition(position, 'L'), depth, cost);
            }
        }
    }
}


Graph Create_Graph(){
    
    Graph *g = new Graph();
    
    int depth = 0;
    int cost = 0;
    
    g->addVertex(StartingPoint, NULL, depth, cost);
    
    Vertex *v = new Vertex(StartingPoint, NULL, depth, cost);
    
    vector<char> moves = AvailableMoves(StartingPoint.X, StartingPoint.Y);
    
    for (int i = 0; i < moves.size(); i++) {
        depth++;
        cost++;
        if (moves[i] == 'U') {
            g->addVertex(NextPosition(StartingPoint, 'U'), NULL, depth, cost);
            Vertex *nextv = new Vertex(NextPosition(StartingPoint, 'U'), NULL, depth, cost);
            g->addEdge(*v, *nextv, 1);
            addChildren(*g, NextPosition(StartingPoint, 'U'), depth, cost);
        }
        else if (moves[i] == 'D') {
            g->addVertex(NextPosition(StartingPoint, 'D'), NULL, depth, cost);
            Vertex *nextv = new Vertex(NextPosition(StartingPoint, 'D'), NULL, depth, cost);
            g->addEdge(*v, *nextv, 1);
            addChildren(*g, NextPosition(StartingPoint, 'D'), depth, cost);
        }
        else if (moves[i] == 'R') {
            g->addVertex(NextPosition(StartingPoint, 'R'), NULL, depth, cost);
            Vertex *nextv = new Vertex(NextPosition(StartingPoint, 'R'), NULL, depth, cost);
            g->addEdge(*v, *nextv, 1);
            addChildren(*g, NextPosition(StartingPoint, 'R'), depth, cost);
        }
        else if (moves[i] == 'L') {
            g->addVertex(NextPosition(StartingPoint, 'L'), NULL, depth, cost);
            Vertex *nextv = new Vertex(NextPosition(StartingPoint, 'L'), NULL, depth, cost);
            g->addEdge(*v, *nextv, 1);
            addChildren(*g, NextPosition(StartingPoint, 'L'), depth, cost);
        }
        
    }
    
    return *g;
}


void dfsVisit(Vertex *v, vector<Vertex *> & res) {
    v->visited = true;
    res.push_back(v);
    typename vector<Edge>::iterator it;
    for(it = v->adj.begin(); it != v->adj.end(); it++){
        if(!it->dest){
            dfsVisit(it->dest, res);
        }
    }
}


vector<Vertex *> DFS( )
{
    Graph g = Create_Graph();
    
    print_maze();
    sleep(1);
    
    
    vector<Vertex *> res;
    vector<Vertex *> vertexSet = g.getVertexSet();
    typename vector<Vertex *>::const_iterator it;
    
    for(it = vertexSet.begin(); it != vertexSet.end(); it++){
        (*it)->visited = false;
    }
    
    
    for(it  = vertexSet.begin(); it != vertexSet.end(); it++){
        if(!(*it)->visited){
            dfsVisit(*it, res);
        }
    }
    return res;
}


void Solve_manual()
{
    int n;
    
    cout << "What direction do you want to move in?" << endl;
    
    vector<char> moves = AvailableMoves(StartingPoint.X,StartingPoint.Y);
    
    if (find(moves.begin(), moves.end(), 'U') != moves.end()) {
        cout << "[0] Up" << endl;
        /*Coord newC = NextPosition(StartingPoint, 'U');
         cout << newC.X << ", " << newC.Y;*/
    }
    if (find(moves.begin(), moves.end(), 'D') != moves.end()) {
        cout << "[1] Down" << endl;
        /*Coord newC = NextPosition(StartingPoint, 'D');
         cout << newC.X << ", " << newC.Y;*/
    }
    if (find(moves.begin(), moves.end(), 'L') != moves.end()) {
        cout << "[2] Left" << endl;
        /*Coord newC = NextPosition(StartingPoint, 'L');
         cout << newC.X << ", " << newC.Y;*/
    }
    if (find(moves.begin(), moves.end(), 'R') != moves.end()) {
        cout << "[3] Right" << endl;
        /*Coord newC = NextPosition(StartingPoint, 'R');
         cout << newC.X << ", " << newC.Y;*/
    }
    cin >> n;
    
    switch (n) {
        case 0:
            Up();
            break;
            
        case 1:
            Down();
            break;
        case 2:
            Left();
            break;
        case 3:
            Right();
            break;
        default: {break;}
    }
    
}

int main() {
    
    print_maze();
    
    int choice;
    int algorithm;
    
    
    cout << "What mode do you want to play?" << endl;
    cout << "[1] Manual" << endl;
    cout << "[2] Computer" << endl;
    cin >> choice;
    
    if(choice == 1){
        while(StartingPoint.X != EndingPoint.X || StartingPoint.Y != EndingPoint.Y){
            Solve_manual();
        }
    }
    else if(choice == 2){
        cout << "What algorithm should I use?" << endl;
        cout << "[1] Depth first search" << endl;
        cout << "[2] Breadth first search" << endl;
        cout << "[3] Iterative deepening search" << endl;
        cout << "[4] Uniform cost search" << endl;
        cout << "[5] Greedy search" << endl;
        cout << "[6] A* search" << endl;
        cin >> algorithm;
        
        while(StartingPoint.X != EndingPoint.X || StartingPoint.Y != EndingPoint.Y){
            DFS();
        }
    }
    
    
    cout << "Congrats!" << endl;
    return 0;
}

