#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

// numItems must be declared as a "constant" variable in order to use it
// to define the size of the shopItemNames array.
// the size of an array must not change and must be known at the time
// the program is compiled, otherwise you will get errors.
// because we are defining these variables outside of int main(),
// these are "global" variables. normally it is not a good idea to create
// global variables, but if they are constant global variables then it is
// generally okay.
const int numItems = 6;
const string shopItemNames[numItems] = {"Boots", "Sword", "Helmet", "Kitten", "Poleaxe", "Leggings"};
void printInventory(int playerInventory[numItems]);

int main()
{

    int playerInventory[numItems] = {0, 0, 0, 1, 0, 0};

    cout << "*** Welcome to the item shop! ***\n" << endl;

    int i;
    for (i = 0; i < numItems; i++)
    {
        cout << shopItemNames[i] << "\n" << endl;
    }

    cout << "*****************************\n" << endl;
    return 0;
}

void printInventory(int playerInventory[numItems])
{
    for (int i = 0; i < numItems; i++)
    {
        if (playerInventory[i] > 0)
        {
            cout << playerInventory[i] << " x " << shopItemNames[i] << endl;
        }
    }
}

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
