#include "Player.h"

Player::Player()
{

}

void Player::init(string name, int money)
{
    _name = name;
    _money = money;
}

void Player::printInventory()
{

    cout << "*** " << _name << ";s inventory ***\n\n";
    list<Item>::iterator lit;
    int i = 0;
    for (lit = _items.begin(); lit != _items.end(); lit++)
    {
        cout << i << ". " << (*lit).getName() << " x " << (*lit).getCount() << endl;
        i++;
    }
}

bool Player::removeItem(string name, Item &newItem)
{
    list<Item>::iterator lit;
    for (lit = _items.begin(); lit != _items.end(); lit++)
    {
        if ((*lit).getName() == name)
        {
            newItem = (*lit);
            (*lit).removeOne();
            if ((*lit).getCount() == 0)
            {
                _items.erase(lit);
            }
            return true;
        }
    }
    return false;
}

void Player::addItem(Item newItem)
{
    list<Item>::iterator lit;
    for (lit = _items.begin(); lit != _items.end(); lit++)
    {
        if ((*lit).getName() == newItem.getName())
        {
            (*lit).addOne();
            return;
        }
    }

    _items.push_back(newItem);
}
