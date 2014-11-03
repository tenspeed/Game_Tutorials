#ifndef PLAYER_H
#define PLAYER_H
#include <string>

using namespace std;

class Player
{
    public:
        Player();
        void initPlayer();
        char getSymbol();
        string getName();

    private:
        string _name;
        char _symbol;
};

#endif // PLAYER_H
