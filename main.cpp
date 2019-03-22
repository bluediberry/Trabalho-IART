#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

const int MazeHeight = 18;
const int MazeWidth = 18;

#define LIGHTRED "\033[1;31m"
#define LIGHTBLUE "\033[1;34m"


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
                setcolor(LIGHTRED, LIGHTRED);
                cout << " 1 ";
            }
            else if(Maze[i][j] == Free){
                setcolor(LIGHTBLUE, LIGHTBLUE);
                cout << " 0 ";
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

int main() {

    print_maze();
    return 0;
}