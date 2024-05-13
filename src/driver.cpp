#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>

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
    std::cout << "1. Cheeseburguer - $29.\n";
    std::cout << "2. Pizza - $20. \n";
    std::cout << "3. Burrito - $18.\n";
    std::cout << "4. Hamburguer - $18.\n";
}

void addItems() 
{


}

void finishOrder()
{

}


#endif