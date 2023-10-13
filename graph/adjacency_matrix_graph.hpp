#ifndef _ADJACENCY_MATRIX_GRAPH_H_
#define _ADJACENCY_MATRIX_GRAPH_H_

#include "abstract_graph.hpp"
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <list>
template <typename LabelType>
class AdjacencyMatrixGraph: public AbstractGraph<LabelType>
{
    public:

        AdjacencyMatrixGraph();

        int getNumVertices() const;
        
        int getNumEdges() const;

        bool add(LabelType start, LabelType end);

        bool remove(LabelType start, LabelType end);

        void depthFirstTraversal(LabelType start, void visit(LabelType&));

        void breadthFirstTraversal(LabelType start, void visit(LabelType&));
    private:
        //int vertices;
        std::vector<std::vector<bool>> matrix;//declaring a dynamic matrix, will always be square

        std::vector<LabelType> keyindex;//vector to add keys in, to match 1:1 with the x items of matrix
        //^^may have to redo all of the above with a 2D array instead, I can't fix segfaults using iterators with 2D vector
        //std::vector<std::vector<int>>::iterator x;//row iterator

        //bool matarr[0][0];// array matrix of initially size 0
        std::vector<int>::iterator it;
        std::vector<int>::iterator it2;

        std::vector<std::list<bool>> listmat;//vector of lists to use as matrix
        std::vector<int> vertvec;
        int x,y;
        int edges=0;
        int verts=0;
        std::vector<int> removedindices;
        int removed=0;
        //std::set<LabelType> keys;// i cannot quite see the purpose of using set instead of vector or if the c requirement can be covered by just vectors alone.

};

#include "adjacency_matrix_graph.tpp"

#endif 
