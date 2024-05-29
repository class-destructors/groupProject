#include<iostream>
#include"Kitchen.h"

//getNumOfOrders and getCount seem to be redundant, leaving both in until confirmation from the group

kitchen::kitchen()
{

}

kitchen::~kitchen()
{

}

int kitchen::kitchen::getNumOfOrders() const
{
  return count;
}

void kitchen::setHead(order* newHead)
{
  //the order acts as a node of a linked list, so all I have to do is manipulate the order objects to add 
  //a new item 


  //first set the next pointer to the current head
  
  //second set the head pointer to the new order
  

  newHead->setNext(head);
  head = newHead;
  count++;
}

void kitchen::setTail(order* newTail)
{
  tail->setNext(newTail);
  tail = newTail;
  count++;
}

void kitchen::deleteHead()
{
  //checks if the list is nonempty and contains more than one element
  if(head != nullptr && head->getNext() != nullptr)
  {
    order* oldHead = head;
    head = oldHead->getNext();
    delete oldHead;
  }
  else
  {
    //handle errors properly here
    std::cout << "ERROR: improper operation on an empty or single element list" << std::endl;
  }
}

void kitchen::listOrders(order* current)
{
  if(current == nullptr)
  {
    std::cout << "\n";
    return;
  }
  else
  {
    std::cout << *current;
    listOrders(current->getNext());
  }
}

void kitchen::removeOrder(int orderNum)
{
  order* previous = nullptr;
  order* current = head;
  order* next = head->getNext();
  bool found = false;
  while(head && !found)
  {
    if(orderNum == current->getOrderId())
    {
      if(previous && next) //check if we're in the middle
      {
        previous->setNext(next);
        delete current;
      }
      else if(!previous) //we're at the start of the list
      {
        delete current;
        head = next;
      }
      else if(!next) //we're at the end of the list
      {
        delete current;
        previous->setNext(nullptr);
        tail = previous;
        found = true;
      }
    }
    else
    {
      previous = current;
      current = next;
      next = next->getNext();
    }
  }
  if(!found)
  {
    std::cout << "Order not found." << std::endl;
  }
}

order* kitchen::searchOrders(int itemNum, order& current)
{
  if(&current == nullptr)
  {
    std::cout << "Error: order not found" << std::endl;
    return nullptr;
  }
  else if(current.getOrderId() == itemNum)
  {
    return &current;
  }
  searchOrders(itemNum, *current.getNext());
}

order* kitchen::getHead() const
{
  return head;
}

order* kitchen::getTail() const
{
  return tail;
}

