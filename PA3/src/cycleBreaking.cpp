#include "cycleBreaking.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <queue>
#include <stack>
# define INF numeric_limits<int>::min() 
# define UNDEF numeric_limits<unsigned int>::max() 
# define NIL -1 

using namespace std;

// print Edge element
ostream&
operator << (ostream& os, const Edge& j){
   os << j.first << " " << j.second;
   return os;
}

// print IJEdge element
ostream&
operator << (ostream& os, const IJWEdge& j){
   os << j.i << " " << j.j << " "<<j.weight;
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

// print remain undirected edge w/o reportinig duplicate edge
void 
CbSolver::writeReGraph(fstream& fout){
    //print 0 if there is no cycle, so no cycle breaking happean
    if (!_totalWeight){
        fout<<"0"<<endl;
        return;
    }
    //print sum of removed weight
    fout<<_totalWeight<<endl;
    for (size_t i = 0; i<_verticeNum; i++)
        for(auto it = _myGraph[i].begin(); it != _myGraph[i].end(); ++it)
            //print only i>j edge
            if (i>(*it).first) fout << i << " "<< *it << endl;
}

// print all removed directed edges
void 
CbSolver::writeRmEdges(fstream& fout){
    //print 0 if there is no cycle, so no cycle breaking happean
    if (!_totalWeight){
        fout<<"0"<<endl;
        return;
    }
    //print sum of removed weight
    fout<<_totalWeight<<endl;
    vector<IJWEdge>::iterator i; 
    for(i = rmedEdge.begin(); i != rmedEdge.end(); ++i)
        fout << *i << endl;
}

// add edge to adjacent list
void
CbSolver::addEdge(const unsigned i, const unsigned j, const int weight){
    _myGraph[i].push_back(Edge(j,weight));
    if(!_directed) {
        _myGraph[j].push_back(Edge(i,weight));
        _totalWeight+=weight;
    }
}

// remove edge from adjacent list, only i>j in undirected graph
void
CbSolver::rmEdge(const unsigned I, const unsigned J){
    unsigned i = I;
    unsigned j = J;
    int weight = 0;
    if ((i==UNDEF)||(j==UNDEF)) return;
    if (!_directed) { if (i<j) swap(i,j); }
    for (auto it = _myGraph[i].begin(); it != _myGraph[i].end(); ++it)
        if ((*it).first == j){
            weight = (*it).second;
            _myGraph[i].erase(it);
            break;
        }
    if (!_directed) _totalWeight-=weight;
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
    // To keep track of nodes included in MST 
    bool* tracked = new bool[_verticeNum];
    // To store parent array which in turn store MST 
    unsigned* parent = new unsigned[_verticeNum];
    for(size_t i=0;i<_verticeNum;++i){
        key[i] = INF;
        parent[i] = UNDEF;
        tracked[i] = false;
    }
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

            // update adjacent nodes' key value, and its next
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
    //for (int i = 1; i < _verticeNum; ++i) 
    //    printf("%d - %d\n", parent[i], i); 

    delete key;
    delete parent;
    delete tracked;
}

// modified DFS find cycle in directed graph
// original from https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
bool 
CbSolver::detectCycle(){
    // Mark all the vertices as not visited and not part of recursion stack 
    bool *visited = new bool[_verticeNum]; 
    bool *recStack = new bool[_verticeNum]; 
    for(unsigned i = 0; i < _verticeNum; i++) { 
        visited[i] = false; 
        recStack[i] = false; 
    } 
    // Call the recursive isCyclicUtil function to detect cycle in different DFS trees 
    for(unsigned i = 0; i < _verticeNum; i++) 
        if (isCyclicUtil(i, visited, recStack)) return true;
    return false; 
}

bool
CbSolver::isCyclicUtil(unsigned v, bool visited[], bool *recStack) 
{ 
    if(visited[v] == false) { 
        // Mark the current node as visited and part of recursion stack 
        visited[v] = true; 
        recStack[v] = true; 

        // Recur for all the vertices adjacent to this vertex 
        AdjacentList::iterator i; 
        for(i = _myGraph[v].begin(); i != _myGraph[v].end(); ++i) { 
            // recursively find cycle
            if ( !visited[(*i).first] && isCyclicUtil((*i).first, visited, recStack) ) {
                // traceback for seeking and updating min edge 
                if(!stopflag){
                    if ((*i).second<minEdge.weight) {
                        minEdge.weight = (*i).second;
                        minEdge.i = v;
                        minEdge.j = (*i).first;
                    }
                }
                // hit, find the cycle head
                if (v==crossedPoint) {
                    cout<<"find it "<<minEdge<<endl;
                    _totalWeight += minEdge.weight;
                    rmEdge(minEdge.i,minEdge.j);
                    rmedEdge.push_back(minEdge);
                    stopflag = true;
                }
                return true; 
            }
            // recursive code end, find the cycle tail
            else if (recStack[(*i).first]) {
                crossedPoint = (*i).first;
                minEdge = { v, (*i).first, (*i).second}; //initialize
                return true; 
            }
        } 
    } 
    recStack[v] = false;  // remove the vertex from recursion stack 
    return false; 
} 