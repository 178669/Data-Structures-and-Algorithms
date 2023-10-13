#include "sorted_list.hpp"

template <typename T, typename L>
SortedList<T, L>::SortedList()
{//constructor to set
  // nothing to do, plist gets created on the stack
}

template <typename T, typename L>
SortedList<T, L>::SortedList(const SortedList<T, L> & x)
{
  plist = x.plist; // use copy assignment to implement copy construction
}

template <typename T, typename L>
SortedList<T, L>& SortedList<T, L>::operator=(SortedList<T, L> x)
{
  plist = x.plist;
  return *this;
}

template <typename T, typename L>
SortedList<T, L>::~SortedList()
{
  // plist destructor gets called automatically
}

template <typename T, typename L>
bool SortedList<T, L>::isEmpty() const noexcept
{
  return plist.isEmpty();
}

template <typename T, typename L>
std::size_t SortedList<T, L>::getLength() const noexcept
{
  return plist.getLength();
}

template <typename T, typename L>
void SortedList<T, L>::insert(const T& item)
{
  if(getLength()==0)
    {
      plist.insert(0,item);//inserts the item if case is that it's empty, manually had to do this for bug fixing
    }
  else//if not empty
    {
      int i;
      int length=getLength();
      for(int i=0;i<length;i++)//loop for whole list
        {
          if(plist.getEntry(i)>item)
            {
              break;
            }
        }
      plist.insert(i,item);//inserts after looping through the list to find an entry greater in value than current, then sends it to the end.
    }

  //plist.insert(getLength(),item);
  //plist.sort();my sorting function breaks code for some reason, using alternative sorting method.
  // TODO
}

template <typename T, typename L>
void SortedList<T, L>::remove(const T& item)
{
  //plist.sort();
  if(isEmpty()) throw std::range_error("empty list in remove");
  
  int i=0;
  bool present=false;
  while (!present&&i<getLength()) 
  {
    if (plist.getEntry(i)==item) 
    {
      plist.remove(i);
      present=true;
    }
    i++;
  }
}

template <typename T, typename L>
void SortedList<T, L>::removeAt(std::size_t position)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
 // plist.sort();
  plist.remove(position);
}

template <typename T, typename L>
void SortedList<T, L>::clear()
{
  plist.clear();
}

template <typename T, typename L>
T SortedList<T, L>::getEntry(std::size_t position) const
{
  return plist.getEntry(position);
}

template <typename T, typename L>
long int SortedList<T, L>::getPosition(const T& newValue)
{
  int i;
  for (i = 0; i < getLength(); i++)
    {
      if (getEntry(i) == newValue)
        return i;//returns item if found immediately
    }
  if (i == getLength())//if i has reached end of list 
    {                                             
      return -1; //returns -1 if not found in list
    } 
  
}

// template <typename T, typename L>
// void SortedList<T, L>::sort()
//   {
//     plist.sort();
//   }
