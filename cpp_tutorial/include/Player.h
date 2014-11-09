#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <list>
#include <iostream>
#include "Item.h"

using namespace std;

class Player
{
    public:
        Player();

        void init(string name, int money);

        void printInventory();
        bool removeItem(string name, Item &newItem);
        void addItem(Item newItem);

        // Getter functions

        int getMoney() { return _money;}

        // Setter functions
        void subtractMoney (int amount) { _money -= amount; }

    private:
        string _name;
        list<Item> _items;
        int _money;

};

#endif // PLAYER_H
