#include "minimax.hpp"

int minimax(char board[][10], int depth, bool isMax, playerInfo player, int alpha, int beta, int tempdepth)
{
    playerInfo playerOp;

    if(player.playerID == 'X'){
        playerOp.playerID = 'O';
    }
    if(player.playerID == 'O'){
        playerOp.playerID = 'X';
    }
    
    //int score = nlinhas4(board, player) - nlinhas4(board, playerOp);
    int fav1 = nlinhas4(board, player) - nlinhas4(board, playerOp);
    int fav2 = 100*fav1 + nlinhas3(board, player) - nlinhas3(board, playerOp);
    int fav3 = 100*fav1 + central(board, player) - central(board, playerOp);
    int score = 5*fav2 + fav3;
    //int score = nlinhas4(board, player);
    //int score = nlinhas3(board, player);
    
    
    if(depth == tempdepth){
        return score;
    }
    
    
    int full = FullBoard(board);
    if (full == 7)
        return 0;
    
    int dropChoice;
    
    // If this maximizer's move
    if (isMax)
    {
   
        for (int i = 1; i <= 8; i++){
            
            for (int j = 1; j <= 9; j++)
            {
                // Check if cell is empty
                if (board[i][j]=='*')
                {
                    dropChoice = j;
                    //CheckBellow(board, player, dropChoice);
                    board[i][dropChoice] = player.playerID;
                    
                    alpha = max( alpha, minimax(board, depth, !isMax, player, alpha, beta, tempdepth+1));
                    
                    // Undo the move
                    board[i][j] = '*';
                }
                
                if(alpha >= beta)
                    break;
            }

        }
        return alpha;
    }
    
    // If this minimizer's move
    else
    {
        for (int i = 1; i <= 8; i++){
            
            for (int j = 1; j <= 9; j++)
            {
                if (board[i][j]=='*')
                {
                    // Make the move
                    dropChoice = j;
                    board[i][dropChoice] = player.playerID;
                    
                    beta = min(beta, minimax(board, depth, !isMax, player, alpha, beta, tempdepth+1));
                    
                    board[i][j] = '*';
                }
                
            }

        }
        
        return beta;
    }
    
}

Move findBestMove(char board[][10],  playerInfo activePlayer, int depth)
{
    
    int bestVal = -1000;
    Move bestMove;
    bestMove.col = 4;
    int dropChoice;
    int length = 6;
    
    for (int i = 1; i <= 8; i++){
        
        for (int j = 1; j <= 9; j++)
        {
            // Check if cell is empty
            if (board[length][j]=='*')
            {
                // Make the move
                dropChoice = j;
                board[length][dropChoice] = activePlayer.playerID;
                
                
                int moveVal = minimax(board, depth, false,  activePlayer, -100000, 100000, 0);
                
                // Undo the move
                board[length][j] = '*';
                
                if (moveVal > bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
                
            }
        }
        
        length--;
        
    }
    
    return bestMove;
}
