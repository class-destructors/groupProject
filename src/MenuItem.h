#pragma once

#include <string>

class item
{
private:
    std::string name;
    float price;
    item * nextItem;

public:
    item();      
    item(std::string newName, float newPrice);
    void setName(std::string newName);
    void setPrice(float newPrice);
    void setNext(item* newItem);
    item* getNext() const;
    std::string getItemName() const;
    float getItemPrice() const; 
                                            
    ~item();

};