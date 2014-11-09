#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <vector>
#include <list>
#include <cstdlib>
#include <fstream>
//#include "Item.h"
//#include "Shop.h"
//#include "Player.h"

using namespace std;

/*
Exercise 19: File IO and Advanced Input!

int main()
{

    ofstream outputfile;
    ifstream inputfile;
    /*
    // open the file and default to write
    outputfile.open("myfile.txt");

    // check to make sure ofstream opened the file correctly
    if (outputfile.fail())
    {
        // "this file does not exist", or whatever
        perror("myfile.txt");
        return 1;
    }
    // write "Hello World" to the file
    outputfile << "Hello World\n";
    // close the file
    outputfile.close();

    */

    inputfile.open("myfile.txt");
    if (inputfile.fail())
    {
        perror("myfile.txt");
        return 1;
    }

    string input;
    while(getline(inputfile,input))
    {
        cout << input << endl;
    }

    cout << input;

    // how to prevent bad input from messing up your program:

    while(true)
    {
        int a;
        // cin is expecting 'a' to be an integer. if the user types in
        // a char or a string instead, this will really mess up your
        // program. to prevent this, we check first whether cin has
        // received an integer or not. cin >> a will actually return a
        // a boolean value (true or false) depending on the input it
        // receives. if 'a' is an integer, it will return true. if
        // 'a' is something else, it will return false. our if-statement
        // below checks to see if cin got an integer, and if not, prints
        // an error message instead of trying to print out 'a'.
        if (!(cin >> a))
        {
            cout << "THAT IS BAD";
            system("PAUSE");
            // cin.clear() : clear the input stream
            cin.clear();
            // cin.ignore (#of characters to ignore, ignore everything up to the newline);
            cin.ignore(9999, '\n');
        }
        else
        {
            cout << a;
        }
    }

    system("PAUSE");
    return 0;
}

