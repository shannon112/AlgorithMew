#include "cycleBreaking.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <queue>
# define INF numeric_limits<int>::min() 
# define UNDEF numeric_limits<unsigned int>::max() 

using namespace std;

// print Edge element
ostream&
operator << (ostream& os, const Edge& j){
   os << j.first << " " << j.second;
   return os;
}

// print Node element
ostream&
operator << (ostream& os, const Node& j){
   os << j.first << " " << j.second;
   return os;
}

// print adjacent list for debug
void 
CbSolver::printGraph(){
    cout<<"i, j, weight"<<endl;
    for (size_t i = 0; i<_verticeNum; i++)
        for(auto it = _myGraph[i].begin(); it != _myGraph[i].end(); it++)
            cout << i << " "<< *it << endl;
    cout<<endl;
}

// print undirected edge w/o reportinig duplicate edge
void 
CbSolver::writeUdGraph(fstream& fout){
    //print 0 if there is no cycle, so no cycle breaking happean
    if (!_totalWeight){
        fout<<"0"<<endl;
        return;
    }
    //print sum of removed weight
    fout<<_totalWeight<<endl;
    for (size_t i = 0; i<_verticeNum; i++){
        for(auto it = _myGraph[i].begin(); it != _myGraph[i].end(); ++it){
            //print i,j edge
            fout << i << " "<< *it << endl;
            //remove j,i edge
            unsigned j = (*it).first;
            for (auto it_in = _myGraph[j].begin(); it_in != _myGraph[j].end(); ++it_in){
                if ((*it_in).first == i){
                    _myGraph[j].erase(it_in);
                    break;
                }
            }
        }
    }
}

// add edge to adjacent list
void
CbSolver::addEdge(const unsigned i, const unsigned j, const int weight){
    _myGraph[i].push_back(Edge(j,weight));
    _myGraph[j].push_back(Edge(i,weight));
    _totalWeight+=weight;
}

// remove edge from adjacent list
void
CbSolver::rmEdge(const unsigned i, const unsigned j){
    if ((i==UNDEF)||(j==UNDEF)) return;
    int weight = 0;
    for (auto it = _myGraph[i].begin(); it != _myGraph[i].end(); ++it)
        if ((*it).first == j){
            weight = (*it).second;
            _myGraph[i].erase(it);
            break;
        }
    for (auto it = _myGraph[j].begin(); it != _myGraph[j].end(); ++it)
        if ((*it).first == i){
            _myGraph[j].erase(it);
            break;
        }
    _totalWeight-=weight;
}

// modified Prim's MST
// original from https://www.geeksforgeeks.org/prims-algorithm-using-priority_queue-stl/
void
CbSolver::makeMaxSpanningTree(){
    // Max heap store key and node idx
    priority_queue< Node, vector<Node> , less<Node>> maxQ; 
    // Taking node 0 as source 
    unsigned src = 0; 
    // Create a vector for keys and initialize all keys as negative infinite
    int* key = new int[_verticeNum];
    for(size_t i=0;i<_verticeNum;++i) key[i] = INF;
    // To store parent array which in turn store MST 
    unsigned* parent = new unsigned[_verticeNum];
    for(size_t i=0;i<_verticeNum;++i) parent[i] = UNDEF;
    // To keep track of nodes included in MST 
    bool* tracked = new bool[_verticeNum];
    for(size_t i=0;i<_verticeNum;++i) tracked[i] = false;
    // Insert source itself in priority queue and initialize its key as 0. 
    maxQ.push(make_pair(0, src)); 
    key[src] = 0; 

    // Looping till priority queue becomes empty
    while (!maxQ.empty()) { 
        // pick the node that has the max key value, and mark it as tracked
        unsigned u = maxQ.top().second; 
        maxQ.pop();
        // every node only step onece, but we push duplicated node in maxQ.
        if (!tracked[u]){
            tracked[u] = true;
            rmEdge(parent[u], u);

            // update adjacent nodes' key value, and its parant
            for (auto it = _myGraph[u].begin(); it != _myGraph[u].end(); ++it) { 
                unsigned v = (*it).first; 
                int weight = (*it).second; 
                if (!tracked[v] && key[v] < weight) { 
                    key[v] = weight; 
                    maxQ.push(make_pair(key[v], v)); 
                    parent[v] = u; 
                }
            } 
        }
    }
  
    // Print edges of MST using parent array 
    for (int i = 1; i < _verticeNum; ++i) 
        printf("%d - %d\n", parent[i], i); 

    delete key;
    delete parent;
    delete tracked;
}
