#include "Database.hpp"
template <typename T>
Database<T>::Database() 
{
    // TODO
    //don't think I need to do anything here since I declared
    //my ADT list and key trees as private members
}

template <typename T>
bool Database<T>::isEmpty() 
{
    // TODO
    if(data.isEmpty()==true)
        {
            return true;
        }
    else
        {
            return false;
        }

}

template <typename T>
std::size_t Database<T>::getNumberOfEntries() 
{
   return data.getLength();
}

template <typename T>
bool Database<T>::add(std::string key1, std::string key2, const T& item) {
    // TODO: remember to save the data as the index of the list rather than the actual data
    int index=data.getLength();//the index that the item will be
    //check if tree inserts are successful before saving indexes:
    //if(tree1.insert(key1,index)&&tree2.insert(key2,index))
    //^realized that to check the insert bool, I can't use it in if statements multiple times, need to save to a bool once.
    bool valid1,valid2;
    valid1=tree1.insert(key1,index);
    valid2=tree2.insert(key2,index);
    if(valid1&&valid2)//if both valid
        {
            keys1.insert(index,key1);//save key
            keys2.insert(index,key2);//save key
            data.insert(index,item);//save item
            return true;
        }
    //cases for if either of them fail. The one that didn't fail would have to get the key removed, then return false overall.    
    else if(valid1)
        {
            tree1.remove(key1);
            return false;

        }
    else if(valid2)
        {
            tree2.remove(key2);
            return false;
        }
    return false;
    // data.insert(data.getCurrentSize,item);//i don't think ordering matters for now, but this is just adding item to the end
    // tree1<key1,index>;//save key1 with index of item
    // tree2<key2,index>;//save key2 with the same index stored as key1
    // return false;
}

template <typename T>
bool Database<T>::remove(std::string key) {
    // TODO: if removal from middle of list, I would have to update all the node indexes
    
    //can use tree1.remove()
    int index;//should retrieve integer value for index from retrieve()
    if(!tree1.retrieve(key,index)&&!tree2.retrieve(key,index))//if the input key wasn't found in either of the trees
        {
            //don't remove any data if a key wasn't found
            return false;
        }
    //cases for the key is found in either tree, there shouldn't be a case where both trees hold the same key, so not implementing for that
    else if(tree1.retrieve(key,index))//if only tree1 retrieves successfully 
        {
            tree1.remove(key);//remove the key from tree 1
            std::string other=keys2.getEntry(index);//getting the second key string and 
            tree2.remove(other);//remove the other key that wasn't successful
            //still need to find out how to delete the other key, as it is now referencing a deleted value
        }
    else if(tree2.retrieve(key,index))
        {
            tree2.remove(key);//remove the key from tree 2
            std::string other=keys1.getEntry(index);//getting the second key string and 
            tree1.remove(other);//remove the other key that wasn't successful
        }
    //need to update the removal of the keys on the respective list of strings
    keys1.remove(index);
    keys2.remove(index);
    data.remove(index);//remove the data at the index
    return true;
}

template <typename T>
void Database<T>::clear() {
    // TODO
    //have to delete all trees, keys, and stored data.
    tree1.destroy();
    tree2.destroy();
    keys1.clear();
    keys2.clear();
    data.clear();
   
}

template <typename T>
T Database<T>::getValue(std::string key) {
    // TODO
    int index;
    //if item is found in tree 1...
    if(tree1.retrieve(key,index))
        {
            return data.getEntry(index);//return data at retrieved index
        }
    //if not found in tree 1, then must be in tree2
    else
        {
            tree2.retrieve(key,index);
            return data.getEntry(index);//return data at retrieved index
        }
}

template <typename T>
bool Database<T>::contains(std::string key) {
    // TODO
    int index;
    bool in1,in2;//booleans to save if either tree has input key within it
    in1=tree1.retrieve(key,index);
    in2=tree2.retrieve(key,index);
    if(in1||in2)
        {
            return true;
        }
    return false;
}
