#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Order.h"
#include "Kitchen.h"
#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"
#define ITALIC "\033[3m"
#define CLOSEITALIC "\033[0m"

void displayMenu();
void placeOrder(order& currentOrder);
void finishOrder(order& currentOrder);
void printOrder(order& currentOrder);
void showCurrentOrder(order& currentOrder);

void displayMenu()
{
    order currentOrder;
    char answer;

    // loop allows customer to have multiple tries if input is incorrect:
    while(toupper(answer) != 'Y')
    {
        // menu display:
        std::cout << "Greetings Valued Customer!\n";
        std::cout << "Press Y to continue to ordering page.\n";
        std::cout << "Press N to quit.\n";
        std::cin >> answer;
        std::cout << std::endl;
        if(toupper(answer) == 'Y')
        {
            // customer will be taken to placeOrder:
            system("clear");
            placeOrder(currentOrder);
        }
        else if (toupper(answer) == 'N')
        {
            // customer will exit program:
            std::cout << "Come back soon!";
            exit(1);
        }
        else
        {
            // error handling message:
            std::cout << "Error - please enter a valid choice from the menu screen.\n";
        }
    }
}

void placeOrder(order& currentOrder)
{
    int itemChoice;
    char orderMore;

    do
    {
        // food menu display:
        std::cout << UNDERLINE << "FOOD MENU" << CLOSEUNDERLINE << std::endl;
        std::cout << "#1 Cheezebürger" << std::setw(40-14) << " " << std::setw(6) << std::right << " $54.99\n";
        std::cout << ITALIC << "\t Unicorn Meat, American Cheese, Caviar\n\n" << CLOSEITALIC;
        std::cout << "#2 World Class Pizza (Slice)" << std::setw(40-27) << " " << std::setw(6) << std::right << " $27.99. \n";
        std::cout << ITALIC << "\t 127-Grain Crust, Fresh Cheese Medley, Rare Mushrooms \n\n" << CLOSEITALIC;
        std::cout << "#3 Burr ala Rito"<< std::setw(40-15) << " " << std::setw(6) << std::right << " $78.99.\n";
        std::cout << ITALIC << "\t Housemade Saffron Tortilla, Beans, Mystery Sauce\n\n" << CLOSEITALIC;
        std::cout << "#4 Hambürger" << std::setw(40-11) << " " << std::setw(6) << std::right << " $50.99.\n";
        std::cout << ITALIC << "\t Unicorn Meat, Gold Dust, Caviar\n\n\n" << CLOSEITALIC;
        std::cout << "To return to main menu - press 5. Order will be reset.\n\n";
        std::cout << "Enter the item (#1-4) to add it to your order:";
        std::cin >> itemChoice;
        std::cout << std::endl;

        // switch/case corresponds directly to menu items:
        switch(itemChoice)
        {
        case 1:
            // item chosen by customer is added to order:
            currentOrder.addItem("Cheezebürger", 54.99, 1);
            // customer's current order is displayed:
            showCurrentOrder(currentOrder);
            // loop showcases an additional menu screen, where customer can add/remove items or finish their order:
            do
                {   
                    // menu display:
                    std::cout << "Press Y to add another item.\nPress R to remove an item.\nPress F to finish your order." << std::endl; // error handling
                    std::cin >> orderMore;

                    //conditional if customer chooses to remove item:
                    if (toupper(orderMore) == 'R')
                    {
                        int removeIndex;
                        std::cout << "Which item would you like to remove?";
                        std::cin >> removeIndex;
                        // item chosen corresponds to the index on the entire order, removeItem() is called:
                        currentOrder.removeItem(removeIndex);
                        // updated order is shown to user after item removal:
                        showCurrentOrder(currentOrder);
                    }
                    // error handling message:
                    else if(toupper(orderMore) != 'Y' && toupper(orderMore) != 'R' && toupper(orderMore) != 'F')
                    {
                        std::cout << "Invalid Entry. Please Try Again.\n\n";
                    }
                } 
                // allows for user to re-try if input does not correspond to menu:
                while (toupper(orderMore) != 'Y' && toupper(orderMore) != 'R' && toupper(orderMore) != 'F');
            std::cout << std::endl;
            break;
        
        case 2:
            // item chosen by customer is added to order:
            currentOrder.addItem("Pizza Slice", 27.99, 1);
            // customer's current order is displayed:
            showCurrentOrder(currentOrder);
            // loop showcases an additional menu screen, where customer can add/remove items or finish their order:
            do
                {   // menu display:
                    std::cout << "Press Y to add another item.\nPress R to remove an item.\nPress F to finish your order." << std::endl;
                    std::cin >> orderMore;

                    // conditional if customer chooses to remove item:
                    if (toupper(orderMore) == 'R')
                    {
                        int removeIndex;
                        std::cout << "Which item would you like to remove?";
                        std::cin >> removeIndex;
                        // item chosen corresponds to the index on the entire order, removeItem() is called:
                        currentOrder.removeItem(removeIndex);
                        // updated order is shown to user after item removal:
                        showCurrentOrder(currentOrder);
                    }
                    // error handling message:
                    else if(toupper(orderMore) != 'Y' && toupper(orderMore) != 'R' && toupper(orderMore) != 'F')
                    {
                        std::cout << "Invalid Entry. Please Try Again.\n\n";
                    }
                } 
                // allows for user to re-try if input does not correspond to menu:
                while (toupper(orderMore) != 'Y' && toupper(orderMore) != 'R' && toupper(orderMore) != 'F');
            std::cout << std::endl;             
            break;
        
        case 3:
            // item chosen by customer is added to order:
            currentOrder.addItem("Burrito", 78.99,1);
            // customer's current order is displayed:
            showCurrentOrder(currentOrder);
            // loop showcases an additional menu screen, where customer can add/remove items or finish their order:
            do
                {   // menu display:
                    std::cout << "Press Y to add another item.\nPress R to remove an item.\nPress F to finish your order." << std::endl;
                    std::cin >> orderMore;

                    // conditional if customer chooses to remove item:
                    if (toupper(orderMore) == 'R')
                    {
                        int removeIndex;
                        std::cout << "Which item would you like to remove?";
                        std::cin >> removeIndex;
                        // item chosen corresponds to the index on the entire order, removeItem() is called:
                        currentOrder.removeItem(removeIndex);
                        // updated order is shown to user after item removal:
                        showCurrentOrder(currentOrder);
                    }
                    // error handling message:
                    else if(toupper(orderMore) != 'Y' && toupper(orderMore) != 'R' && toupper(orderMore) != 'F')
                    {
                        std::cout << "Invalid Entry. Please Try Again.\n\n";
                    }
                } 
                // allows for user to re-try if input does not correspond to menu:
                while (toupper(orderMore) != 'Y' && toupper(orderMore) != 'R' && toupper(orderMore) != 'F');
            std::cout << std::endl;             
            break;
        
        case 4:
            // item chosen by customer is added to order:
            currentOrder.addItem("Hambürger ", 50.99,1);
            // customer's current order is displayed:
            showCurrentOrder(currentOrder);
            // loop showcases an additional menu screen, where customer can add/remove items or finish their order:
            do
                {   // menu display:
                    std::cout << "Press Y to add another item.\nPress R to remove an item.\nPress F to finish your order." << std::endl;
                    std::cin >> orderMore;

                    // conditional if customer chooses to remove item:
                    if (toupper(orderMore) == 'R')
                    {
                        int removeIndex;
                        std::cout << "Which item would you like to remove?";
                        std::cin >> removeIndex;
                        // item chosen corresponds to the index on the entire order, removeItem() is called:
                        currentOrder.removeItem(removeIndex);
                        // updated order is shown to user after item removal:
                        showCurrentOrder(currentOrder);
                    }
                    // error handling message:
                    else if(toupper(orderMore) != 'Y' && toupper(orderMore) != 'R' && toupper(orderMore) != 'F')
                    {
                        std::cout << "Invalid Entry. Please Try Again.\n\n";
                    }
                } 
                // allows for user to re-try if input does not correspond to menu:
                while (toupper(orderMore) != 'Y' && toupper(orderMore) != 'R' && toupper(orderMore) != 'F');
            std::cout << std::endl;             
            break;
        
        case 5:
            // reverts back to main menu:
            displayMenu();
            break;
        
        default:
            // error handling message:
            std::cout << "Error - please enter a valid choice from the menu screen.\n";
        }
    
    }
    // encapsulating loop condition, will exit if customer chooses to finish order:
    while (toupper(orderMore) != 'F');
    finishOrder(currentOrder);
}

