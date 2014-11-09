#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <string>

using namespace std;

class GameBoard
{
    public:
        GameBoard(void);
        void initBoard(void);
        void printBoard(void);
        bool setGamePiece(int x, int y, char symbol);
        bool win(char symbol, string name);

        char board[3][3];
        int count;

    private:

};

#endif // GAMEBOARD_H
