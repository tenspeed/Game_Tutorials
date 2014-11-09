#include <iostream>
#include <string>
#include "GameBoard.h"
#include "Player.h"

using namespace std;

int main()
{
    // declare variables
    bool gameDone = false;
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
    while(gameDone != true)
    {
        while(turnDone != true)
        {
            tictactoe.printBoard();
            if (turn % 2 != 0)
            {
                cout << "\n" << player1.getName() << endl;
                cout << "Enter a x-coordinate: ";
                cin >> x;
                cout << "Enter a y-coordinate: ";
                cin >> y;
                // update the game board with player 1's symbol
                // unless the spot is already taken
                turnDone = tictactoe.setGamePiece(x, y, player1.getSymbol());
                // check for a winning condition to end the game
                gameDone = tictactoe.win(player1.getSymbol(), player1.getName());
                turn++;
            }
            else
            {
                cout << "\n" << player2.getName() << endl;
                cout << "Enter a x-coordinate: ";
                cin >> x;
                cout << "Enter a y-coordinate: ";
                cin >> y;

                turnDone = tictactoe.setGamePiece(x, y, player2.getSymbol());

                gameDone = tictactoe.win(player2.getSymbol(), player2.getName());
                turn++;
            }

        }

            turnDone = false;

    }


    cout << "\n";
    tictactoe.printBoard();
    return 0;
}
