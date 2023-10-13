#include "limited_size_bag.hpp"

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag() {
  numitems=0;//set to empty bag
  limitedarray=new T[numitems];
}
  
template<typename T>
bool LimitedSizeBag<T>::add(const T& item)
{
  if(numitems<100)
  {
  int oldsize=getCurrentSize();
  numitems=numitems+1;
  T newBagArray[numitems];//create new BagArray of 1 more length than the last
 
  for(int i=0;i<numitems;i++)
    {
      if(i!=numitems-1)//if index isnt the last index
        {
          newBagArray[i]=limitedarray[i];//copy items from old array into new array
        }
      else
        {
          newBagArray[i]=item;//if last index, add input item to newarray.
        }
    }
  delete[] limitedarray;//delete oldbagarray
  limitedarray=new T[numitems];//recreate array of proper size
  for(int i=0;i<numitems;i++)
    { 
      limitedarray[i]=newBagArray[i];//put newBagArray items back into fresh recreated BagArray
    }
  if (limitedarray[numitems-1]==item)//if last index value is equal to input item
    {
     //delete[] newBagArray; this gives a warning so I'll see how it goes without
      return true;//return true if added 
    }
  }
  return false;
}

template<typename T>
bool LimitedSizeBag<T>::remove(const T& item)
{
 if(contains(item)&&numitems>0)//if item is present in bag
  {
        int index;//find index of item
        
          for(int i=0;i<numitems;i++)//scanning through whole bag
            {
              if(limitedarray[i]==item)//if item matches,
                {
                  index=i;//store item index
                }
            }     
      //end of find item 
      //start of actually removing: I will remove the item index that is closest to the end (last item in temp index array)
    int newsize=numitems-1;//size of new array after removing the item
    T newBagArray[newsize];//creating new array
    for(int i=0;i<newsize;i++)//loop for new bag size
      {
        if(i<index)//if index is less than index of item being removed
          { 
            newBagArray[i]=limitedarray[i];//copy the items of old bag to new bag
          }
        if(i>=index)//once equal or greater than item being removed
          {
            newBagArray[i]=limitedarray[i+1];//only read in values an index greater, so that index of removed item is effectively removed
          }
      }
      //newbag is now created, need to delete oldbag and copy over items again
      delete[] limitedarray;//delete old bag
      limitedarray=new T[newsize];//recreate fresh BagArray of correct size;
      for(int i=0;i<newsize;i++)
        {
          limitedarray[i]=newBagArray[i];//refill bag w
        }
      numitems=newsize;//set this bag's size to the new size
      return true;//successful
  }

    return false;
}


template<typename T>
bool LimitedSizeBag<T>::isEmpty() const
{
  if(numitems==0)
    {
      return true;
    }
  else
    {
  return false;
    }
}

template<typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const
{
  return numitems;
}

template<typename T>
bool LimitedSizeBag<T>::contains(const T& item) const
{  
  int counter;
  for(int i=0;i<numitems;i++)
        {
          if(limitedarray[i]==item)
            {
              return true;
            }
        }
  return false;
}

template<typename T>
void LimitedSizeBag<T>::clear(){
  numitems=0;//item counter
  delete[] limitedarray;
}

template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T & item) const
{
  if(numitems>0)
  {
  size_t counter=0;
  if(contains(item))
    { 
      for(int i=0;i<numitems;i++)
        {
          if(limitedarray[i]==item)
            {
              counter++;;//if bag index contains item, return true
            }
        }
      return counter;//returns the counter value
    }
  }
  return 0;//returns 0 if item isnt present in bag.
}
