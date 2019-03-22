#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

const int MazeHeight = 18;
const int MazeWidth = 18;

#define LIGHTRED "\033[1;31m"
#define LIGHTBLUE "\033[1;34m"
#define WHITE "\033[1;30m"
#define BROWN "\033[1;37m"


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


class COORD{
public:
    int X;
    int Y;
    COORD(int x = 0, int y = 0){X = x, Y = y;};
    COORD(const COORD &coord) {X = coord.X, Y = coord.Y ;};
};

COORD StartingPoint(10,3);
COORD EndingPoint(3, 12);

//==========================================================================================
// Set text color & background
void setcolor(string color, const string background_color)
{
    cout << color << background_color;
}


void print_maze(){
    for(int i = 0; i < MazeHeight-1; i++){
        for(int j = 0; j < MazeWidth; j++){
            //cout << Maze[i][j];
            if(Maze[i][j] == Wall){
                setcolor(WHITE, BROWN);
                cout << " 1 ";
            }
            else if(Maze[i][j] == Free){
                setcolor(WHITE, WHITE);
                cout << " 0 ";
            }
            else if(Maze[i][j] == Target){
                setcolor(LIGHTRED, LIGHTRED);
                cout << " T ";
            }
            else if(Maze[i][j] == Robot){
                setcolor(LIGHTBLUE, LIGHTBLUE);
                cout << " R ";
            }
        }
        
        cout << endl;
    }
}

int main() {
    
    print_maze();
    return 0;
}

void Up(int posx, int posy) {
    while (Maze[posx][posy - 1] == 0 || Maze[posx][posy - 1] == 'T') {
        Maze[posx][posy - 1] = 0;
        Maze[posx][posy - 1] = 'A';
        posy = posy - 1;
    }
}

void Down(int posx, int posy) {
    while (Maze[posx][posy + 1] == 0 || Maze[posx][posy + 1] == 'T') {
        Maze[posx][posy + 1] = 0;
        Maze[posx][posy + 1] = 'A';
        posy = posy + 1;
    }
}

void Left(int posx, int posy) {
    while (Maze[posx - 1][posy] == 0 || Maze[posx - 1][posy] == 'T') {
        Maze[posx - 1][posy] = 0;
        Maze[posx - 1][posy] = 'A';
        posx = posx - 1;
    }
}

void Right(int posx, int posy) {
    while (Maze[posx + 1][posy] == 0 || Maze[posx + 1][posy] == 'T') {
        Maze[posx + 1][posy] = 0;
        Maze[posx + 1][posy] = 'A';
        posx = posx + 1;
    }
}
