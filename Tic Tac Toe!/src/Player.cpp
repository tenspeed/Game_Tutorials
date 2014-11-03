#include "Player.h"
#include <iostream>

Player::Player()
{
    string _name;
    char _symbol;
}

void Player::initPlayer()
{
    cout << "Enter your name: ";
    cin >> _name;
    cout << "Enter a symbol to use :";
    cin >> _symbol;
}

char Player::getSymbol()
{
    return _symbol;
}

string Player::getName()
{
    return _name;
}
