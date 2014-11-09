#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <vector>

using namespace std;

/*

int main()
{
    // vectors are like arrays without a fixed index size. the size
    // of a vector can be changed at any time while the program is
    // running, unlike an array. vectors are actually classes.
    // the "<string>" part is called a 'template'. classes which
    // use <> are called 'template classes' it's basically just
    // telling the compiler what kind of datatype this vector
    // will be dealing with.
    vector<string> itemNames;

    // every time you call push_back() on a vector, it pushes
    // the variable you give it, in this case a string, into the
    // vector and increments the vector's size automatically. this
    // is how you add items to your vector.
    itemNames.push_back("Gloves");
    itemNames.push_back("Hats");
    itemNames.push_back("Axes");
    itemNames.push_back("Rocks");

    for (int i = 0; i < itemNames.size(); i++)
    {
        cout << itemNames[i] << endl;
    }

    // to remove an item from a vector, use pop_back(). by default,
    // pop_back() removes the last item in the vector.
    itemNames.pop_back();

    // here is a trick to remove an item from the middle of a vector:
    // 1) overwrite the item in the middle of the vector with the last
    //    item in the vector
    // 2) delete the last item in the vector to remove the duplicate.

    // back() grabs the very last item at the back of the vector
    // this method works well for removing items at any arbitrary point
    // in the vecor, but it shuffles the order of the items in the
    // process. if you need the order to remain the same, then you
    // need to use a list (see exercise 18)
    itemNames[1] = itemNames.back();
    itemNames.pop_back();

    for (int i = 0; i < itemNames.size(); i++)
    {
        cout << itemNames[i] << endl;
    }

    // print out the size of the vector
    cout << itemNames.size() << endl;



    return 0;
}

*/

/*
Exercise 16
#include "Monster.h"

using namespace std;

int main()
{
    Monster monsters[100];

    Monster monster1("Fred");
    Monster monster2("George");

    monster1.printName();
    monster2.printName();

    monsters[0].printName();

    return 0;
}

*/

/*

Exercise 15

class CheckerBoard
{
    public:

        void initBoard()
        {
                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        if ((i % 2) != 0)
                        {
                            if ((j % 2) == 0)
                            {
                                board[i][j] = '.' ;
                            }
                            else
                            {
                                board[i][j] = '*';
                            }
                        }
                        else
                        {
                            if ((j % 2) != 0)
                            {
                                board[i][j] = '.';
                            }
                            else
                            {
                                board[i][j] = '*';
                            }
                        }

                    }
                }
        }

        void printBoard()
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    cout << board[i][j];
                }
                cout << endl;
            }
        }

    private:

        char board[8][8];
};

int main()
{
    CheckerBoard checkers;

    checkers.initBoard();
    checkers.printBoard();
}

*/

/*

Exercise 14

// by default, all functions, variables, etc in a Class are 'private'., meaning
// they can't be accessed outside of the class. this is to protect the data
// inside of the class or the object when it is instantiated. often times we
// want to be able to access data or use functions in the class/object so we
// need to make them 'public', but if say, you want to set the name of the
// monster at the start of the program and not allow it to be changed later,
// then you would leave the name as 'private'.
class Monster
{
    public:

         void growl()
        {
            cout << "Growl!!!\n" << endl;
        }

        // this is a setter function that sets a variable
        // _name is a private variable, but the monster
        // class can set it itself.

        void setName(string name)
        {
            _name = name;
        }

        // this is a getter function that gets a variable,
        // in this case, the protected variable, _name

        string getName(void)
        {
            return _name;
        }

    private:
        // putting _name under 'private' protects _name from being
        // changed willy-nilly, ie, using monster._name = 'blah'.
        // in order to change our monster's name, you have to call
        // the public setter function, setName.
        string _name;
};

int main()
{
    Monster monster1;

    monster1.growl();
    monster1.setName("George");

    cout << monster1.getName() << endl;

    return 0;
}

*/

/*

Exercises 12 - 13

// numItems must be declared as a "constant" variable in order to use it
// to define the size of the shopItemNames array.
// the size of an array must not change and must be known at the time
// the program is compiled, otherwise you will get errors.
// because we are defining these variables outside of int main(),
// these are "global" variables. normally it is not a good idea to create
// global variables, but if they are constant global variables then it is
// generally okay.
const int numItems = 7;
const string shopItemNames[numItems] = {"Boots", "Swords", "Helmets", "Kittens", "Poleaxes", "Leggings", "Daggers"};
void printInventory(const int playerInventory[numItems]);
void printShop(void);
bool buyItems(int playerInventory[numItems]);

int main()
{
    bool isDone = false;
    int playerInventory[numItems] = {0, 0, 0, 1, 0, 0, 0};

    cout << "*** Welcome to the item shop! ***\n" << endl;

    while(isDone == false)
    {
        printShop();

        printInventory(playerInventory);

        isDone = buyItems(playerInventory);

        cout << "\n\n\n" << endl;
    }


    return 0;
}

// arrays are passed by reference by default. you actually can't pass
// arrays by value like you can for variables. in this function,
// we're passing playerInventory as a constant. this means that printInventory()
// cannot modify the player inventory when it runs. this is important because
// we don't want print inventory to modify our player inventory; that's not
// it's purpose.
void printInventory(const int playerInventory[numItems])
{
    cout << "Your inventory is: \n" << endl;
    for (int i = 0; i < numItems; i++)
    {
        if (playerInventory[i] > 0)
        {
            cout << playerInventory[i] << " x " << shopItemNames[i] << "\n" << endl;
        }
    }
}

void printShop()
{
     for (int i = 0; i < numItems; i++)
    {
        cout << i + 1 << ". " << shopItemNames[i] << "\n" << endl;
    }

    cout << "*****************************\n" << endl;
}

bool buyItems(int playerInventory[numItems])
{
    int input;
    cout << "What would you like to buy? Enter -1 to quit. Enter (" << 1 << "-" << numItems << "):" << endl;
    cin >> input;

    if (input == -1)
    {
        return true;
    }
    if (input <= 0 || input > numItems)
    {
        cout << "That's not a valid item!\n" << endl;
        return false;
    }

    playerInventory[input - 1]++;
    return false;
}

*/

/* Exercises 1-11

int main()
{
    default_random_engine randomgenerator(time(0));
    uniform_real_distribution<float> attackRoll(0.0f, 1.0f);

    while (1)
    {
        float attack = attackRoll(randomgenerator);

        if (attack <= 0.3f)
        {
            cout << "I hit the snake! Yay!\n";
            return 0;
        }
        else
        {
            cout << "I missed the snake oohhh noooooooo\n";
        }
    }

    return 0;
}

int getNumHumans()
{
    int numHumans;
    //Get the number of humans
    cout << "Enter the number of humans:\n" << endl;
    cin >> numHumans;
    return numHumans;
}
*/
