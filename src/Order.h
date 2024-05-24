#pragma once

#include "MenuItem.h"

class order
{
    private:
        order* next;
        int orderID;
        float totalPrice;
        item * head;
        item * tail;
        int noi;

    public:
        order();
        order(int newId, float newTotalPrice);
        order(const order& otherOrder);
        order& operator=(const order& rhs);
        //overloaded insertion operator? 
        void setOrder(int newId, float newTotalPrice);
        void addItem(std::string name, float price, int itemNum);
        void setNext(order* nextOrder);
        order* getNext() const;
        item* getHead() const;
        item* getTail() const;
        int getOrderId() const;
        float getTotalPrice() const;
        void sendToPrinter() const;
        void sendToKitchen() const;
        void clearItems();
        void listItems() const;
        void removeItem(int itemNum);
        friend std::ostream& operator<<(std::ostream& out, const order& myOrder); 
        ~order();
};

