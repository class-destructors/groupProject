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

void kitchen::setHead(order* newHead);
{
  //the order acts as a node of a linked list, so all I have to do is manipulate the order objects to add 
  //a new item 


  //first set the next pointer to the current head
  //second set the head pointer to the new order

  newHead.setNext(newHead);
  head = newHead;
  count++;
}

void kitchen::setTail(order* newTail)
{
  tail.setNext(newTail);
  tail = newTail;
  count++;
}

void kitchen::deleteHead()
{
  //checks if the list is nonempty and contains more than one element
  if(head != nullptr && head.getNext() != nullptr)
  {
    oldHead = head;
    head = oldHead.getNext();
    delete oldHead;
  }
  else
  {
    //handle errors properly here
    std::cout << "ERROR: improper operation on an empty or single element list" << std::endl;
  }
}

order* kitchen::getHead() const
{
  return head;
}

order* kitchen::getTail() const
{
  return tail;
}

