#include <iostream>
#include <string>
#include "GameBoard.h"
#include "Player.h"

using namespace std;

int main()
{
    // declare variables
    bool isDone = false;
    bool turnDone = false;
    int x;
    int y;
    int turn = 1;

    // create a GameBoard object
    GameBoard tictactoe;

    // create a Player object for player 1
    Player player1;

    // create a Player object for player 2
    Player player2;

    // initialize the game board
    tictactoe.initBoard();

    cout << "*** Player 1 ***" << endl;

    // initialze player 1 to get their name and symbol
    player1.initPlayer();

    cout << "*** Player 2 ***" << endl;

    // initialize player 2 to get their name and symbol
    player2.initPlayer();

    // main game loop
    while(isDone != true)
    {
        // reset the turnDone flag
        turnDone = false;

        // player 1 turn
        if(turn == 1)
        {
            // keep going until player 1 has given valid input
            while(turnDone != true)
            {

                tictactoe.printBoard();
                cout << player1.getName() << endl;
                cout << "Enter a x-coordinate: ";
                cin >> x;
                cout << "Enter a y-coordinate: ";
                cin >> y;
                // update the game board with player 1's symbol
                // unless the spot is already taken
                turnDone = tictactoe.setGamePiece(x, y, player1.getSymbol());
                // check for a winning condition to end the game
                isDone = tictactoe.win(player1.getSymbol(), player1.getName());

            }
            // increment turn so next time it will be player 2's turn
            turn++;

        }

        // player 2 turn
        else
        {
            // keep going until player 2 has given valid input
            while(turnDone != true)
            {
                tictactoe.printBoard();
                cout << player2.getName() << endl;
                cout << "Enter a x-coordinate: ";
                cin >> x;
                cout << "Enter a y-coordinate: ";
                cin >> y;
                // update the game board with player 2's symbol
                // unless the spot is already taken
                turnDone = tictactoe.setGamePiece(x, y, player2.getSymbol());
                // check for a winning condition to end the game
                isDone = tictactoe.win(player2.getSymbol(), player2.getName());
            }

            // decrement turn so next time it will be player 1's turn
            turn--;
        }
    }
    cout << "\n";
    tictactoe.printBoard();
    return 0;
}
