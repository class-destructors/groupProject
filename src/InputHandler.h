#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <iostream>
#include <fstream>
#include "Order.h"

void displayMenu();
void viewMenuItems(order& currentOrder);
void finishOrder(order& currentOrder);
void printOrder(order& currentOrder);

void displayMenu()
{
    order currentOrder;
    char answer;
    while(toupper(answer) != 'Y')
    {
        std::cout << "Hello! Are you ready to order?\n";
        std::cout << "Press Y to continue\n";
        std::cout << "Press N to quit\n";
        std::cin >> answer;
        std::cout << std::endl;
        if(toupper(answer) == 'Y')
        {
            viewMenuItems(currentOrder);
        }
        else if (toupper(answer) == 'N')
        {
            exit(1);
        }
        else
        {
            std::cout << "Error - please enter a valid choice from the menu screen.\n";
        }
    }
}

void viewMenuItems(order& currentOrder)
{
    int itemChoice;
    char orderMore;

    do
    {
        std::cout << "Menu      \n";
        std::cout << "1. Cheeseburger w/ Caviar- $29.\n";
        std::cout << "2. Pizza w/ Gold Dust (Slice) - $20. \n";
        std::cout << "3. Burrito w/ Rare Mushrooms- $18.\n";
        std::cout << "4. Hamburguer w/ Mystery Sauce- $18.\n\n";
        std::cout << "Press 5 to return to main menu.\n\n";
        std::cout << "Enter your choice:";
        std::cin >> itemChoice;
        std::cout << std::endl;
        switch(itemChoice)
        {
        case 1:
            currentOrder.addItem("Cheeseburger", 29);
            std::cout << "Your current order:\n";
            currentOrder.listItems();
            std::cout << std::endl << "Total: $"<< currentOrder.getTotalPrice() << std::endl;
            std::cout << "Would you like to add another item? Y or N?";
            std::cin >> orderMore;
            break;
        case 2:
            currentOrder.addItem("Pizza", 20); 
            std::cout << "Your current order:\n";
            currentOrder.listItems();
            std::cout << std::endl << "Total: $"<< currentOrder.getTotalPrice() << std::endl;
            std::cout << "Would you like to add another item? Y or N?";
            std::cin >> orderMore;             
            break;
        case 3:
            currentOrder.addItem("Burrito", 18);
            std::cout << "Your current order:\n";
            currentOrder.listItems();
            std::cout << std::endl << "Total: $"<< currentOrder.getTotalPrice() << std::endl;
            std::cout << "Would you like to add another item? Y or N?";
            std::cin >> orderMore;
            break;
        case 4:
            currentOrder.addItem("Hamburger", 18);
            std::cout << "Your current order:\n";
            currentOrder.listItems();
            std::cout << std::endl << "Total: $"<< currentOrder.getTotalPrice() << std::endl;
            std::cout << "Would you like to add another item? Y or N?";
            std::cin >> orderMore;
        case 5:
            displayMenu();
            break;
        default:
            std::cout << "Error - please enter a valid choice from the menu screen.\n";
        }
    
    }
    while (toupper(orderMore) == 'Y');
    finishOrder(currentOrder);
}

void finishOrder(order& currentOrder)
{
    std::cout << "Your receipt:\n";
    currentOrder.listItems();
    std::cout << std::endl << "Total: $"<< currentOrder.getTotalPrice() << std::endl;
    std::cout << std::endl << "Your order will be right out!";      // wait time?
    printOrder(currentOrder);
}

void printOrder(order& currentOrder)
{
    std::ofstream outFile;
    outFile.open("Printer.txt");
    outFile << currentOrder;
    outFile.close();
}

#endif