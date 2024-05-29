#include <iostream>
#include <string>
#include "InputHandler.h"

using namespace std;


int main()
{
    int userType;
    kitchen backHouse;
    do
    {
        cout << "Welcome to Chef's Kiss Fast Food Co." << endl;
        cout << "Press 1 to continue to customer ordering page." << endl;
        cout << "Press 2 to continue as administrator. Credential Required." << endl;
        cin >> userType;

        switch(userType)
        {
        case 1:
            displayMenu(backHouse);
            break;
        case 2:
            kitchenLogin(backHouse);
            break;
        default:
            cout << "Error - Invalid Entry. Please try again." << endl;
        } 
        //this doesn't loop properly if the user quits out of the login
        //fix later
    } while (userType != 1 && userType != 2);

    
   









    return 0;
}
