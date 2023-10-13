#include "queue.hpp"

template <typename T, typename L>
void Queue<T,L>::enqueue(const T& item)
{
  // TODO: inserts to the end of the list
  //inserts to the end of the list, so would be at index value of current length.
  internal_list.insert(internal_list.getLength(),item);
}

template <typename T, typename L>
void Queue<T,L>::dequeue()
{
  // TODO: remove from front, throw exception if trying to remove while empty
  if(internal_list.getLength()==0)
    {
      throw std::range_error("Queue is Empty");
    }
  else 
    {
      internal_list.remove(0);//remove item at index 0
    }
}

template <typename T, typename L>
T Queue<T,L>::peekFront()
{
  return internal_list.getEntry(0);
}

template <typename T, typename L>
bool Queue<T,L>::isEmpty() const
{
  if(internal_list.getLength()==0)
    {
      return true;
    }
  return false;
}

