#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "array_list.hpp"

//force class expansion
template class ArrayList<int>;

TEST_CASE( "Test", "[ArrayList]" ) {

  ArrayList<int> list;//constructor test
}

TEST_CASE( "Test insert end" ) {

  ArrayList<int> list;
  for(int i=0;i<10;i++)
    {
      list.insert(i,10);//inserts into each of the indexes at the end
    }
  REQUIRE(list.getCurrentSize()==10);
}

TEST_CASE( "Test insert front" ) {

  ArrayList<int> list;
  for(int i=0;i<10;i++)
    {
      list.insert(0,10);//inserts into each of the indexes at the end
    }
  list.insert(0,69);//extra insert at front for content check
  REQUIRE(list.getCurrentSize()==11);
  REQUIRE(list.getEntry(0)==69);
}

TEST_CASE( "Test insert front then delete back" ) {

  ArrayList<int> list;
  for(int i=0;i<10;i++)
    {
      if(i==9)
        {
          list.insert(i,420);
        }
      else
      list.insert(0,10);//inserts into each of the indexes at the end
    }
  list.insert(0,69);//extra insert at front for content check
  //total size should be 11 current
  list.remove(8);//removes item before my prev insertion
  REQUIRE(list.getCurrentSize()==10);
  REQUIRE(list.getEntry(9)==420);
}

TEST_CASE( "Test insert front then delete back and also clear" ) {

  ArrayList<int> list;
  for(int i=0;i<10;i++)
    {
      if(i==9)
        {
          list.insert(i,420);
        }
      else
      list.insert(0,10);//inserts into each of the indexes at the end
    }
  list.insert(0,69);//extra insert at front for content check
  //total size should be 11 current
  list.remove(8);//removes item before my prev insertion
  REQUIRE(list.getCurrentSize()==10);
  REQUIRE(list.getEntry(9)==420);
  list.clear();
  REQUIRE(list.getCurrentSize()==0);
}

TEST_CASE( "Test insert front then delete back and manual removal" ) {

  ArrayList<int> list;
  for(int i=0;i<10;i++)
    {
      if(i==9)
        {
          list.insert(i,420);
        }
      else
      list.insert(0,10);//inserts into each of the indexes at the end
    }
  list.insert(0,69);//extra insert at front for content check
  //total size should be 11 current
  list.remove(8);//removes item before my prev insertion
  REQUIRE(list.getCurrentSize()==10);
  REQUIRE(list.getEntry(9)==420);
  for(int i=0;i<10;i++)
    {
      list.remove(0);//remove index 0 item 10 times
    }
  REQUIRE(list.getCurrentSize()==0);
}

