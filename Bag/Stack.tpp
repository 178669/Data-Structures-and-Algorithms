//  Adapated from Frank M. Carrano and Timothy M. Henry.

/** ADT Stack implementation.
    @file Stack.cpp */

#include <iostream>
#include <cstddef>
#include "Stack.hpp"
#include "Node.hpp"

// TODO: Implement the constructor here
template<class ItemType>
Stack<ItemType>::Stack() 
{
	headPtr=NULL;//set to null initially for empty
}  // end default constructor

// TODO: Implement the destructor here
template<class ItemType>
Stack<ItemType>::~Stack()
{
	delete headPtr;//deletes headptr
}  // end destructor

// TODO: Implement the isEmpty method here
template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
	if(currentSize==0)
		{
			return true;//true is empty
		}
	else
		{
			return false;//false if not empty
		}
}  // end isEmpty

// TODO: Implement the size method here
template<class ItemType>
int Stack<ItemType>::size() const
{
	return currentSize;
}  // end size

// TODO: Implement the push method here
template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem)
{
	Node<ItemType>* temp=new Node<ItemType>(newItem);//allocates memory for newItem node
	// if(!temp)// idk if we need to put a cap on stack size
	// 	{
	// 		return false;
	// 	}
	temp->setItem(newItem);//just incase it didn't set item 
	temp->setNext(headPtr);//set the next to headPtr, so it acts like SP incremented
	headPtr=temp;//makes most recently put in the top of stack	
	currentSize++;//add size
	return true;
}  // end push

// TODO: Implement the peek method here
template<class ItemType>
ItemType Stack<ItemType>::peek() const
{
	ItemType returnItem;
	if(!isEmpty())
		{
			returnItem=headPtr->getItem();//getting item from top of stack
		}
	else
		{
			throw std::logic_error("Stack Empty");
		}
	return returnItem;//returns the item
}  // end peek

// TODO: Implement the pop method here
template<class ItemType>
bool Stack<ItemType>::pop() 
{
	Node<ItemType>* temp;//temp node
	if(headPtr==NULL)//if empty then don't run
		{
			return false;
		}
	else//otherwise, pop
		{
			temp=headPtr;
			headPtr=headPtr->getNext(); //increments head pointer to point to item after remvoval
			delete temp;//delete temp node
		}
	currentSize--;//decrement after a pop
	return true;
}  // end pop

// TODO: Implement the clear method here
template<class ItemType>
void Stack<ItemType>::clear()
{
	headPtr=NULL;//resets headPtr to empty
	currentSize=0;//0 if cleared 
}  // end clear

