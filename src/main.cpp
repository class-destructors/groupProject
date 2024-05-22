#include <iostream>
#include "order.h"
#include "InputHandler.h"

using namespace std;


int main()
{
    char userType;
    cout << "Welcome to Posh Nosh Inc." << endl;
    cout << "Press 1 to continue as customer." << endl;
    cout << "Press 2 to enter administrator view. Password required.";

    if (userType == 'C')
    {
        displayMenu();
    }
    else if (userType == 'K')
    {
        // first ktichen function
    }


    return 0;
}