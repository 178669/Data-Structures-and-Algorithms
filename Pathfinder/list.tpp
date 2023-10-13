#include "list.hpp"

template <typename T>
List<T>::List() 
  {
    Array=new T [0];//creating a Array of size 0;
    size=0;

  }

template <typename T>
List<T>::~List() 
  {
    delete[] Array;
  }

template <typename T>
List<T>::List(const List& rhs)
  {
    Array=new T [rhs.getCurrentSize()];//make new array of same size
    size=rhs.getCurrentSize();
    for(int i=0;i<rhs.getCurrentSize();i++)//fill array with same contents
        {
          Array[i]=rhs.Array[i];//copying other DynamicBag object's Array into this one
        }

  }

template <typename T>
List<T>& List<T>::operator=(List rhs){
  swap(rhs);
  return *this;
}

template <typename T>
void List<T>::swap(List& rhs) {
  std::swap(Array,rhs.Array);
  std::swap(size,rhs.size);
}

template <typename T>
bool List<T>::isEmpty() const noexcept {
  if(size==0)
    {
      return true;
    }
  else
  {
    return false;
  }
}

template <typename T>
std::size_t List<T>::getLength() const noexcept {
  return size;//just returns size
}

template <typename T>
void List<T>::insert(std::size_t position, const T& item){
  int oldsize=getCurrentSize();
  if(position>=0&&position<=size)
  {
  size=size+1;
  T newArray[size];//create new Array of 1 more length than the last
  
  for(int i=0;i<size;i++)
    {
      if(i<position)//if index isnt the last index
        {
          newArray[i]=Array[i];//copy items from old array into new array until insertion point reached
        }
      if(i==position)
        {
          newArray[i]=item;//insert at index
        }
      if(i>position)
        {
          newArray[i]=Array[i-1];//push everything else back by 1
        }
    }
  delete[] Array;//delete oldArray
  Array=new T[size];//recreate array of proper size
  for(int i=0;i<size;i++)
    { 
      Array[i]=newArray[i];//put newArray items back into fresh recreated Array
    }
  if (Array[size-1]==item)//if last index value is equal to input item
    {
     //delete[] newArray; this gives a warning so I'll see how it goes without
      //return true;//return true if added 
    }
  }
  else
  {
    //return false;
    throw std::range_error("insert error");
  }
}

template <typename T>
void List<T>::remove(std::size_t position){
  //*fixxxxxx
    
    /*if(contains(item)&&size>0)//if item is present in bag
      {
        int index;//find index of item
        
          for(int i=0;i<size;i++)//scanning through whole bag
            {
              if(Array[i]==item)//if item matches,
                {
                  index=i;//store item index
                }
            }
    */// no need for my previous index finder anymore
    if(position>=0&&position<size)
    {
    int index=position;//index given by input to be removed     
      //end of find item 
      //start of actually removing: I will remove the item index that is closest to the end (last item in temp index array)
    if(index>size-1||index<0)
      {
       // return false;// returns false if index is invalid
       throw std::range_error("remove error");
      }
    int newsize=size-1;//size of new array after removing the item
    T newArray[newsize];//creating new array
   
    for(int i=0;i<newsize;i++)//loop for new bag size
      {
        if(i<index)//if index is less than index of item being removed
          { 
            newArray[i]=Array[i];//copy the items of old bag to new bag
          }
        if(i>=index)//once equal or greater than item being removed
          {
            newArray[i]=Array[i+1];//only read in values an index greater, so that index of removed item is effectively removed
          }
      }
    //newbag is now created, need to delete oldbag and copy over items again
    delete[] Array;//delete old bag
    Array=new T[newsize];//recreate fresh Array of correct size;
    for(int i=0;i<newsize;i++)
      {
        Array[i]=newArray[i];//refill bag w
      }
    size=newsize;//set this bag's size to the new size
    //return true;//successful
      }
  else
  {  
    //return false;
    throw std::range_error("remove error");
  }
}

template <typename T>
void List<T>::clear() 
  {
      delete[] Array;//deletes Array
      Array=nullptr;//reinitializes to null ptr.
      size=0;
  }

template <typename T>
T List<T>::getEntry(std::size_t position) const {
  return Array[position];//just returns item at index
}

template <typename T>
void List<T>::setEntry(std::size_t position, const T& newValue) 
  {
    Array[position]=newValue;//just sets index value to input
  }

template<typename T>
std::size_t List<T>::getCurrentSize() const
{
  return size;
}


