#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "order.h"


order::order()
{
    orderID = 0;
    totalPrice = 0.0;
    int noi = 0;
    head = nullptr;
    tail = nullptr;
    next = nullptr;
    
}
order::order(int newId, float newTotalPrice)
{
    orderID = newId;
    totalPrice = newTotalPrice;
}
order::order(const order& otherOrder)
{
    orderID = otherOrder.orderID;
    totalPrice = otherOrder.totalPrice;

    if (this->orderID != otherOrder.orderID)
    {
        orderID = otherOrder.orderID;
        totalPrice = otherOrder.totalPrice;

        if (otherOrder.head != nullptr)
        {
            item* original = otherOrder.head;
            item* current = new item();

            if (!current)
            {
                cout << "\n\nERROR : FAILED MEMORY ALLOCATION";
            }

            current->setName(original->getItemName());
            current->setPrice(original->getItemPrice());

            head = current; 
            noi++;

            original = original->getNext(); 

            while(original != nullptr)
            {   
                item* nextItem = new item(); 

                if (!nextItem)
	            {
		            std::cout << "\n\nERROR : FAILED MEMORY ALLOCATION, COULD NOT CREATE NEW CART\n";
	            }

    
                nextItem->setName(original->getItemName());
                nextItem->setPrice(original->getItemPrice());
            
                current->setNext(nextItem); 
                noi++;

                original = original->getNext(); 
                current = current->getNext();
            }
        }
        
    }
}
// void order::addItem(std::string name, float price)
// {
//     item* newItem = new item(name, price);

//     if (!head) 
//     {
//         // If the cart is empty, set the new node as the first and last node:
//         head = tail = newItem;
//     } else 
//     {
//         // If the cart is not empty, add the new node to the end of the list:
//         tail->setNext(newItem);
//         tail = newItem;
//     }

//     // Increment the number of items:
//     noi++;
// }

// order& order::operator=(const order& rhs)
// {
//     // assigning temp pointer to first pointer of rightside
// 	item* current = rhs.getHead();
    
//     // conditional statement to ensure items are not already the same:
//     if (this == &rhs)
//     {
//         cout << "ERROR : ITEM ASSIGNMENT IS TO ITSELF";
//         exit(1);
//     }
//     else if (this != &rhs)
//     {
//         while (current)
//         {
//             // assigning data of rightside to left side:
//             this->addItem(current->getItemName(), current->getItemPrice());
//             current = current->getNext();
//         }
//     }
//     return *this;
// }
// void order::setOrder(int newId, float newTotalPrice)
// {
//     orderID = newId;
//     totalPrice = newTotalPrice;
// }

// void order::setNext(order* nextOrder)
// {
//     next = nextOrder;
// }
// order* order::getNext() const
// {
//     return next;
// }
// item* order::getHead() const
// {
//     return head;
// }
// item* order::getTail() const
// {
//     return tail;
// }
int order::getOrderId() const
{
    return orderID;
}
// float order::getTotalPrice() const
// {
//     double total = 0.0;
//     // beginning at the front of the linked list:
//     item* temp = head;
    
//     // the list will be iterated through until nullptr is reached:
//     while(temp)
//     {
//         // combined assignment operator will continue adding to the total:
//         total += temp->getItemPrice();
//         // move to the next node:
//         temp = temp->getNext();
//     }
//     return total;
// }
// void order::sendToPrinter() const
// {

// }
// void order::sendToKitchen() const
// {

// }
// std::ostream& operator<<(std::ostream& out, const order& myOrder)
// {
//     item* temp = myOrder.head;

// 	while (temp)
// 	{	
// 		out << left << setw(10) << temp->getItemName() << " $" << temp->getItemPrice() << endl;
//         temp = temp->getNext();
// 	}

// 	out << endl << "Total Number of Items: " << myOrder.noi << endl;
//     out << "Total Price: $" << myOrder.getTotalPrice() << endl;

// 	return out;
// }

void order::clearItems()
{
    // beginning at the front of the linked list:
    item* current = head;

    // the list will be iterated through until nullptr is reached:
    while (current != nullptr) 
    {
        item* next = current->getNext();
        delete current;
        current = next;
    }
    head = tail = nullptr;
    noi = 0;
}
order::~order()
{
    clearItems();
}