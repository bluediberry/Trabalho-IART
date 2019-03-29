#include <iostream>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <unistd.h>

using namespace std;

const int MazeHeight = 18;
const int MazeWidth = 18;

void Up(int x, int y);
void Down(int x, int y);
void Left(int x, int y);
void Right(int x, int y);


char Maze[MazeHeight][MazeWidth] =
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


class COORD
{
public:
    int X;
    int Y;
    COORD(int x = 0, int y = 0) { X = x; Y = y; }
    COORD(const COORD &coord) { X = coord.X; Y = coord.Y; }
};

COORD StartingPoint(3,10);
COORD RobotPosition(StartingPoint);
COORD EndingPoint(12, 3);


void print_maze(){
    for(int i = 0; i < MazeHeight-1; i++){
        for(int j = 0; j < MazeWidth; j++){
            //cout << Maze[i][j];
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


bool isNextToWall(int X, int Y){
    return (Maze[Y - 1][X] == Wall || Maze[Y + 1][X] == Wall || Maze[Y][X - 1] == Wall || Maze[Y][X - 1] == Wall);
}


bool Solve(int X, int Y)
{
    // Make the move (if it's wrong, we will backtrack later.
    Maze[Y][X] = Robot;
    
    // If you want progressive update, uncomment these lines...
    if(isNextToWall(X, Y)){
        print_maze();
        sleep(1);}
    
    // Check if we have reached our goal.
    if (X == EndingPoint.X && Y == EndingPoint.Y)
    {
        exit(0);
    }
    
    // Recursively search for our goal.
    if (Y > 0 && (Maze[Y - 1][X] == Free || Maze[Y - 1][X] == Target) && Solve(X, Y - 1))
    {
        return true;
    }
    if (Y < MazeHeight && (Maze[Y + 1][X] == Free || Maze[Y + 1][X] == Target) && Solve(X, Y + 1))
    {
        return true;
    }
    if (X > 0 && (Maze[Y][X - 1] == Free || Maze[Y][X - 1] == Target) && Solve(X - 1, Y))
    {
        return true;
    }
    if (X < MazeWidth && (Maze[Y][X + 1] == Free || Maze[Y][X + 1] == Target) && Solve(X + 1, Y))
    {
        return true;
    }
    
    // Otherwise we need to backtrack and find another solution.
    Maze[Y][X] = Free;
    
    print_maze();
    sleep(1);
    return false;
}

int main() {
    
    print_maze();
    
    if (Solve(StartingPoint.X, StartingPoint.Y))
    {
        print_maze();
    }
    else
    {
        printf("Damn\n");
    }
    
    
    return 0;
}

void Up(int posx, int posy) {
    while (Maze[posx][posy - 1] == Free || Maze[posx][posy - 1] == 'T') {
        Maze[posx][posy - 1] = Free;
        Maze[posx][posy - 1] = 'R';
        posy = posy - 1;
    }
}

void Down(int posx, int posy) {
    while (Maze[posx][posy + 1] == Free || Maze[posx][posy + 1] == 'T') {
        Maze[posx][posy + 1] = Free;
        Maze[posx][posy + 1] = 'R';
        posy = posy + 1;
    }
}

void Left(int posx, int posy) {
    while (Maze[posx - 1][posy] == Free || Maze[posx - 1][posy] == 'T') {
        Maze[posx - 1][posy] = Free;
        Maze[posx - 1][posy] = 'R';
        posx = posx - 1;
    }
}

void Right(int posx, int posy) {
    while (Maze[posx + 1][posy] == Free || Maze[posx + 1][posy] == 'T') {
        Maze[posx + 1][posy] = Free;
        Maze[posx + 1][posy] = 'R';
        posx = posx + 1;
    }
}


