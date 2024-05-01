#ifndef NODE_H
#define NODE_H
#include <string>

class Node
{
public:



private:
    Node* next;
    Node* previous;
    std::string order;      // ex: order # or customer name
    double totalPrice;      // ex: total price

};




#endif