void showCurrentOrder(order& currentOrder)
{
    // lists order items and total price:
    std::cout << UNDERLINE << "Your current order:" CLOSEUNDERLINE << std::endl;
    currentOrder.listItems();
    std::cout << std::endl << "Total: $"<< currentOrder.getTotalPrice() << std::endl << std::endl;
}

void finishOrder(order& currentOrder)
{
    // lists order items and total price as final reference for user:
    
    int tipChoice;
    float tenPercent;
    tenPercent = (currentOrder.getTotalPrice() * .10); 
    float fifteenPercent;
    fifteenPercent = (currentOrder.getTotalPrice() * .15);
    float twentyPercent;
    twentyPercent = (currentOrder.getTotalPrice() * .20);
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Add a tip?\n";
    std::cout << "(0) - No Tip" << "\t\t(1) 10% - $" << tenPercent << "\t\t(2) 15% - $" << fifteenPercent << "\t\t(3) 20% - $" << twentyPercent << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> tipChoice;
    // switch(tipChoice)
    // {
    // case 1:
        
    // case 2:

    // case 3:

    // case 4:

    // }

    std::cout << UNDERLINE << "Your receipt:" << CLOSEUNDERLINE << std::endl;
    currentOrder.listItems();
    std::cout << std::endl << "Total: $"<< currentOrder.getTotalPrice() << std::endl;
    std::cout << std::endl << "Your order will be right out!";      // wait time?

    // sends order to printOrder function:
    printOrder(currentOrder);
}

void printOrder(order& currentOrder)
{
    // writes the "receipt" to a file to act as a printer:
    std::ofstream outFile;
    outFile.open("Printer.txt");
    // utilization of overloaded insertion operator:
    outFile << currentOrder;
    outFile.close();
}
// kitchen functions should go here:


#endif
