#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "adjacency_list_graph.hpp"

TEST_CASE("Test Construction", "[construction]") {
  AdjacencyListGraph<int>  ListGraph;
  ListGraph.add(1,2);
  REQUIRE(ListGraph.getNumVertices() == 2);
}

TEST_CASE("Test Add Alot","[getNumVertices & getNumEdges]") {
  AdjacencyListGraph<int>  ListGraph;
  ListGraph.add(1,2);
  ListGraph.add(1,3);
  ListGraph.add(1,4);
  ListGraph.add(1,5);
  ListGraph.add(1,6);
  ListGraph.add(1,7);
  ListGraph.add(1,8);
  REQUIRE(ListGraph.getNumVertices() == 8);
  REQUIRE(ListGraph.getNumEdges() == 7);
}

TEST_CASE("Test Remove","[getNumVertices & getNumEdges]") {
  AdjacencyListGraph<int>  ListGraph;
  ListGraph.add(1,2);
  ListGraph.add(1,3);
  ListGraph.add(1,4);
  ListGraph.add(1,5);
  ListGraph.add(1,6);
  ListGraph.add(1,7);
  ListGraph.add(1,8);
  ListGraph.remove(1,2);
  REQUIRE(ListGraph.getNumVertices() == 7);
  REQUIRE(ListGraph.getNumEdges() == 6);
}

TEST_CASE("Test Remove All Edges","[getNumVertices & getNumEdges]") {
  AdjacencyListGraph<int>  ListGraph;
  ListGraph.add(1,2);
  ListGraph.add(1,3);
  ListGraph.add(1,4);
  ListGraph.add(1,5);
  ListGraph.add(1,6);
  ListGraph.add(1,7);
  ListGraph.add(1,8);
  ListGraph.remove(1,2);
  ListGraph.remove(1,3);
  ListGraph.remove(1,4);
  ListGraph.remove(1,5);
  ListGraph.remove(1,6);
  ListGraph.remove(1,7);
  ListGraph.remove(1,8);
  REQUIRE(ListGraph.getNumVertices() == 0);
  REQUIRE(ListGraph.getNumEdges() == 0);
}

