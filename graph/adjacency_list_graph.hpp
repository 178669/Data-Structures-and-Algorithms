#ifndef _ADJACENCY_LIST_GRAPH_H_
#define _ADJACENCY_LIST_GRAPH_H_

#include "abstract_graph.hpp"
#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <algorithm>

template <typename LabelType>
class AdjacencyListGraph: public AbstractGraph<LabelType>
{
    public:

        AdjacencyListGraph();
        
        int getNumVertices() const;
        
        int getNumEdges() const;

        bool add(LabelType start, LabelType end);

        bool remove(LabelType start, LabelType end);

        void depthFirstTraversal(LabelType start, void visit(LabelType&));

        void breadthFirstTraversal(LabelType start, void visit(LabelType&));
    private:
        //personal comments: graph is collection of vertices (nodes) and connections (edges)
        //ex G={V,E}
        //a mathematical concept, data structure, and an ADT - probably an exam question
        //use undirected edges, NOT multi-graphs [at most one edge between 2 points], 
        //std::vector<std::vector<LabelType>> adj;//dynamic list of lists
       // std::vector<std::vector<LabelType>> removed;//dynamic list of lists
        int edges=0;
       //std::map<LabelType,int> keys;//creating this to store the keys, then the data will reference an index of a vector that contains the edges
        std::map<LabelType,std::vector<LabelType>> link;//testing this, so this should create maps with the label type key, and then edges associated with it through a vector.
       // std::map<LabelType,bool> visited;//for search algorithms
};      

#include "adjacency_list_graph.tpp"

#endif 
