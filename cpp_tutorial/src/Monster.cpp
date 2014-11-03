#include "Monster.h"
#include <iostream>

// this is the default constructor function for the Monster class
// it is the default because it doesn't take any parameters.
// every monster needs a name though for every monster who is created
// with the default constructor, it sets their name to the default "NONAME"
Monster::Monster(void)
{
    _name = "NONAME";
}

// this is a custom constructor function that takes a string and
// set's the monster's name equal to the string.
Monster::Monster(string name)
{
    _name = name;
}

// this is a function that prints out the monster's name
void Monster::printName(void)
{
    cout << "My name is " << _name << endl;
}
