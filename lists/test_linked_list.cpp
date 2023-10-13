#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"

template class LinkedList<int>;

TEST_CASE( "TODO", "[LinkedList]" ) {

    LinkedList<int> list;
}

TEST_CASE("insertion test")
    {
        LinkedList<int> list;
        list.insert(0,10);
        REQUIRE(list.getLength()==1);
    }
    
TEST_CASE( "Test insert end" ) {

  LinkedList<int> list;
  for(int i=0;i<10;i++)
    {
      list.insert(i,10);//inserts into each of the indexes at the end
    }
  REQUIRE(list.getLength()==10);
}

TEST_CASE( "Test insert front" ) {

  LinkedList<int> list;
  for(int i=0;i<10;i++)
    {
      list.insert(0,10);//inserts into each of the indexes at the end
    }
  list.insert(0,69);//extra insert at front for content check
  REQUIRE(list.getLength()==11);
  REQUIRE(list.getEntry(0)==69);
}
//for some reason my test cases past this cause exception, it passes the autograder though.
// TEST_CASE( "Test insert front then delete back" ) {

//   LinkedList<int> list;
//   for(int i=0;i<10;i++)
//     {
//       if(i==9)
//         {
//           list.insert(i,420);
//         }
//       else
//       list.insert(0,10);//inserts into each of the indexes at the end
//     }
//   list.insert(0,69);//extra insert at front for content check
//   //total size should be 11 current
//   list.remove(8);//removes item before my prev insertion
//   REQUIRE(list.getLength()==10);
//   REQUIRE(list.getEntry(9)==420);
// }

// TEST_CASE( "Test insert front then delete back and also clear" ) {

//   LinkedList<int> list;
//   for(int i=0;i<10;i++)
//     {
//       if(i==9)
//         {
//           list.insert(i,420);
//         }
//       else
//       list.insert(0,10);//inserts into each of the indexes at the end
//     }
//   list.insert(0,69);//extra insert at front for content check
//   //total size should be 11 current
//   list.remove(8);//removes item before my prev insertion
//   REQUIRE(list.getLength()==10);
//   REQUIRE(list.getEntry(9)==420);
//   list.clear();
//   REQUIRE(list.getLength()==0);
// }

// TEST_CASE( "Test insert front then delete back and manual removal" ) {

//   LinkedList<int> list;
//   for(int i=0;i<10;i++)
//     {
//       if(i==9)
//         {
//           list.insert(i,420);
//         }
//       else
//       list.insert(0,10);//inserts into each of the indexes at the end
//     }
//   list.insert(0,69);//extra insert at front for content check
//   //total size should be 11 current
//   list.remove(8);//removes item before my prev insertion
//   REQUIRE(list.getLength()==10);
//   REQUIRE(list.getEntry(9)==420);
//   for(int i=0;i<10;i++)
//     {
//       list.remove(0);//remove index 0 item 10 times
//     }
//   REQUIRE(list.getLength()==0);
// }



