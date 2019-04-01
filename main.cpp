#include <iostream>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <windows.h>
#include <ctime>
#include "Coord.h"


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
    if (Maze[x - 1][y] == Free)
        moves.push_back('L');
    if (Maze[x + 1][y] == Free)
        moves.push_back('R');
    if (Maze[x][y - 1] == Free)
        moves.push_back('U');
    if (Maze[x][y + 1] == Free)
        moves.push_back('D');
    return moves;
}

void Left() {
    Maze[StartingPoint.X][StartingPoint.Y] = Robot;
    while (Maze[StartingPoint.X][StartingPoint.Y - 1] == 0 || Maze[StartingPoint.X][StartingPoint.Y - 1] == 'T') {
        Maze[StartingPoint.X][StartingPoint.Y] = Free;
        Maze[StartingPoint.X][StartingPoint.Y - 1] = 'R';
        StartingPoint.Y--;
    }
    print_maze();
    Sleep(1);
}

void Right() {
    Maze[StartingPoint.X][StartingPoint.Y] = Robot;
    while (Maze[StartingPoint.X][StartingPoint.Y + 1] == 0|| Maze[StartingPoint.X][StartingPoint.Y + 1] == 'T') {
        Maze[StartingPoint.X][StartingPoint.Y] = Free;
        Maze[StartingPoint.X][StartingPoint.Y + 1] = 'R';
        StartingPoint.Y++;
    }
    print_maze();
    Sleep(1);
}

void Up() {
    Maze[StartingPoint.X][StartingPoint.Y] = Robot;
    while (Maze[StartingPoint.X - 1][StartingPoint.Y] == 0 || Maze[StartingPoint.X - 1][StartingPoint.Y] == 'T') {
        Maze[StartingPoint.X][StartingPoint.Y] = Free;
        Maze[StartingPoint.X - 1][StartingPoint.Y] = 'R';
        StartingPoint.X--;
    }
    print_maze();
    Sleep(1);
}

void Down() {
    Maze[StartingPoint.X][StartingPoint.Y] = Robot;
    while (Maze[StartingPoint.X + 1][StartingPoint.Y] == 0 || Maze[StartingPoint.X + 1][StartingPoint.Y] == 'T') {
        Maze[StartingPoint.X][StartingPoint.Y] = Free;
        Maze[StartingPoint.X + 1][StartingPoint.Y] = 'R';
        StartingPoint.X++;
    }
    print_maze();
    Sleep(1);
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

void Solve_manual()
{
    int n;
    
    cout << "What direction do you want to move in?" << endl;
    cout << "[0] Up" << endl;
    cout << "[1] Down" << endl;
    cout << "[2] Left" << endl;
    cout << "[3] Right" << endl;
    
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
            Solve();
        }
    }
    
    cout << "Congrats!" << endl;
    return 0;
}
