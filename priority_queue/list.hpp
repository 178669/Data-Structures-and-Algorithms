#ifndef _LIST_HPP_
#define _LIST_HPP_

#include "abstract_list.hpp"
#include "Node.hpp"

template <typename T>
class List: public AbstractList<T>
{
public:
  
  // default constructor
  List();
  
  // copy constructor
  List(const List& x);
    
  // destructor
  ~List();
  
  // copy assignment
  List& operator=(List x);

  void swap(List& x);
  
  // determine if a list is empty
  bool isEmpty() const noexcept;

  // return current length of the list
  std::size_t getLength() const noexcept;

  // insert item at position in the list
  void insert(std::size_t position, const T& item);

  // remove item at position in the list
  void remove(std::size_t position);

  // remove all items from the list
  void clear();

  // get a copy of the item at position
  T getEntry(std::size_t position) const;

  // set the value of the item at position 
  void setEntry(std::size_t position, const T& newValue);
 
  //void sort();

 // List<T> sort(List<T>);

private:
  Node<T> **head=&pointer;//pointer to head
  Node<T> *pointer;//pointer that head points to so that if pointer change, den head change too
  int numnodes;//integer value of new nodes
};

//#include "list.tpp"

#endif
