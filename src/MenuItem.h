#pragma once

#include <string>

class item
{
private:
    std::string name;
    float price;
    int itemNum;
    item * nextItem;

public:
    item();      
    item(std::string newName, float newPrice, int newItemNum);
    void setName(std::string newName);
    void setPrice(float newPrice);
    void setNext(item* newItem);
    void setItemNum(int newItemNum);
    item* getNext() const;
    std::string getItemName() const;
    float getItemPrice() const; 
    int getItemNum() const;

                                            
    ~item();

};