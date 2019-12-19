#ifndef CYCLEBREAKING_H
#define CYCLEBREAKING_H

#include <map>
#include <vector>
using namespace std;

typedef pair<unsigned, int>  Edge;
typedef vector<Edge> Graph;

class CbSolver
{
public:
    CbSolver(unsigned v, unsigned e, bool d):_verticeNum(v),_edgeNum(e),_directed(d){
        _myGraph = new Graph[_verticeNum];
    }
    ~CbSolver(){
        delete _myGraph;
    }
   const unsigned& edgeNum() const { return _edgeNum; }
   unsigned& edgeNum() { return _edgeNum; }
   const unsigned& verticeNum() const { return _verticeNum; }
   unsigned& verticeNum() { return _verticeNum; }
   void addEdge(unsigned i, unsigned j, int w) { _myGraph[i].push_back(Edge(j,w)); }
   void printGraph();

   friend ostream& operator << (ostream&, const Edge&);

private:
    unsigned _verticeNum;
    unsigned _edgeNum;
    bool _directed;
    Graph* _myGraph;
};

#endif
