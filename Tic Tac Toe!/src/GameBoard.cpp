#include "GameBoard.h"
#include <iostream>

GameBoard::GameBoard(void)
{
    //constructor
    char board[3][3];
}

void GameBoard::initBoard(void)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '_';
        }
    }

}

void GameBoard::printBoard(void)
{
    cout << "  1 2 3  " << endl;
    for(int i = 0; i < 3; i++)
    {
        cout << i + 1 << "|";

        for(int j = 0; j < 3; j++)
        {
            cout << board[i][j] << "|";
        }

        cout << "\n";
    }

}

bool GameBoard::setGamePiece(int x, int y, char symbol)
{
    if(board[x - 1][y - 1] != '_')
    {
        cout << "That space is already taken. Choose another." << endl;
        return false;
    }
    else
    {
        board[x - 1][y - 1] = symbol;
        return true;
    }
}

bool GameBoard::win(char symbol, string name)
{
    if((board[0][0] == symbol) && (board[0][1] == symbol) && (board[0][2] == symbol))
    {
        cout << name << " wins!" << endl;
        return true;
    }
    else if((board[1][0] == symbol) && (board[1][1] == symbol) && (board[1][2] == symbol))
    {
        cout << name << " wins!" << endl;
        return true;
    }
    else if((board[2][0] == symbol) && (board[2][1] == symbol) && (board[2][2] == symbol))
    {
        cout << name << " wins!" << endl;
        return true;
    }
    else if((board[0][0] == symbol) && (board[1][0] == symbol) && (board[2][0] = symbol))
    {
        cout << name << " wins!" << endl;
        return true;
    }
    else if((board[0][1] == symbol) && (board[1][1] == symbol) && (board[2][1] = symbol))
    {
        cout << name << " wins!" << endl;
        return true;
    }
    else if((board[0][2] == symbol) && (board[1][2] == symbol) && (board[2][2] = symbol))
    {
        cout << name << " wins!" << endl;
        return true;
    }
    else if((board[0][0] == symbol) && (board[1][1] == symbol) && (board[2][2] = symbol))
    {
        cout << name << " wins!" << endl;
        return true;
    }
    else if((board[0][2] == symbol) && (board[1][1] == symbol) && (board[2][0] = symbol))
    {
        cout << name << " wins!" << endl;
        return true;
    }

    return false;
}
