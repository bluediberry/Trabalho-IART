#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

const int MazeHeight = 18;
const int MazeWidth = 18;

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
			{ 1, 0, 0, 'A', 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1 },
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
const char Robot = 'A';

int main() {
    std::cout << "Hello, World!" << std::endl;
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