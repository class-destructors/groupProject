#include <iostream>

#include "order.h"
#include "menuItem.h"
#include "driver.cpp"

int main()
{
    char choice = 'Y';

    displayMenu();
    
    while (choice == 'Y')
    {
        std::cout << "hi\n";
    } 

    std::cin >> choice;

    return;
}