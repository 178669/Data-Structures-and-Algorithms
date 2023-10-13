#ifndef LIST_HPP
#define LIST_HPP

#include "abstract_list.hpp"

template<typename T>
class List: public AbstractList<T>
{
public:

  // default constructor
  List();

  // destructor
  ~List();

  // copy constructor
  List(const List& rhs);

  // copy assignment
  List& operator=(List rhs);

  // swap 
  void swap(List& rhs);
  
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

  std::size_t getCurrentSize() const;
private:
  T* Array=nullptr;
  int size;
  // TODO
  
};

#include "list.tpp"

#endif

