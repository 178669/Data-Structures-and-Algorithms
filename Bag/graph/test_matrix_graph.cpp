#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "adjacency_matrix_graph.hpp"

TEST_CASE("Test Construction", "[construction]") {
  AdjacencyMatrixGraph<int>  matrixGraph;
  matrixGraph.add(1,2);
  REQUIRE(matrixGraph.getNumVertices() == 2);
}

TEST_CASE("Test Add Alot","[getNumVertices & getNumEdges]") {
  AdjacencyMatrixGraph<int>  matrixGraph;
  matrixGraph.add(1,2);
  matrixGraph.add(1,3);
  matrixGraph.add(1,4);
  matrixGraph.add(1,5);
  matrixGraph.add(1,6);
  matrixGraph.add(1,7);
  matrixGraph.add(1,8);
  REQUIRE(matrixGraph.getNumVertices() == 8);
  REQUIRE(matrixGraph.getNumEdges() == 7);
}

TEST_CASE("Test Remove","[getNumVertices & getNumEdges]") {
  AdjacencyMatrixGraph<int>  matrixGraph;
  matrixGraph.add(1,2);
  matrixGraph.add(1,3);
  matrixGraph.add(1,4);
  matrixGraph.add(1,5);
  matrixGraph.add(1,6);
  matrixGraph.add(1,7);
  matrixGraph.add(1,8);
  matrixGraph.remove(1,2);
  REQUIRE(matrixGraph.getNumVertices() == 7);
  REQUIRE(matrixGraph.getNumEdges() == 6);
}

TEST_CASE("Test Remove All Edges","[getNumVertices & getNumEdges]") {
  AdjacencyMatrixGraph<int>  matrixGraph;
  matrixGraph.add(1,2);
  matrixGraph.add(1,3);
  matrixGraph.add(1,4);
  matrixGraph.add(1,5);
  matrixGraph.add(1,6);
  matrixGraph.add(1,7);
  matrixGraph.add(1,8);
  matrixGraph.remove(1,2);
  matrixGraph.remove(1,3);
  matrixGraph.remove(1,4);
  matrixGraph.remove(1,5);
  matrixGraph.remove(1,6);
  matrixGraph.remove(1,7);
  matrixGraph.remove(1,8);
  REQUIRE(matrixGraph.getNumVertices() == 0);
  REQUIRE(matrixGraph.getNumEdges() == 0);
}

