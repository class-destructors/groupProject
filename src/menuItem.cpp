#include <iostream>
#include <string>

using namespace std;

#include "menuItem.h"

item::item()     
{
    name = "";
    price = 0.0;
    nextItem = nullptr;
}
item::item(string newName, float newPrice) 
{
    name = newName;
    price = newPrice;
}

void item::setName(std::string newName)
{
    name = newName;
}
void item::setPrice(float newPrice)
{
    price = newPrice;
}
void item::setNext(item* newItem)
{
    nextItem = newItem;
}
item* item::getNext() const
{
    return nextItem;
}
string item::getItemName() const
{  
    return name;
}
float item::getItemPrice() const
{
    return price;
}                                        
item::~item()
{

}