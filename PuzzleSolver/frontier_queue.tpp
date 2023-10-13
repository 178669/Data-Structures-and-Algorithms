#include "frontier_queue.hpp"

// TODO implement the member functions here

template <typename T>
State<T> frontier_queue<T>::pop() {

  //TODO, fronter is a MIN HEAP, parent is less than children

  //implement this the same way we implemented pop in the heap lecture. Compare using getFCost
  State<T> ret=queue[0];//saving the value from the queue (saving the state)
  queue[0] = queue[queue.size()-1];//make the last item root
  queue.erase(queue.begin()+queue.size()-1);//deleting the last item that was copied to be root

  //as root currently may be improper, algorithm needed to re-order:
  int i=0;//index counter variable
  int l;//left
  int r;//right
  while(2*i+1<queue.size())//2*i+1 is less than the total size, then current node i is not a leaf.
    {
      l=2*i+1;
      if((2*i)+2<queue.size())
        {
          r=l+1;
          if(queue[r].getFCost()<queue[l].getFCost())
            {
              l=r;//is right costs more than left, swap as left has to be smaller
            }
        }
      if(queue[i].getFCost()>queue[l].getFCost())
        {//root cannot be greater than smallest child bc this is min heap
          State<T> temp=queue[l];//temp to store left value
          queue[l]=queue[i];//copying the root state
          queue[i]=temp;//new root is set equal to original left value
        }
      else 
        {
          break;//if passes all if cases, then the root and children are correctly ordered
        }
    }
  // needs return statement
  return ret;
}

template <typename T>
void frontier_queue<T>::push(const T &p, std::size_t cost, std::size_t heur) 
{
  //TODO
  State<T> input(p,cost,heur);//creating an item of type State<T> with the inputs
  queue.push_back(input);//pushing input item into queue
  //now need to implement sorting to verify positions:
  int i=queue.size()-1;//index variable
  int par;//parent index variable

  while(i>0)//while index is greater than 0, as 0 would signify child.
    {
      par=(i-1)/2;//index of parent
      if(queue[i].getFCost()>queue[par].getFCost())
        {
          break;//current node is greater than parent, correct position
        }
      else 
        {//if current isn't >parent, then swaps and loops until current is > parent, as parent has to be smallest.
          queue[i]=queue[par];
          queue[par]=input;
          i=par;
        }
    }
}

template <typename T>
bool frontier_queue<T>::empty() {

  //TODO
  return queue.empty();
}

template <typename T> 
bool frontier_queue<T>::contains(const T &p) {

  //TODO
  for(int i=0;i<queue.size();i++)
    {
      if(queue[i].getValue()==p)
        {
          return true;//if p found, return true
        }
    }
  return false;//otherwise, false

}

template <typename T>
void frontier_queue<T>::replaceif(const T &p, std::size_t cost) {

  //TODO
  for(int i=0;i<queue.size();i++)
    {
      if(cost<queue[i].getFCost())
        {
          queue[i].updatePathCost(cost);
          break;
        }
    }
}