*/
/*

Exercise 18.5: Item Shop Game (Doesn't quite work)

void initShops(list<Shop> &shops);
void initPlayer(Player &player);
void pickShop(list<Shop> &shops);
void enterShop(Player &player, Shop &shop);

int main()
{

    list<Shop> shops;
    list<Shop>::iterator lit;
    Player player;
    string shopName;

    // Initialization
    initPlayer(player);
    initShops(shops);

    // Tells us when the game is over
    bool isDone = false;

    cout << "*** Welcome to the item shop! ***\n";

    // Game loop
    while(isDone == false)
    {
        cout << "Shops\n";
        int i = 1;
        for (lit = shops.begin(); lit != shops.end(); lit++)
        {
            cout << i << ". " << (*lit).getName() << endl;
            i++;
        }
        cout << "What shop would you like to enter?";

        // getline(cin, shopName) is going to capture the entire string
        // of your user's input. if you just use cin, it will only grab
        // the first string and then stop when it encounters the blank
        // space character. for example, if you type "The Blacksmith"
        // cin will only grab "The". getline(cin, shopName) will grab
        // "The Blacksmith". In order for this to fully work though,
        // you will want to call cin.ignore(64, '\n') and cin.clear()
        // to make sure that any previous input does not get grabbed
        // by getline(). (cin does not get automatically cleared from
        // the last time you called it).

        getline(cin, shopName);

        cout << "You inputted: " << shopName << endl;

        bool validShop = false;

        for (lit = shops.begin(); lit != shops.end(); lit++)
        {
           if ((*lit).getName() == shopName)
           {
                enterShop(player, (*lit));
                validShop = true;
           }
        }

        if (validShop == false)
        {
            cout << "Invalid Shop!\n";
        }
    }
}

void initShops(list<Shop> &shops)
{
    shops.push_back(Shop("Bill's Leather Shop", 500));
    shops.back().addItem(Item("Leather Boots", 50));
    shops.back().addItem(Item("Leather Hat", 50));
    shops.back().addItem(Item("Leather Gloves", 50));
    shops.back().addItem(Item("Leather Gauntlets", 50));
    shops.back().addItem(Item("Leather Chestpiece", 100));

    shops.push_back(Shop("The Blacksmith", 1500));
    shops.back().addItem(Item("Iron Boots", 100));
    shops.back().addItem(Item("Iron Hat", 100));
    shops.back().addItem(Item("Iron Gloves", 100));
    shops.back().addItem(Item("Iron Gauntlets", 100));
    shops.back().addItem(Item("Iron Chestpiece", 200));
    shops.back().addItem(Item("Iron Sword", 150));
    shops.back().addItem(Item("Iron Shield", 150));


    shops.push_back(Shop("Beverly's Fruity Fruit Shop", 200));
    shops.back().addItem(Item("Grapes", 5));
    shops.back().addItem(Item("Apple", 5));
    shops.back().addItem(Item("Orange", 5));
    shops.back().addItem(Item("Watermellon", 10));
    shops.back().addItem(Item("Tomato", 3));
}

void initPlayer(Player &player)
{
    cout << "Enter thy name sir knight: ";
    string name;
    getline(cin, name);
    player.init(name, 100);
    player.addItem(Item("Bronze Sword", 5));
}

void enterShop(Player &player, Shop &shop)
{
    bool isDone = false;
    char input;
    string itemName;
    Item newItem("NOITEM", 0);

    while (isDone == false)
    {
        shop.printShop();
        player.printInventory();

        cout << "Would you like to buy or sell? Q to quit. (B/S): ";
        cin >> input;
        cin.ignore(64, '\n');
        cin.clear();

        if (input == 'Q' || input == 'q')
        {
            return;
        }

        if (input == 'B' || input == 'b')
        {
            // buy
            cout << "Enter the item you wish to buy: ";
            getline(cin, itemName);

            if (shop.purchaseItem(itemName, newItem))
            {
                player.addItem(newItem);
            }
            else
            {
                cout << "That is an invalid item\n";
            }
        }
        else
        {
            // sell
            cout << "Enter the item you wish to sell: ";
            getline(cin, itemName);

            if (player.removeItem(itemName, newItem) == true)
            {
                shop.addItem(newItem);
            }
            else
            {
                cout << "That is an invalid item\n";
            }
        }
    }
}

*/
/*

// Exercise 18: Lists!

// In this exercise we learn about lists. Lists are similar to vectors and
// arrays in that they store collections of data. the benefit of using a list
// is that you can add or remove items from the list without having to care
// about where the items are located in the list. this is more difficult to
// accomplish with an array or a vector. The downside of using a list is that
// in order to remove specific items, you will have to loop through all or
// a portion of the list which can be very slow/inefficient, especially if
// it's a big list. It is much much MUCH faster to use a vector or an array
// to store data in memory. It's up to you to decide which one you need to use.

int main()
{
    // lists are a 'template class' just like vectors. they are
    // declared the same way as you can see.
    list<string> shopItemNames;

    // lists have a push_back() method just like vectors do and they
    // also have a push_front() method that pushes things to the front
    // of the list.
    shopItemNames.push_back("Gloves");
    shopItemNames.push_front("Axes");
    shopItemNames.push_back("Kittens");
    shopItemNames.push_back("Swords");
    shopItemNames.push_back("Cars");
    shopItemNames.push_back("Kittens");

    // you cannot loop through a list with an integer, i, like you
    // can with an array or vector, ie: for (int i = 0; i < vector.size(); i++)
    // you have to create a new thing called an "iterator"
    list<string>::iterator it;

    for (it = shopItemNames.begin(); it != shopItemNames.end(); it++)
    {
        // print out whatever it is pointing at (hint: it is a pointer
        // to the values in the list shopItemNames).
        cout << *it << endl;
    }

    // remove() will remove ALL instances of the parameter you give it
    // ie: this will remove all Kittens from the list if there are
    // multiple Kittens.
   // shopItemNames.remove("Kittens");

   // if you only want to remove one Kitten, this for loop will do the trick.
   // erase() only erases the current item it is pointing at. once you call
   // erase() on the first Kitten you encounter, you can use break; to leave
   // the for loop
   for (it = shopItemNames.begin(); it != shopItemNames.end(); it++)
   {
        if(*it == "Kittens")
        {
            it = shopItemNames.erase(it);
            break;
        }
   }

    cout << "\n";

    for (it = shopItemNames.begin(); it != shopItemNames.end(); it++)
    {
        // print out whatever it is pointing at (hint: it is a pointer
        // to the values in the list shopItemNames).
        cout << *it << endl;
    }

    return 0;
}

*/
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
