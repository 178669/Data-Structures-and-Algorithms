#include "adjacency_matrix_graph.hpp"

template <typename LabelType>
AdjacencyMatrixGraph<LabelType>::AdjacencyMatrixGraph() 
    {

    }

template <typename LabelType> 
int AdjacencyMatrixGraph<LabelType>::getNumVertices() const 
    {
        //return keyindex.size();
        //return verts-removed;
        int count=0;
        for(int i=0;i<vertvec.size();i++)
            {
                if(vertvec[i]==0)
                    {
                        count++;
                    }
            }
        return verts-count;
    }

template <typename LabelType> 
int AdjacencyMatrixGraph<LabelType>::getNumEdges() const 
    {
        // int edges;
        // for(int i=0;i<matrix.size();i++)
        //     {
        //         for(int j=0;j<matrix.size();j++)
        //             {
        //                 if(matrix[i][j]==true)
        //                     {
        //                         edges++;
        //                     }
        //             }
        //     }
        return edges;
    }
        
template <typename LabelType> 
bool AdjacencyMatrixGraph<LabelType>::add(LabelType start, LabelType end) 
    {
        // bool in1,in2;
        //     //repeat preventing
        // for(int i=0;i<keyindex.size();i++)
        //     {
        //         if(keyindex[i]==start)
        //             {
        //                 in1=true;
        //             }
        //         if(keyindex[i]==end)
        //             {
        //                 in2=true;
        //             }
        //     }
        // if(in1!=true&&in2!=true)
        //     {
        //         // keyindex.push_back(start);
        //         // keyindex.push_back(end);
        //         // std::vector<bool> temp(keyindex.size(),0);
        //         // matrix.push_back(temp);
        //         // matrix.push_back(temp);
        //         adjmat[keyindex.size()][adjmatrix[keyindex.size]]=true;
        //         adjmat[adjmatrix[keyindex.size]][keyindex.size()]=true;

        //     }
        // else
        //     {
        //         if(in1!=true)
        //             {
        //                 keyindex.push_back(start);
        //                 std::vector<bool> temp(keyindex.size(),0);
        //                 matrix.push_back(temp);
        //             }
        //         if(in2!=true)
        //             {
        //                 keyindex.push_back(end);
        //                 std::vector<bool> temp1(keyindex.size(),0);
        //                 matrix.push_back(temp1);
        //             }
        //     }
        
        //resize entire matrix
        // for(int i=0;i<matrix.size();i++)
        //     {
        //         if(matrix[i].size()<matrix[keyindex.size()].size())
        //             {
        //                 for(int j=matrix[i].size();j<matrix[keyindex.size()].size();j++);
        //                     {
        //                         matrix[i].push_back(false);
        //                     }
        //             }
        //     }
        
        // it=std::find(keyindex.begin(),keyindex.end(),start);
        // x=std::distance(keyindex.begin(),it);
        // it=std::find(keyindex.begin(),keyindex.end(),end);
        // y=std::distance(keyindex.begin(),it);
        // //if(matrix[x][y]!=true)
        // for(int i=0;i<matrix.size();i++)
        //     {
        //         for(int j=0;j<matrix.size();j++)
        //         if(i==x&&j==y)
        //             {
        //                 if(matrix[i][j]!=true)
        //                     {
        //                         //edges++;
        //                         matrix[x][y]==true;
        //                         edges++;
        //                         return true;
        //                     }
        //             }
        //     }

        //restarting bc I just can't debug my errors
        bool in1,in2;
        int startind, endind;
        //implementing connectivity
            //repeat preventing
        
        for(int i=0;i<keyindex.size();i++)
            {
                if(keyindex[i]==start)
                    {
                        in1=true;
                        startind=i;
                        // if(vertvec[startind]==0)
                        //     {
                        //         return false;//trying to create unconnected link
                        //     }
                        vertvec[startind]++;
                    }
                if(keyindex[i]==end)
                    {
                        in2=true;
                        endind=i;
                        vertvec[endind]++;
                    }
            }  
        //Make sure both vertices are accounted for
        if(!in1)
            {
                if(keyindex.size()>0)
                    {
                        return false;//if the start isn't present, then it can't be connected 
                    }
                vertvec.push_back(0);
                keyindex.push_back(start);
                vertvec[keyindex.size()-1]++;
                startind=keyindex.size()-1;
                verts++;
            }   
        if(!in2)
            {
                vertvec.push_back(0);
                keyindex.push_back(end);
                vertvec[keyindex.size()-1]++;
                endind=keyindex.size()-1;
                verts++;
            }
        //
        matrix.resize(keyindex.size(),std::vector<bool>(keyindex.size(),0));//resizing
        if(in1&&in2)
            {
                if(matrix[startind][endind]==true&&matrix[endind][startind]==true)//returns false if already present in matrix
                    {
                        return false;
                    }
            }
        matrix[startind][endind]=1;
        matrix[endind][startind]=1;
        edges++;

        return true;
    }   

template <typename LabelType> 
bool AdjacencyMatrixGraph<LabelType>::remove(LabelType start, LabelType end) 
    {
        bool in1=false,in2=false;
        int startind,endind;
            //repeat preventing
        for(int i=0;i<keyindex.size();i++)
            {
                if(keyindex[i]==start)
                    {
                        in1=true;
                        startind=i;
                        vertvec[startind]--;
                    }
                if(keyindex[i]==end)
                    {
                        in2=true;
                        endind=i;
                        vertvec[endind]--;
                    }
            }
        if(in1&&in2)
            {
                if(matrix[startind][endind]==0||matrix[endind][startind]==0)
                    {
                        return false;
                    }
                matrix[startind][endind]=0;
                matrix[endind][startind]=0;
                edges--; 
                // it=std::find(keyindex.begin(),keyindex.end(),start);
                // x=std::distance(keyindex.begin(),it);
                // it=std::find(keyindex.begin(),keyindex.end(),end);
                // y=std::distance(keyindex.begin(),it);
                // for(int i=0;i<matrix.size();i++)
                //     {
                //         for(int j=0;j<matrix.size();j++)
                //         if(i==x&&j==y)
                //             {
                //                 if(matrix[i][j]!=true)
                //                     {
                //                         //edges--;
                //                         matrix[x][y]==false;
                //                         edges--;
                //                         return true;
                //                     }
                //             }
                //     }
                
            }
        // bool rem=false;
        // for(int i=0;i<matrix.size();i++)
        //     {
        //         int num=0;
        //         for(int j=0;j<matrix.size();j++)
        //             {
        //                 num+=matrix[i][j];
        //             }
        //         if(num==0)
        //             {
        //                 for(int g=0;g<removedindices.size();g++)
        //                     {
        //                         if(removedindices[g]==i)
        //                             {
        //                                 rem=true;
        //                             }
        //                     }
        //                 if(rem==false)
        //                     {
        //                         verts--;
        //                         removedindices.push_back(i);
        //                     }

        //             }
        //     }
        if(!(in1&&in2))
            {
                return false;
            }
        return true;
    }

template <typename LabelType> 
void AdjacencyMatrixGraph<LabelType>::depthFirstTraversal(LabelType start, void visit(LabelType&)) 
    {

    }

template <typename LabelType> 
void AdjacencyMatrixGraph<LabelType>::breadthFirstTraversal(LabelType start, void visit(LabelType&)) 
    {

    }