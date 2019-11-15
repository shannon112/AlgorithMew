#include <iostream>
#include "maxPlanarSubset.h"
#include <cstring>
#include <fstream>

using namespace std;

int vertice_num;
int line_num;
int **MPSpyramid;
int **MPSchoice;
bool **lineMap;
//none:-1, full-self:-2, succDown-not-self:-3, succDown-and-self:-4, others: k 
LineMap in_lineMap; 
LineMap out_lineMap; 

void help_message() {
    cout << "usage: mps <input_file_name> <output_file_name>" << endl;
}

int main(int argc, char* argv[])
{
    if(argc != 3) {
       help_message();
       return 0;
    }

    //////////// read the input file /////////////
    fstream fin;
    fstream fout;
    fin.open(argv[1],ios::in); //read
    if (!fin) return 1;
    fout.open(argv[2],ios::out); //write
    if (!fout) return 1;

    fin>>vertice_num;
    line_num = vertice_num/2;

    MPSpyramid = new int *[vertice_num];
    MPSchoice = new int *[vertice_num];
    lineMap = new bool *[vertice_num];
    for(int i = 0; i <vertice_num; i++){
        MPSpyramid[i] = new int[vertice_num];
        for (int j=0; j<vertice_num; ++j) MPSpyramid[i][j]=-1;
        MPSchoice[i] = new int[vertice_num];
        for (int j=0; j<vertice_num; ++j) MPSchoice[i][j]=-1;
        lineMap[i] = new bool[vertice_num];
        for (int j=0; j<vertice_num; ++j) lineMap[i][j]=false;
    }

    int i,j;
    while (fin >> i >> j){
        if (i>j) {
            in_lineMap.insert(LinePair(j, i));
            lineMap[j][i] = true;
        }
        else {
            in_lineMap.insert(LinePair(i, j));
            lineMap[i][j] = true;
        }
    }

    //////////// the MPS part ////////////////
    int MPSans = maxPlanarSubset(0, vertice_num-1);
    fout << MPSans <<endl;
    getPlanarSubset(0, vertice_num-1);
    for(LineMap::iterator iter = out_lineMap.begin(); iter != out_lineMap.end(); ++iter){
        fout << iter->first << " " << iter->second << endl;
    }

    fin.close();
    fout.close();
    return 0;
}

