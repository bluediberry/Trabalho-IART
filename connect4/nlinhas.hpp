#ifndef nlinhas_hpp
#define nlinhas_hpp

#include <stdio.h>

struct playerInfo
{
    char playerName[81];
    char playerID;
};

int nlinhas4 ( char board[][10], playerInfo activePlayer);
int nlinhas3 ( char board[][10], playerInfo activePlayer);
int central ( char board[][10], playerInfo activePlayer);



#endif /* nlinhas_hpp */
