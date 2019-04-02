#include <unistd.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <stdio.h>
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
vector<Coord> graphPos;

void addChildren(Graph g, Vertex *v){
    
    //cout << "Add children X: " << v->getPosition().X << " Y: "<< v->getPosition().Y << endl;
    vector<Coord>::iterator it;
    
    int flag  = 0;

    vector<char> moves = AvailableMoves(v->getPosition().X, v->getPosition().Y);
    
    for (int i = 0; i < moves.size(); i++) {
        flag = 0;
        v->addDepth();
        if (moves[i] == 'U' && v->getDirection()!='D') {
            //the next position isnt in the graph yet
            for (it = graphPos.begin(); it != graphPos.end(); it++) {
                if(it->X == NextPosition(v->getPosition(), 'U').X && it->Y == NextPosition(v->getPosition(), 'U').Y){
                    flag = 1;
                }

            }
            if(flag != 1){
                Vertex *nextv = g.addVertex(NextPosition(v->getPosition(), 'U'), 'U', v->getDepth());
                graphPos.push_back(NextPosition(v->getPosition(), 'U'));
                
               cout << "(U) X: "<< nextv->getPosition().X << " Y: " << nextv->getPosition().Y << endl;
                
                g.addEdge(*v, *nextv, 1);
                addChildren(g, nextv);
                
            }
            
   
        }
        if (moves[i] == 'D' && v->getDirection() != 'U') {
            
            for (it = graphPos.begin(); it != graphPos.end(); it++) {
                if(it->X == NextPosition(v->getPosition(), 'D').X && it->Y == NextPosition(v->getPosition(), 'D').Y){
                    flag = 1;
                }
            }
            if(flag != 1){

                Vertex *nextv = g.addVertex(NextPosition(v->getPosition(), 'D'), 'D', v->getDepth());
                graphPos.push_back(NextPosition(v->getPosition(), 'D'));
                
                cout << "(D) X: "<< nextv->getPosition().X << " Y: " << nextv->getPosition().Y << endl;
                
                g.addEdge(*v, *nextv, 1);
                addChildren(g, nextv);
            }
            
        }
        if (moves[i] == 'R' && v->getDirection() != 'L') {
            for (it = graphPos.begin(); it != graphPos.end(); it++) {
                if(it->X == NextPosition(v->getPosition(), 'R').X && it->Y == NextPosition(v->getPosition(), 'R').Y){
                    flag = 1;
;
                }
            }
            if(flag != 1){
                    Vertex *nextv = g.addVertex(NextPosition(v->getPosition(), 'R'), 'R', v->getDepth());
                    graphPos.push_back(NextPosition(v->getPosition(), 'R'));
                    
                    cout << "(R) X: "<< nextv->getPosition().X << " Y: " << nextv->getPosition().Y << endl;
                    
                    g.addEdge(*v, *nextv, 1);
                addChildren(g, nextv);
                
            }
            
            
        }
        if (moves[i] == 'L' && v->getDirection() != 'R') {
            for (it = graphPos.begin(); it != graphPos.end(); it++) {
                if(it->X == NextPosition(v->getPosition(), 'L').X && it->Y == NextPosition(v->getPosition(), 'L').Y){
                    flag = 1;
;
                }
            }
            
            if(flag != 1){
            Vertex *nextv = g.addVertex(NextPosition(v->getPosition(), 'L'), 'L', v->getDepth());
            graphPos.push_back(NextPosition(v->getPosition(), 'L'));
            
            cout << "(L) X: "<< nextv->getPosition().X << " Y: " << nextv->getPosition().Y << endl;
            
            g.addEdge(*v, *nextv, 1);
                addChildren(g, nextv);
                
            }
        }
    }
}


