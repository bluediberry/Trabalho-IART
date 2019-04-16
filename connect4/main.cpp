#include <iostream>
#include "nlinhas.hpp"
#include "utils.hpp"

using namespace std;

void play_manual(){
    playerInfo playerOne, playerTwo;
    char board[9][10];
    int dropChoice, win, full, again;
    
    cout << "Let's Play Connect 4" << endl << endl;
    cout << "Player One please enter your name: ";
    cin  >> playerOne.playerName;
    playerOne.playerID = 'X';
    cout << "Player Two please enter your name: ";
    cin  >> playerTwo.playerName;
    playerTwo.playerID = 'O';
    
    full = 0;
    win = 0;
    again = 2;
    DisplayBoard( board );
    
    
    do
    {
        dropChoice = PlayerDrop( board, playerOne );
        CheckBellow( board, playerOne, dropChoice );
        DisplayBoard( board );
        cout << playerOne.playerName << "'s finishing chances: " << nlinhas3(board, playerOne) << endl;
        cout << playerOne.playerName << "'s points: " << central(board, playerOne) << endl;

        win = nlinhas4( board, playerOne );
        if ( win == 1 )
        {
            PlayerWin(playerOne);
            again = restart(board);
            if (again == 0)
            {
                break;
            }
        }
        
        dropChoice = PlayerDrop( board, playerTwo );
        CheckBellow( board, playerTwo, dropChoice );
        DisplayBoard( board );
        cout << playerTwo.playerName << "'s finishing chances: " << nlinhas3(board, playerTwo) << endl;
        cout << playerTwo.playerName << "'s points: " << central(board, playerTwo) << endl;
        win = nlinhas4( board, playerTwo );
        if ( win == 1 )
        {
            PlayerWin(playerTwo);
            again = restart(board);
            if (again == 0)
            {
                break;
            }
        }
        full = FullBoard( board );
        if ( full == 7 )
        {
            cout << "The board is full, it is a draw!" << endl;
            again = restart(board);
        }
        
    }while ( again != 0);
    
}

void play_computer(){
    
}

int main()
{

    
    int choice;
    
    cout << "How do you want to play? " << endl;
    cout << "[0] Manual" << endl;
    cout << "[1] Computer" << endl;
    cin >> choice;
    
    if (choice  == 0) {
        play_manual();
    }
    else if(choice == 1){
        play_computer();
    }
    else return 1;
    
    return 0;
}
