#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "list.hpp"
#include "sorted_list.hpp"
#include "priority_queue.hpp"

TEST_CASE("Testing Priority Queue", "[priority queue]") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;
  pq.add(3);
  pq.add(2);
  pq.add(4);
  pq.add(8);
  pq.add(9);
  pq.remove();
  REQUIRE(pq.peek()==8);
  pq.remove();
  REQUIRE(pq.peek()==4);
  pq.remove();
  REQUIRE(pq.peek()==3);
  pq.remove();
  REQUIRE(pq.peek()==2);
}
TEST_CASE("Testubg Priority Queue Add and Remove Multiple") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;
  pq.add(1);
  std::cout<<pq.peek()<<std::endl;

  pq.add(2);
  std::cout<<pq.peek()<<std::endl;

  pq.add(3);
  std::cout<<pq.peek()<<std::endl;

  pq.add(4);
  std::cout<<pq.peek()<<std::endl;

  pq.add(5);
  std::cout<<pq.peek()<<std::endl;

  pq.add(5);
  std::cout<<pq.peek()<<std::endl;

  pq.add(5);
  std::cout<<pq.peek()<<std::endl;

  pq.add(5);
  std::cout<<pq.peek()<<std::endl;

  pq.add(1);
  std::cout<<pq.peek()<<std::endl;

  pq.add(1);
  std::cout<<pq.peek()<<std::endl;

  pq.add(1);
  std::cout<<pq.peek()<<std::endl;

  pq.add(1);
  std::cout<<pq.peek()<<std::endl;

  pq.add(1);
  std::cout<<pq.peek()<<std::endl;

  pq.add(2);
  std::cout<<pq.peek()<<std::endl;

  pq.add(5);
  std::cout<<pq.peek()<<std::endl<<"_"<<std::endl;
  
  pq.remove();
  REQUIRE(pq.peek()==5);
  std::cout<<pq.peek()<<std::endl;
  
  pq.remove();
  REQUIRE(pq.peek()==5);
  std::cout<<pq.peek()<<std::endl;
  
  pq.remove();
  REQUIRE(pq.peek()==5);
  std::cout<<pq.peek()<<std::endl;
  
  pq.remove();
  REQUIRE(pq.peek()==5);
  std::cout<<pq.peek()<<std::endl;
  
  pq.remove();
  REQUIRE(pq.peek()==4);
  std::cout<<pq.peek()<<std::endl;
  
  pq.remove();
  REQUIRE(pq.peek()==3);
  std::cout<<pq.peek()<<std::endl;
  
  pq.remove();
  REQUIRE(pq.peek()==2);
  std::cout<<pq.peek()<<std::endl;
  
  pq.remove();
  REQUIRE(pq.peek()==2);
  std::cout<<pq.peek()<<std::endl;

  pq.remove();
  REQUIRE(pq.peek()==1);
  std::cout<<pq.peek()<<std::endl;
}