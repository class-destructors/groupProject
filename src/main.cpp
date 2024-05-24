#include <iostream>
#include "InputHandler.h"

using namespace std;


int main()
{
    int userType;
    do
    {
        cout << "Welcome to Chef's Kiss Fast Food Co." << endl;
        cout << "Press 1 to continue to customer ordering page." << endl;
        cout << "Press 2 to continue as administrator. Credential Required." << endl;
        cin >> userType;

        switch(userType)
        {
        case 1:
            displayMenu();
            break;
        case 2:
            // enter credential function
        default:
            cout << "Error - Invalid Entry. Please try again." << endl;
        } 
    } while (userType != 1 && userType != 2);
    
   









    return 0;
}