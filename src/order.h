#pragma once

#include "menuItem.h"

class order
{
    private:
        order* next;
        item * items;
        int id;
        float price;
        int table;
        item * head;
        item * tail;

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
        ~order();
};