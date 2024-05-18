#include <iostream>
#include "InputHandler.h"

//this driver program instead of pos class?

void displayMenu()
{
    std::cout << "Welcome, what can we get you today? (Enter Choice) \n";
    std::cout << "1. View Item Menu.\n";
    std::cout << "2. Add Item to order.\n";
    std::cout << "3. Finish Order. \n";   //calls print function
    std::cout << "4. Quit(q).\n";
}

void viewMenuItems()
{
    std::cout << "      Menu      \n";
    std::cout << "1. Cheeseburger w/ Caviar- $29.\n";
    std::cout << "2. Pizza w/ Gold Dust (Slice) - $20. \n";
    std::cout << "3. Burrito w/ Rare Mushrooms- $18.\n";
    std::cout << "4. Hamburguer w/ - $18.\n";
}

void addItems() 
{

    // call from order class
}

void finishOrder()
{

}
