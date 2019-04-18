#ifndef minimax_hpp
#define minimax_hpp

#include <stdio.h>
#include "utils.hpp"
#include "nlinhas.hpp"

struct Move
{
    int row, col;
};


int minimax(char board[9][10], int depth, bool isMax, playerInfo player, int alpha, int beta, int tempdepth);
Move findBestMove(char board[][10],  playerInfo activePlayer, int depth);

#endif /* minimax_hpp */
