#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{
  //pointer=nullptr;//pointer initlaly nullptr **doesnt work this way
  pointer=new Node <T>();//this makes it so it is dynamically allocated node i think?? similar to array
  numnodes=0;//zero nodes initially
}

template <typename T>
LinkedList<T>::~LinkedList()
{//destructor for linked list isnt as simple as just delete[] a whole array
  pointer=0;//error bypass
  delete[] pointer;//delete/deallocate pointer to memory space
  numnodes=0;//idk if this should be reset or not
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{//copy constructor, assuming that this is same as prev implmenetations where both
  numnodes=x.getLength();//copying the size of input array to this
  pointer=x.pointer;//copying sifting pointer
  head=x.head;//copying the head pointer value from input
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> x)
{
  swap(x);//swapping and then returning this
  return *this;
}

template <typename T>
void LinkedList<T>::swap(LinkedList& x) 
{
  std::swap(head,x.head);//swapping all private members of this and input linkedlist
  std::swap(pointer,x.pointer);//basically using the same methodology as arraylist
  std::swap(numnodes,x.numnodes);
}

template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
  if(numnodes==0)//if empty
    {
      return true;//return true
    }
  else//not empty otherwise
    {
      return false;
    }
}

template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept
{
  return numnodes;//just returns length of linkedlist
}

template <typename T>
void LinkedList<T>::insert(std::size_t position, const T& item)
{
    Node<T> *newlist=new Node<T>();//create data input node
    newlist->setItem(item);//set data to input data
    if(position>=0&&position<=numnodes)//if valid position, run
      {
        if(position==0)//if zero, then same as head node
          {
            newlist->setNext(*head); 
            *head=newlist;
            numnodes++;
          }
        else
          {
            Node <T> *cpy=*head;//copy node to save data
            for(int i=0;i<position-1;i++)
              {
                cpy=cpy->getNext();//iterate cpy
              }
            newlist->setNext(cpy->getNext());//link newlist and cpy
            cpy->setNext(newlist);//cpy links to newlist
            numnodes++;//iterate
          }
        LinkedList::sort();
        //return true;
      }
      else
        {
          throw std::range_error("insert() position error");
        }
     // return false;
}

template <typename T>
void LinkedList<T>::remove(std::size_t position)
{
  if(position>=numnodes||position<0||isEmpty())//if not pass parameters for valid, exit with false
    {
      //return false;
      throw std::range_error("remove() position error");
    }
 else{
  if((*head)->getItem()==getEntry(position))
    {
      Node<T> *skip=*head;
      *head=(*head)->getNext();
    }
  //for loop with variable set to the already incremented head ptr for the case that 
  //it goes into the if statement above, otherwise, goes through for loop until end
  else{
  for(Node<T> *thiserator=*head;thiserator->getNext()!=NULL;thiserator=thiserator->getNext())//at position-1 bc I want it so that getNext() would end up at position
    {//for loops until end of linkedlist
        if(thiserator->getItem()==getEntry(position-1))
          {
            Node<T> *skipper=thiserator->getNext();
            thiserator->setNext(thiserator->getNext()->getNext());
            delete skipper;
            break;
        }
    }
  }
  numnodes--;
  //return true;
  }
}

template <typename T>
void LinkedList<T>::clear()//as of 2:44pm Monday, my clear isn't working
{
  // while(pointer!=nullptr)//this loops in a backwards order until
  // //pointer ptr is back to default state equal to nullptr;
  //   {
  //     delete pointer;
  //     numnodes=0;
  //   }
  //2:44 newcode
  pointer=0;//abritrary value that the pointer is set to just incase somehow segmentation error bc it hasnt been allocated yet
  delete[] pointer;//deleting
  numnodes=0;
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  Node<T> *thiserator=pointer;
  T item;
  if(position<0||position>=numnodes||isEmpty())
    {
      throw std::range_error("getEntry() range error");
    }
      for(int i=0;i<numnodes;i++)
        {
          if(i==position)
            {
              item=thiserator->getItem();//stores item at location to return variable
            }
          thiserator=thiserator->getNext();//increment until interator is at position
        }
      return item;
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{//this is replacing item at position
Node<T> *thiserator=pointer;
if(position>=0&&position<=numnodes&&!isEmpty())
  {
    for(int i=0;i<numnodes;i++)
      {
        if(i==position)
          {
            thiserator->setItem(newValue);//same thing at getEntry, but instead of getting, set value
          }
        thiserator=thiserator->getNext();//increment until interator is at position
      }
  }
else
  {
    throw std::range_error("setEntry() range error");
  }
}

template <typename T>
void LinkedList<T>::sort()
{//bubblesort implementation 
//**NO INSTRUCTION FOR RECURSION REQUIRED**
    size_t size = getLength();
        for(int i = 0; i < size - 1; i++){
            for (int j = 0; j < size - i - 1; j++){
                if(getEntry(j) > getEntry(j+1))//if current enntry is larger than than the next, then it should be swapped
                {
                    T val1,val2;//using T data type template format
                    val1 = getEntry(j);//storage variables of the items at indices so that they can be swapped
                    val2 = getEntry(j+1);
                    setEntry(j,val2);//swapping the entries
                    setEntry(j+1,val1);
                }
            }
        }
    //return list;
}
template <typename T>
LinkedList<T> LinkedList<T>::sort(LinkedList<T> list)
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