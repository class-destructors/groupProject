#pragma once

#include "menuItem.h"

class order
{
    private:
        order* next;
        item* items;
        int id;
        float price;
        int table;
        item * head;
        item * tail;
        int noi;

    public:
        order();
        order(int newId, float newPrice, int newTable);
        order(const order& otherOrder);
        order& operator=(const order& rhs);
        //overloaded insertion operator? 
        void addItem(int itemID, float itemPrice);
        std::ofstream printReceipt(); 
        void setOrder(int newId, float newPrice, int newTable);
        void setNext(order* nextOrder);
        order* getNext() const;
        item* getHead() const;
        item* getTail() const;
        int getOrderId() const;
        float getPrice() const;
        void sendToPrinter() const;
        void sendToKitchen() const;
        friend std::ostream& operator<<(std::ostream& out, const item& newItem); 
        order& operator=(const order& rhs);
{

}
        ~order();
};

item::item(const item& otherItem)
{
    if (this->name != otherItem.name)
    {
        name = otherItem.name;
        price = otherItem.price;

        if (otherItem.nextItem != nullptr)
        {
            item* original = otherItem.nextItem;
            item* current = new item;

            if (!current)
            {
                cout << "\n\nERROR : FAILED MEMORY ALLOCATION";
            }

            current->setName(original->getItemName());
            current->setPrice(original->getItemPrice());
        }
        
    }
}