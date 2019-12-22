#include <iostream>
#include <fstream>
#include "cycleBreaking.h"

using namespace std;

void help_message() {
    cout << "usage: cb <input_file_name> <output_file_name>" << endl;
}

int main(int argc, char* argv[]){
    if(argc != 3) {
       help_message();
       return 0;
    }

    //initialize file i/o
    fstream fin;
    fstream fout;
    fin.open(argv[1],ios::in); //read
    if (!fin) return 1;
    fout.open(argv[2],ios::out); //write
    if (!fout) return 1;

    //get type
    char graphType;
    fin>>graphType;
    bool directed = (graphType=='d') ? 1 : 0;

    //get size
    unsigned verticeNum, edgeNum;
    fin>>verticeNum;
    fin>>edgeNum;

    //new a solver
    CbSolver *cbsr = new CbSolver(verticeNum,edgeNum,directed);

    //set edges
    unsigned i, j;
    int weight;
    while (fin>>i>>j>>weight)
        cbsr->addEdge(i,j,weight);
    fin.close();

    //solve by Prim's MST
    cbsr->makeMaxSpanningTree();

    //write the ans to file
    cbsr->writeUdGraph(fout);
    fout.close();

    return 0;
}