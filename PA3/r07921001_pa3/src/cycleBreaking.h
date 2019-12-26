#ifndef CYCLEBREAKING_H
#define CYCLEBREAKING_H

#include <fstream>
#include <vector>
using namespace std;

typedef pair<int, unsigned> Node; // (key, vertice_idx)
typedef pair<unsigned, int>  Edge; // (j, weight)
typedef vector<Edge> AdjacentList; // [i](j, weight)

struct IJWEdge {
    unsigned i;
    unsigned j;
    int weight;
}; 

class CbSolver
{
public:
    CbSolver(unsigned v, unsigned e, bool d):_verticeNum(v),_edgeNum(e),_directed(d){
        _myGraph = new AdjacentList[_verticeNum];
    }
    ~CbSolver(){
        delete _myGraph;
    }
   const unsigned& edgeNum() const { return _edgeNum; }
   unsigned& edgeNum() { return _edgeNum; }
   const unsigned& verticeNum() const { return _verticeNum; }
   unsigned& verticeNum() { return _verticeNum; }

   void addEdge(const unsigned, const unsigned, const int);
   void rmEdge(const unsigned, const unsigned);

   void makeMaxSpanningTree();

   bool detectCycle();
   bool isCyclicUtil(unsigned,bool[],bool*);
   
   void printGraph();
   void writeReGraph(fstream&);
   void writeRmEdges(fstream&);
   friend ostream& operator << (ostream&, const IJWEdge&);
   friend ostream& operator << (ostream&, const Edge&);
   friend ostream& operator << (ostream&, const Node&);

private:
    int _totalWeight = 0;
    unsigned _verticeNum;
    unsigned _edgeNum;
    bool _directed;
    AdjacentList* _myGraph;

    //directed graph only
    bool stopflag = false;
    unsigned crossedPoint;
    IJWEdge minEdge;
    vector<IJWEdge> rmedEdge;
};


#endif