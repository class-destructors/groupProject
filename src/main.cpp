#include <iostream>
#include "order.h"

using namespace std;


int main()
{
    order test1(45, 89.0);
    order test2(test1);

    cout << test2.getOrderId();
    


    return 0;
}