#include <iostream>
#include "maxPlanarSubset.h"
#include <cstring>
#include <fstream>

using namespace std;

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

    int vertice_num;
    fin>>vertice_num;
    int line_num = vertice_num/2;
    int i,j;
    LineMap lineMap; 
    while (fin >> i >> j)
        lineMap.insert(LinePair(i, j));

    //////////// the MPS part ////////////////
    int **MPSpyramid = new int *[line_num];
    int **MPSchoice = new int *[line_num];
    for(int i = 0; i <line_num; i++){
        MPSpyramid[i] = new int[line_num];
        for (int j=0; j<line_num; ++j) MPSpyramid[i][j]=0;
        MPSchoice[i] = new int[line_num];
        for (int j=0; j<line_num; ++j) MPSchoice[i][j]=0;
    }
    int MPSans = maxPlanarSubset(vertice_num, lineMap, MPSpyramid, MPSchoice);

    //////////// write the output file ///////////
    fout << MPSans <<endl;
    //for (int i = 0; i < pairs_num; i++)
    //    fout << "i " <<pairs[i][0] << " j " <<pairs[i][1] << endl;
    fin.close();
    fout.close();
    return 0;
}

