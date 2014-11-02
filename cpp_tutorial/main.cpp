#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

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
