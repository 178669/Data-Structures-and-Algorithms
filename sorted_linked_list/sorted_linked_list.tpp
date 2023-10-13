#include "sorted_linked_list.hpp"
#include <stdexcept>

template <typename T>
SortedLinkedList<T>::SortedLinkedList(): LinkedList<T>()
{
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(LinkedList<T> unsorted_list) 
{
  // TODO
  //unsorted_list.sort();
 // SortedLinkedList<T> dog;
  for(int i=0;i<unsorted_list.getLength();i++)
    {
      insert(unsorted_list.getEntry(i));
    }
  
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T> & x):
  LinkedList<T>(x)
{

}

template <typename T>
SortedLinkedList<T>& SortedLinkedList<T>::operator=(SortedLinkedList<T> x)
{
  LinkedList<T>::operator=(x);
  return *this;
}

template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
  // base destructor gets called automatically
}

template <typename T>
bool SortedLinkedList<T>::isEmpty() const noexcept
{
  return LinkedList<T>::isEmpty();
}

template <typename T>
std::size_t SortedLinkedList<T>::getLength() const noexcept
{
  return LinkedList<T>::getLength();
}

template <typename T>
void SortedLinkedList<T>::insert(const T& item)
{
  LinkedList<T>::insert(getLength(),item);
  // TODO
}

template <typename T>
void SortedLinkedList<T>::remove(const T& item)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  
  int i=0;
  bool present=false;
  while (!present&&i<getLength()) 
  {
    if (LinkedList<T>::getEntry(i)==item) 
    {
      LinkedList<T>::remove(i);
      present=true;
    }
    i++;
  }
  // TODO
}

template <typename T>
void SortedLinkedList<T>::removeAt(std::size_t position)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  LinkedList<T>::sort();
  LinkedList<T>::remove(position);
  // TODO
}

template <typename T>
void SortedLinkedList<T>::clear()
{
  LinkedList<T>::clear();
} 

template <typename T>
T SortedLinkedList<T>::getEntry(std::size_t position) const
{
  return LinkedList<T>::getEntry(position);
}

template <typename T>
long int SortedLinkedList<T>::getPosition(const T& item)
{
    int i;
    for (i = 0; i < getLength(); i++)
      {
        if (getEntry(i) == item)
          return i;//returns item if found immediately
      }
    if (i == getLength())//if i has reached end of list 
      {                                             
        return -1; //returns -1 if not found in list
      } 
    
}

template <typename T>
LinkedList<T> SortedLinkedList<T>::sort(LinkedList<T> list)
{//bubblesort implementation 
//**NO INSTRUCTION FOR RECURSION REQUIRED**
    size_t size = list.getLength();
        for(int i = 0; i < size - 1; i++){
            for (int j = 0; j < size - i - 1; j++){
                if(list.getEntry(j) > list.getEntry(j+1))//if current enntry is larger than than the next, then it should be swapped
                {
                    T val1,val2;//using T data type template format
                    val1 = list.getEntry(j);//storage variables of the items at indices so that they can be swapped
                    val2 = list.getEntry(j+1);
                    list.setEntry(j,val2);//swapping the entries
                    list.setEntry(j+1,val1);
                }
            }
        }
    return list;
}
