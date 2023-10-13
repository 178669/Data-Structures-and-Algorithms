
#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <iostream>
#include "binary_search_tree.hpp"
#include "list.hpp"

template <typename T>
class Database
{
public:
  Database();

  // determine if the database is empty
  bool isEmpty();

  // return current number of entries
  std::size_t getNumberOfEntries();

  // insert entry 
  bool add(std::string key1, std::string key2, const T& item);

  // remove entry 
  bool remove(std::string key);

  // remove all entries
  void clear();

  // retrieve the value of the entry associated with the input key
  T getValue(std::string key);

  // return true if an entry exists associated with the input key
  bool contains(std::string key);

private:

  // TODO:
  List<T> data;//"store the data in an ADT list"
  BinarySearchTree<std::string,int> tree1,tree2;//"you will have two binary search trees"
  List<std::string> keys1,keys2;//storing the key strings in a list as well


};

#include "Database.tpp"
#endif // _DATABASE_H_
