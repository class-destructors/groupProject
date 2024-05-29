//this is for ad-hoc experiments into the functionality of the other components

#include<iostream>
#include<string>
#include"InputHandler.h"

using namespace std;

int main()
{
  order kate;
  order rachel;
  order hugo;

  kate.addItem("Hamburger", 20, 1);
  kate.addItem("Pizza", 10, 2);

  rachel.addItem("Burger", 20, 1);
  rachel.addItem("Quesadilla", 15, 2);
  rachel.addItem("Wings", 13, 3);

  

  rachel.listItems();

  kate.listItems();

  kitchen kitchen;
  kitchen.setHead(&kate);
  kitchen.setHead(&rachel);
  cout << "This is a test!" << endl;

  kate.clearItems();
  
  kitchen.listOrders(kitchen.getHead());

  order* findKate = kitchen.searchOrders(1, *kitchen.getHead());
  cout << "reached?" << endl;
  cout << *findKate;
  
  kitchen.removeOrder(1);

  kitchen.listOrders(kitchen.getHead());

  return 0;
}
