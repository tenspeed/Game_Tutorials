#ifndef ITEM_H
#define ITEM_H
#include <string>

using namespace std;


class Item
{
    public:
        Item(string name, int value);

        void addOne();
        void removeOne();

        // Getter functions
        string getName() { return _name;}
        int getValue()  { return _value;}
        int getCount() { return _count;}

        // Setter functions
        void setCount(int count)
        {
            _count = count;
        }

    private:

        string _name;
        int _value;
        int _count;

};

#endif // ITEM_H
