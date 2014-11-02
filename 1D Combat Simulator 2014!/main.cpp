#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

// this is a forward declaration. these functions are written
// below int main(). we use a forward declaration to let
// int main() know that these functions exist somewhere else
// in our code. otherwise, your program won't know they exist.
int getNumHumans(void);
int getNumSkeletons(void);
void simulateBattle(int &humans, int &skeletons);
void printResults(int humans, int skeletons);


int main()
{
    int humans;
    int skeletons;

    humans = getNumHumans();

    skeletons = getNumSkeletons();

    simulateBattle(humans, skeletons);

    printResults(humans, skeletons);
    return 0;
}

int getNumHumans(void)
{
    int numHumans;
    //Get the number of humans
    cout << "Enter the number of humans:\n" << endl;
    cin >> numHumans;
    return numHumans;
}

int getNumSkeletons(void)
{
    int numSkeletons;
    //Get the number of humans
    cout << "Enter the number of Skeletons:\n" << endl;
    cin >> numSkeletons;
    return numSkeletons;
}

void printResults(int humans, int skeletons)
{
    if (skeletons <= 0)
    {
        cout << "The Humans are victorious!!!\n" << endl;
    }
    else if (humans <= 0)
    {
        cout << "The Undead reign forever!!!\n" << endl;
    }
    else
    {
        cout << "Something went wrong. Reality as you know it has unraveled\n" << endl;
    }
}

// The '&' before humans and skeletons means we are passing
// these variables in by reference. This means that when we
// make changes to humans and skeletons from within
// simulateBattle(), the changes will stick in the variables
// declared in int main().
void simulateBattle(int &humans, int &skeletons)
{
    // static variables are only initialized the first time
    // the function is called. when the function ends, the
    // static variable remains inside the program memory.
    // if you call the function a second time, it will not
    // re-initialize the variable because it has already
    // been initialized and it still exists in program
    // memory for use.
    static default_random_engine randomgenerator(time(0));
    uniform_real_distribution<float> attackRoll(0.0f, 1.0f);
    bool turn;
    float attack;
    attack = attackRoll(randomgenerator);

    //determine if humans or skeletons attack first
    if (attack < 0.5f)
    {
        turn = 1;
    }
    else
    {
        turn = 0;
    }

    while (humans > 0 && skeletons > 0)
    {
        attack = attackRoll(randomgenerator);

        if (turn == 1)
        {
            skeletons = skeletons - (int)(10*attack);
            cout << "The humans killed " << (int)(10*attack) << " skeletons\n" << endl;
            cout << "Skeleton Army: " << skeletons << "\n" << endl;
            turn = 0;
        }
        else
        {
            humans = humans - (int)(10*attack);
            cout << "The skeletons killed " << (int)(10*attack) << " humans\n" << endl;
            cout << "Human Army: " << humans << "\n" << endl;
            turn = 1;
        }
    }
}
