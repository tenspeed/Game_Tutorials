#include "Shop.h"
#include <iostream>

Shop::Shop(string name, int money)
{
    _name = name;
    _money = money;
}

void Shop::printShop()
{
    cout << "*** Welcome to " << _name << " ***\n\n";
    list<Item>::iterator lit;
    int i = 0;
    for (lit = _items.begin(); lit != _items.end(); lit++)
    {
        cout << i << ". " << (*lit).getName() << " x " << (*lit).getCount() << endl;
        i++;
    }
}

bool Shop::purchaseItem(string name, Item &newItem)
{
    list<Item>::iterator lit;
    for (lit = _items.begin(); lit != _items.end(); lit++)
    {
        if ((*lit).getName() == name)
        {
            Item newItem = (*lit);
            newItem.setCount(1);
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

void Shop::addItem(Item newItem)
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
