#include "cycleBreaking.h"
#include <cassert>
#include <fstream>
#include <iostream>

using namespace std;

// print Edge element
ostream&
operator << (ostream& os, const Edge& j)
{
   os << j.first << " " << j.second;
   return os;
}

void 
CbSolver::printGraph(){
    for (size_t i = 0; i<_verticeNum; i++){
        for(auto it = _myGraph[i].begin(); it != _myGraph[i].end(); it++) {
            cout << i << " "<< *it << endl;
        }
    }
}