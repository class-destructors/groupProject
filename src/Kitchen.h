#pragma once
#include "Order.h"
#include "MenuItem.h"

class kitchen
{
    private: 
        order * head;
        order * tail;
        int count;
    
    public:
        kitchen();
        int getNumOfOrders() const;
        void setHead(order* newHead);
        void setTail(order* newTail);
        void deleteHead();
        order* getHead() const;
        order* getTail() const;
        int getCount() const;
        ~kitchen();
        
};
