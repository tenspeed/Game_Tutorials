#ifndef MONSTER_H
#define MONSTER_H
#include <string>

using namespace std;

class Monster
{
    public:
        Monster(void);
        Monster(string name);
        void printName(void);


    private:
        string _name;
};

#endif // MONSTER_H
