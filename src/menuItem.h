#pragma once

#include <string>

class item
{
private:
    std::string name;
    float price;
    item * nextItem;
    //std::string shortDesc;

public:
    item();      
    item(std::string newItem, float newPrice);
    item(const item& otherItem);
    item& operator=(const item& rhs);
    void setName(std::string newName);
    void setPrice(float newPrice);
    void setNext(item* nextItem);
    item* getNext() const;
    std::string getItemName() const;
    float getItemPrice() const;                                               
    ~item();

};