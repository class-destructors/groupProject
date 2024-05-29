#pragma once
#include "Order.h"
#include "MenuItem.h"

class kitchen
{
    private: 
        order * head = nullptr;
        order * tail = nullptr;
        int count;
    
    public:
        kitchen();
        int getNumOfOrders() const;
        void setHead(order* newHead);
        void setTail(order* newTail);
        void deleteHead();
        order* getHead() const;
        order* getTail() const;
        void listOrders(order* current);
        void removeOrder(int orderNum);
        order* searchOrders(int orderId, order& order);
        int getCount() const;
        ~kitchen();
        
};
