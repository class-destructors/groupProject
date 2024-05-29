#include <iostream>
#include <string>

using namespace std;

#include "MenuItem.h"

item::item()     
{
    name = "";
    price = 0.0;
    nextItem = nullptr;
}
item::item(string newName, float newPrice, int newItemNum) 
{
    name = newName;
    price = newPrice;
    itemNum = newItemNum;
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
void item::setItemNum(int newItemNum)
{
    itemNum = newItemNum;
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
int item::getItemNum() const
{
    return itemNum;
}                                        
item::~item()
{

}
