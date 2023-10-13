#include "dynamic_bag.hpp"
//array implementation NOT linked list!!
template<typename T>
DynamicBag<T>::DynamicBag()
{//default for size 0
 BagArray=new T [0];//creating a bagarray of size 0;
 bagsize=0;
}

template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag& x)
{
 BagArray=new T [x.getCurrentSize()];//make new array of same size
 bagsize=x.getCurrentSize();
 for(int i=0;i<x.getCurrentSize();i++)//fill array with same contents
    {
      BagArray[i]=x.BagArray[i];//copying other DynamicBag object's BagArray into this one
    }
}

    
template<typename T>
DynamicBag<T>::~DynamicBag(){//array memory deallocation
  delete[] BagArray;
}
  
template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T> x)
{ 
  swap(x);
  return *this;
}

template<typename T>
void DynamicBag<T>::swap(DynamicBag<T>& x){
  std::swap(BagArray,x.BagArray);
  std::swap(bagsize,x.bagsize);
}

template<typename T>
bool DynamicBag<T>::add(const T& item)
{
  int oldsize=getCurrentSize();
  bagsize=bagsize+1;
  T newBagArray[bagsize];//create new BagArray of 1 more length than the last
 
  for(int i=0;i<bagsize;i++)
    {
      if(i!=bagsize-1)//if index isnt the last index
        {
          newBagArray[i]=BagArray[i];//copy items from old array into new array
        }
      else
        {
          newBagArray[i]=item;//if last index, add input item to newarray.
        }
    }
  delete[] BagArray;//delete oldbagarray
  BagArray=new T[bagsize];//recreate array of proper size
  for(int i=0;i<bagsize;i++)
    { 
      BagArray[i]=newBagArray[i];//put newBagArray items back into fresh recreated BagArray
    }
  if (BagArray[bagsize-1]==item)//if last index value is equal to input item
    {
     //delete[] newBagArray; this gives a warning so I'll see how it goes without
      return true;//return true if added 
    }
  return false;
}

template<typename T>
bool DynamicBag<T>::remove(const T& item)//presumption is that this is only removing one instance of the itme
{//*fixxxxxx
if(contains(item)&&bagsize>0)//if item is present in bag
  {
    int index;//find index of item
    
       for(int i=0;i<bagsize;i++)//scanning through whole bag
         {
          if(BagArray[i]==item)//if item matches,
            {
              index=i;//store item index
            }
        }     
  //end of find item 
  //start of actually removing: I will remove the item index that is closest to the end (last item in temp index array)
int newsize=bagsize-1;//size of new array after removing the item
T newBagArray[newsize];//creating new array
for(int i=0;i<newsize;i++)//loop for new bag size
  {
    if(i<index)//if index is less than index of item being removed
      { 
        newBagArray[i]=BagArray[i];//copy the items of old bag to new bag
      }
    if(i>=index)//once equal or greater than item being removed
      {
        newBagArray[i]=BagArray[i+1];//only read in values an index greater, so that index of removed item is effectively removed
      }
  }
  //newbag is now created, need to delete oldbag and copy over items again
  delete[] BagArray;//delete old bag
  BagArray=new T[newsize];//recreate fresh BagArray of correct size;
  for(int i=0;i<newsize;i++)
    {
      BagArray[i]=newBagArray[i];//refill bag w
    }
  bagsize=newsize;//set this bag's size to the new size
  return true;//successful
  }
  
    return false;
  
}

template<typename T>
bool DynamicBag<T>::isEmpty() const
{
  if(bagsize==0)
    {
      return true;//returns "true" for bag is empty
    }
  return false;
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
  return bagsize;
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{  
  if(bagsize>0)
  {
  for(int i=0;i<bagsize;i++)
    {
      if(BagArray[i]==item)
        {
          return true;//if bag index contains item, return true
        }
    }
  }
  return false;//return false otherwise
}

template<typename T>
void DynamicBag<T>::clear(){
  delete[] BagArray;//deletes bagarray
  BagArray=nullptr;//reinitializes to null ptr.
  bagsize=0;
}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
  if(bagsize>0)
  {
  size_t counter=0;
  if(contains(item))
    { 
      for(int i=0;i<bagsize;i++)
        {
          if(BagArray[i]==item)
            {
              counter++;;//if bag index contains item, return true
            }
        }
      return counter;//returns the counter value
    }
  }
  return 0;//returns 0 if item isnt present in bag.
}
