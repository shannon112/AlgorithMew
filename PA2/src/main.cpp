#include <iostream>
#include "maxPlanarSubset.h"
#include <fstream>

using namespace std;

int vertice_num;
int line_num;
int **MPSpyramid;
int **MPSchoice;
int *linearLineMap;
//none:-1, full-self:-2, i+1&jsubproblem:-3, succDown-and-self:-4, others: k 
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

    //get size
    fin>>vertice_num;
    line_num = vertice_num/2;

    //get arrays
    MPSpyramid = new int *[vertice_num];
    MPSchoice = new int *[vertice_num];
    linearLineMap = new int [vertice_num];
    for(int i = 0; i <vertice_num; i++){
        MPSpyramid[i] = new int[vertice_num];
        for (int j=0; j<vertice_num; ++j) MPSpyramid[i][j]=-1;
        MPSchoice[i] = new int[vertice_num];
        for (int j=0; j<vertice_num; ++j) MPSchoice[i][j]=-1;
    }

    //fill in value to array
    int i,j;
    while (fin >> i >> j){
        linearLineMap[i] = j;
        linearLineMap[j] = i;
    }
    fin.close();

    //////////// the MPS value ////////////////
    int MPSans = maxPlanarSubset(0, vertice_num-1);
    fout << MPSans <<endl;
    for(int i = 0; i <vertice_num; i++) delete MPSpyramid[i];
    delete MPSpyramid;

    //////////// the MPS path ////////////////
    getPlanarSubset(0, vertice_num-1);
    for(LineMap::iterator iter = out_lineMap.begin(); iter != out_lineMap.end(); ++iter)
        fout << iter->first << " " << iter->second << endl;
    for(int i = 0; i <vertice_num; i++) delete MPSchoice[i];
    delete MPSchoice;
    delete linearLineMap;
    fout.close();
    
    return 0;
}