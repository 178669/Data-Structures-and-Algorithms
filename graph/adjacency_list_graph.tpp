#include "adjacency_list_graph.hpp"

template <typename LabelType>
AdjacencyListGraph<LabelType>::AdjacencyListGraph() 
    {

    }

template <typename LabelType> 
int AdjacencyListGraph<LabelType>::getNumVertices() const 
    {
        return link.size();
    }

template <typename LabelType> 
int AdjacencyListGraph<LabelType>::getNumEdges() const 
    {   
        return edges;
    }
        
template <typename LabelType> 
bool AdjacencyListGraph<LabelType>::add(LabelType start, LabelType end) 
    {//if start and end don't exist, then create then
        bool svalid,evalid,endp;//booleans to check which ones are/aren't present in set & endp to check for duplicates
        std::vector<LabelType> temp1,temp2;
        //std::list<LabelType> temp1,temp2;//just to add into the vector.
        svalid=link.count(start);//tests if the label is present in map
        evalid=link.count(end);//same thing
        
        int index;
        if(!svalid)//if start key not found, add to set
            {
                //adj.push_back();
                //adj[adj.size()-1].insert(end);//should be the last list(which should be empty), then inserting into the list, the label.
                temp1.push_back(end);
                //adj.push_back(temp1);

                link.insert({start,temp1});
                //^i think I managed to condense without the use of temp lists
                //temp1.insert(end);//nodes connected
                //adj.push_back(temp1);//add list to vector for indexing and access
                //keys.insert({start,adj.size()-1});//finally, insert the key into the set with the index of vector stored.
            }
        else if(svalid)
            {//case if start key is already present
                //adj[keys[start]].push_back(end);//keys[start] should access the data associated with start, which is an index of adj that holds adjacent nodes
                // for(int i=0;i<link[start].size();i++)
                //     {
                //         if((link[start])[i]==end)
                //             {
                //                 endp=true;
                //             }
                //     }
                // if(endp=false)
                //     {
                    for(int i=0;i<link[start].size();i++)
                        {
                            if(link[start][i]==end)
                                {
                                    return false;
                                }
                        }
                        link[start].push_back(end);
                //     }
                // else
                //     {
                //         return false;
                //     }
            }

        if(!evalid)
            {
                temp2.push_back(start);
                //adj.push_back(temp2);
                //keys.insert({end,adj.size()-1});//where adj.size()-1 contains the index that was last inserted 
                link.insert({end,temp2});
            }
        else if(evalid)
            {
                //adj[keys[end]].push_back(start);//add end as a new adjacent
                link[end].push_back(start);
            }
        edges++;
        return true;//i dont see why this has a return value...
    }   

template <typename LabelType> 
bool AdjacencyListGraph<LabelType>::remove(LabelType start, LabelType end) 
    {   // remove an edge from this graph
        // if a vertex is left with no other edges, remove it from the graph since this is a connected graph
        bool in1,in2;
        int ind1,ind2;        
        if(link.count(start)==0||link.count(end==0))//if the vertex to be removed couldn't be found
            {
                return false;
            }
        else
            {
                if(std::count(link[start].begin(),link[start].end(),end)==0)
                    {
                        return false;
                    }
                for(int i=0;i<link[start].size();i++)
                    {
                        if((link[start])[i]==end)
                            {
                                bool ind1=true;
                                ind1=i;
                            }
                    }
                for(int i=0;i<link[end].size();i++)
                    {
                        if((link[end])[i]==start)
                            {
                                bool ind1=true;
                                ind2=i;
                            }
                    }
                //removes from respective edge vectors
                if(in1)
                    {
                        link[start].erase(link[start].begin()+ind1);
                    }
                if(in2)
                    {
                        link[end].erase(link[end].begin()+ind2);
                    }
                //
                if(link[start].size()==0)//if no edges, remove vertex
                    {
                        link.erase(start);
                    }
                if(link[end].size()==0)
                    {
                        link.erase(end);
                    }
            }
        edges--;
        return true;
    }

template <typename LabelType> 
void AdjacencyListGraph<LabelType>::depthFirstTraversal(LabelType start, void visit(LabelType&)) 
    {
        // visited[start]=true;//initially set start as visited
        // std::vector<int>::iterator i;
        // for(i=adj[start].begin();i!=adj[start].end();++i)
        //     {

        //         if(!visited[*i])
        //             {
        //                 visit(*i);
        //                 //depthFirstTraversal(*i,void visit());
        //             }
        //     }

    }

template <typename LabelType> 
void AdjacencyListGraph<LabelType>::breadthFirstTraversal(LabelType start, void visit(LabelType&)) 
    {

    }