#ifndef MAXPLANARSUBSET_H
#define MAXPLANARSUBSET_H

#include <map>
using namespace std;

typedef map<int, int>   LineMap;
typedef pair<int, int>  LinePair;

class MpsSolver
{
public:
    MpsSolver(){}
    ~MpsSolver(){
        for(int i = 0; i <verticeNum; i++) delete MPSpyramid[i];
        delete MPSpyramid;
        for(int i = 0; i <verticeNum; i++) delete MPSchoice[i];
        delete MPSchoice;
        delete linearLineMap;
    }

    // solving, tracing, and printing
    int maxPlanarSubset( int, int);
    void getPlanarSubset( int, int);
    void printLines(fstream&);

    // set and get variable
    void setVerticeNum(int);
    int getVerticeNum() {return verticeNum;};
    int getLineNum() {return lineNum;};
    
    //initailizing table and filling it
    void buildArray();
    void fillArray(fstream&);

private:
    int searchLine(const int&, const int&);
    int verticeNum;
    int lineNum;
    int **MPSpyramid; //subproblem value storage
    int **MPSchoice; //subproblem choice record
    int *linearLineMap; //input pairs storage
    LineMap outLineMap; //output pairs storage
};

#endif
