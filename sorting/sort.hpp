#ifndef _SORT_HPP
#define _SORT_HPP

#include "linked_list.hpp"


template<typename T> LinkedList<T> sort(LinkedList<T> list)
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

#endif