Graph Create_Graph(){
    
    Graph *g = new Graph();
    
    Vertex *v = g->addVertex(StartingPoint, NULL, 0);
    
    
    vector<char> moves = AvailableMoves(StartingPoint.X, StartingPoint.Y);
    
    for (int i = 0; i < moves.size(); i++) {
        v->addDepth();
        if (moves[i] == 'U') {
            Vertex *nextv = g->addVertex(NextPosition(StartingPoint, 'U'), 'U', v->getDepth());
            graphPos.push_back(NextPosition(StartingPoint, 'U'));
            g->addEdge(*v, *nextv, 1);
            addChildren(*g, nextv);
        }
        else if (moves[i] == 'D') {
            Vertex *nextv = g->addVertex(NextPosition(StartingPoint, 'D'), 'D',  v->getDepth());
            graphPos.push_back(NextPosition(StartingPoint, 'D'));
            g->addEdge(*v, *nextv, 1);
            addChildren(*g, nextv);
        }
        else if (moves[i] == 'R') {
            Vertex *nextv = g->addVertex(NextPosition(StartingPoint, 'R'), 'R',  v->getDepth());
            graphPos.push_back(NextPosition(StartingPoint, 'R'));
            g->addEdge(*v, *nextv, 1);
            addChildren(*g, nextv);
        }
        else if (moves[i] == 'L') {
            Vertex *nextv = g->addVertex(NextPosition(StartingPoint, 'L'), 'L',  v->getDepth());
            graphPos.push_back(NextPosition(StartingPoint, 'L'));
            g->addEdge(*v, *nextv, 1);
            addChildren(*g, nextv);
        }
        
    }
    
    return *g;
}


void dfsVisit(Vertex *v, vector<Vertex *> & res) {
    v->visited = true;
    res.push_back(v);

    
    typename vector<Edge>::iterator it;
    for(it = v->adj.begin(); it != v->adj.end(); it++){
        if(!it->dest->visited){
            dfsVisit(it->dest, res);
        }
    }
}


vector<Vertex *> DFS(Graph g)
{
    
    vector<Vertex *> res;

    typename vector<Vertex *>::const_iterator it;
    
    for(it = g.vertexSet.begin(); it != g.vertexSet.end(); it++){
        (*it)->visited = false;
    }
    
    
    for(it  = g.vertexSet.begin(); it != g.vertexSet.end(); it++){
            if(!(*it)->visited){
                dfsVisit(*it, res);
            }
    }
    
    return res;
}

vector<Vertex *> BFS(Graph g, Vertex *v)
{
    queue<Vertex *> temp;
    vector<Vertex *> res;
    
    int flag = 0;

    typename vector<Vertex *>::const_iterator it;
    
    for(it = g.vertexSet.begin(); it != g.vertexSet.end(); it++){
        (*it)->visited = false;
    }
    
    temp.push(*g.vertexSet.begin()); //por na queue
    
    if(flag == 0){
    while (!temp.empty())
    {
        
        Vertex* vertex = temp.front();
    
        if (vertex->getPosition().X == EndingPoint.X ||vertex->getPosition().Y == EndingPoint.Y) {
            cout << "Found solution" << endl;
            flag = 1;
        }
        
        vertex->visited = true;
        temp.pop(); //tirar da queue
        res.push_back(vertex);
        typename vector<Edge>::iterator it;
        for (it = vertex->adj.begin(); it != vertex->adj.end(); it++){
            if(!it->dest->visited){
                temp.push(it->dest);
            }
        }
        
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

    }
    if (find(moves.begin(), moves.end(), 'D') != moves.end()) {
        cout << "[1] Down" << endl;

    }
    if (find(moves.begin(), moves.end(), 'L') != moves.end()) {
        cout << "[2] Left" << endl;

    }
    if (find(moves.begin(), moves.end(), 'R') != moves.end()) {
        cout << "[3] Right" << endl;

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
    vector<Vertex *> searchResult;
    Graph g = Create_Graph();

    
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
        cout << "[3] Iterative deepening search (not implemented)" << endl;
        cout << "[4] Uniform cost search (not implemented)" << endl;
        cout << "[5] Greedy search (not implemented)" << endl;
        cout << "[6] A* search (not implemented)" << endl;
        cin >> algorithm;
        
        /*for (int i = 0; i < g.getVertexSet().size(); i++) {
            cout << "X: "<< g.getVertexSet().at(i)->getPosition().X << " Y: " << g.getVertexSet().at(i)->getPosition().Y << endl;
        }*/
        switch (algorithm) {
            case 1:
                searchResult = DFS(g);
                break;
                
            case 2:
                searchResult = BFS(g, g.getVertexSet().front());
            default:
                break;
        }

        int s = searchResult.size();
        
        for(int i = 0; i < s ; i++){
          cout << "Coordinates: (" << searchResult.at(i)->getPosition().X << ", " << searchResult.at(i)->getPosition().Y << ")" << endl;
        }
        cout << "Coordinates on last vertex: (" << searchResult.at(s - 1)->getPosition().X << ", " << searchResult.at(s -1)->getPosition().Y << ")" << endl;
    }


    
    cout << "Congrats!" << endl;
    return 0;
}

