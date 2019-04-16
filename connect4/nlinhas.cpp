#include "nlinhas.hpp"

int nlinhas4 ( char board[][10], playerInfo activePlayer )
{
    char XO;
    int win;
    
    XO = activePlayer.playerID;
    win = 0;
    
    for( int i = 8; i >= 1; --i )
    {
        
        for( int ix = 9; ix >= 1; --ix )
        {
            
            if( board[i][ix] == XO     &&
               board[i-1][ix-1] == XO &&
               board[i-2][ix-2] == XO &&
               board[i-3][ix-3] == XO )
            {
                win = 1;
            }
            
            
            if( board[i][ix] == XO   &&
               board[i][ix-1] == XO &&
               board[i][ix-2] == XO &&
               board[i][ix-3] == XO )
            {
                win = 1;
            }
            
            if( board[i][ix] == XO   &&
               board[i-1][ix] == XO &&
               board[i-2][ix] == XO &&
               board[i-3][ix] == XO )
            {
                win = 1;
            }
            
            if( board[i][ix] == XO     &&
               board[i-1][ix+1] == XO &&
               board[i-2][ix+2] == XO &&
               board[i-3][ix+3] == XO )
            {
                win = 1;
            }
            
            if ( board[i][ix] == XO   &&
                board[i][ix+1] == XO &&
                board[i][ix+2] == XO &&
                board[i][ix+3] == XO )
            {
                win = 1;
            }
        }
        
    }
    
    return win;
}


int nlinhas3 ( char board[][10], playerInfo activePlayer )
{
    char XO;
    char free = '*';
    int nlinhas3 = 0;
    int counter = 0;
    
    XO = activePlayer.playerID;
    
    for( int i = 8; i >= 1; --i )
    {
        
        for( int ix = 9; ix >= 1; --ix )
        {
            
            if( board[i][ix] == XO     &&
               board[i-1][ix-1] == XO &&
               board[i-2][ix-2] == XO &&
               board[i-3][ix-3] == free )
            {
                nlinhas3++;
            }

            
            if( board[i][ix] == XO   &&
               board[i][ix-1] == XO &&
               board[i][ix-2] == XO &&
               board[i][ix-3] == free )
            {
                nlinhas3++;
            }
            
            //------------------------------
            
            if( board[i][ix] == XO   &&
               board[i-1][ix] == XO &&
               board[i-2][ix] == XO &&
               board[i-3][ix] == free )
            {
                nlinhas3++;
            }
            
            
            if( board[i][ix] == XO     &&
               board[i-1][ix+1] == XO &&
               board[i-2][ix+2] == XO &&
               board[i-3][ix+3] == free )
            {
                nlinhas3++;
            }

            
            if ( board[i][ix] == XO   &&
                board[i][ix+1] == XO &&
                board[i][ix+2] == XO &&
                board[i][ix+3] == free )
            {
                nlinhas3++;
            }
            
        }
        
    }
    
    return nlinhas3;
}


int central( char board[][10], playerInfo activePlayer ){
    int points = 0;
    char XO;
    
    XO = activePlayer.playerID;
    
    for( int i = 8; i >= 1; --i )
    {
        if( board[i][4] == XO){
            points += 2;
        }
        if( board[i][3] == XO || board[i][5] == XO){
            points++;
        }
        
    }
    
    return points;
}
