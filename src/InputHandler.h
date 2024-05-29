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

void displayMenu(kitchen& kitchen);
void placeOrder(order& currentOrder, kitchen& kitchen);
void showCurrentOrder(order& currentOrder);
void calculateTip(order& currentOrder);
void finishOrder(order& currentOrder, float& finalTip, float& finalTotal);
void printOrder(order& currentOrder, float& finalTip, float& finalTotal);
void kitchenMenu(kitchen& kitchen);

void displayMenu(kitchen& kitchen)
{
    order currentOrder;
    char answer = '/0';

    // loop allows customer to have multiple tries if input is incorrect:
    while(toupper(answer) != 'Y')
    {
        // menu display:
        std::cout << "\nGreetings Valued Customer!\n";
        std::cout << "Press Y to continue to ordering page.\n";
        std::cout << "Press N to quit.\n";
        std::cin >> answer;
        std::cout << std::endl;
        if(toupper(answer) == 'Y')
        {
            // customer will be taken to placeOrder:
            system("clear");
            placeOrder(currentOrder, kitchen);
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

void placeOrder(order& currentOrder, kitchen& kitchen)
{
    int itemChoice;
    int orderMore;

    do
    {
        // food menu display:
        // prints the options to order, and takes in the user's choice
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
            break;
        
        case 2:
            // item chosen by customer is added to order:
            currentOrder.addItem("Pizza Slice", 27.99, 1);        
            break;
        
        case 3:
            // item chosen by customer is added to order:
            currentOrder.addItem("Burrito", 78.99,1);        
            break;
        
        case 4:
            // item chosen by customer is added to order:
            currentOrder.addItem("Hambürger ", 50.99,1);       
            break;
        
        case 5:
            // reverts back to main menu:
            displayMenu(kitchen);
            system("clear");
            return;
        
        default:
            // error handling message:
            std::cout << "Error - please enter a valid choice from the menu screen.\n";
            continue;
        }
    
        showCurrentOrder(currentOrder);   

          // loop showcases an additional menu screen, where customer can add/remove items or finish their order:
        do
        {
            // menu display:
            std::cout << "Press 1 to add another item.\nPress 2 to remove an item.\n"
            << "Press 3 to finish your order.\nPress 4 to return to Main Menu (order will be reset).\n\n";
            std::cin >> orderMore;

            if (orderMore == 1)
            {
                // break the inner loop to add another item
                break;
            }
            else if (orderMore == 2)
            {
                int removeIndex;
                std::cout << "Which item would you like to remove? ";
                std::cin >> removeIndex;
                // item chosen corresponds to the index on the entire order, removeItem() is called:
                currentOrder.removeItem(removeIndex);
                // updated order is shown to user after item removal:
                showCurrentOrder(currentOrder);
            }
            else if (orderMore == 3)
            {
                // exit both loops to finish the order
                calculateTip(currentOrder);
                kitchen.setHead(&currentOrder);
                return;
            }
            else if (orderMore == 4)
            {
                displayMenu(kitchen);
                return; // exit this function to avoid adding more items
            }
            else
            {
                // error handling message:
                std::cout << "Invalid Entry. Please Try Again.\n\n";
            }
        }
        // allows for user to re-try if input does not correspond to menu:
        while (true);
        }
    // encapsulating loop condition, will exit if customer chooses to finish order:
    while (orderMore != 3);
    system("clear");
    calculateTip(currentOrder);
}

void showCurrentOrder(order& currentOrder)
{
    // lists order items and total price:
    std::cout << UNDERLINE << "Your current order:" CLOSEUNDERLINE << std::endl;
    currentOrder.listItems();
    std::cout << std::endl << "Total: $"<< currentOrder.getTotalPrice() << std::endl << std::endl;

}

void calculateTip(order& currentOrder)
{
    int tipChoice;
    float finalTip;
    float finalTotal;
    float tenPercent = (currentOrder.getTotalPrice() * .10); 
    float fifteenPercent = (currentOrder.getTotalPrice() * .15);
    float twentyPercent = (currentOrder.getTotalPrice() * .20);
    std::cout << std::fixed << std::setprecision(2);

    std::cout<< "Your total is: $" << currentOrder.getTotalPrice();
    std::cout << "\n\nAdd a tip?\n";
    std::cout << "(0) - No Tip" << "\t\t(1) 10% - $" << tenPercent << "\t\t(2) 15% - $" << fifteenPercent << "\t\t(3) 20% - $" << twentyPercent;
    std::cout << "\n(4) Custom Tip\n\n";
    std::cout << "Enter your choice: ";
    std::cin >> tipChoice;

    switch(tipChoice)
    {
    case 0:
        finalTip = 0.0;
        break;
    case 1:
        finalTip = tenPercent;
        break;
    case 2:
        finalTip = fifteenPercent;
        break;
    case 3:
        finalTip = twentyPercent;
        break;
    case 4:
        std::cout << "Custom Tip: $";
        std::cin >> finalTip;
        break;
    default:
        std::cout << "Error - invalid choice. No tip added.\n";
        finalTip = 0.0;
    }

    finalTotal = (currentOrder.getTotalPrice()) + finalTip;
    finishOrder(currentOrder, finalTip, finalTotal);
}


void finishOrder(order& currentOrder, float& finalTip, float& finalTotal)
{
    system("clear");
    // lists order items and total price as final reference for user:
    std::cout << UNDERLINE << "Your receipt:" << CLOSEUNDERLINE << std::endl;
    // we should probably put order # here:
    currentOrder.listItems();
    std::cout << std::endl << "Total: $"<< currentOrder.getTotalPrice() << std::endl;
    std::cout<< std::endl << "Tip: $" << finalTip << std::endl;
    std::cout<< std::endl<< "Final Total: $" << finalTotal << std::endl;
    std::cout << std::endl << "Your order will be right out!\n";      

    // sends order to printOrder function:
    printOrder(currentOrder, finalTip, finalTotal);
}


void printOrder(order& currentOrder, float& finalTip, float& finalTotal)
{
    std::cout << std::fixed << std::setprecision(2);
    // writes the "receipt" to a file to act as a printer:
    std::ofstream outFile;
    outFile.open("Printer.txt");
    // utilization of overloaded insertion operator:
    outFile << currentOrder << std::endl;
    outFile  << "Tip: $" << finalTip << std::endl;
    outFile << "Final Total: $" << finalTotal << std::endl;
    outFile.close();
}
// kitchen functions should go here:

void kitchenLogin(kitchen& kitchen)
{
  //this should enter a loop
  //3 cases:
  //right password
  //wrong password
  //user decides to go back
  //when the user quits, we should drop out of this loop
  //then the menu will repeat
  //otherwise we stick in the login loop
  bool userContinue = true;
  while(userContinue)
  {
    std::string password = "123";
    //prompt the user to enter the password or type quit
    std::cout << "Please enter the password or type \"quit\"";
    std::cout << "\n>";
    std::string userInput;
    std::cin >> userInput;
    //if quit set continue false and drop
    if(userInput == "quit")
    {
      userContinue = false;
    }
    //else if password right, call kitchen
    else if(userInput == password)
    {
      kitchenMenu(kitchen);
      userContinue = false;
      break;
    }
    //else we continue
  }
}

void kitchenMenu(kitchen& kitchen)
{
  bool run = true;
  while(run)
  {
    //print the kitchen's list of orders
    kitchen.listOrders(kitchen.getHead());
    
    
  }
}


#endif
