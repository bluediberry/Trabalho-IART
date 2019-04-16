#ifndef utils_hpp
#define utils_hpp

#include <stdio.h>
#include <iostream>
#include "nlinhas.hpp"
using namespace std;

int PlayerDrop( char board[][10], playerInfo activePlayer );
void CheckBellow ( char board[][10], playerInfo activePlayer, int dropChoice );
void DisplayBoard ( char board[][10] );
int FullBoard(char board[][10]);
void PlayerWin ( playerInfo activePlayer );
int restart ( char board[][10] );

#endif /* utils_hpp */
