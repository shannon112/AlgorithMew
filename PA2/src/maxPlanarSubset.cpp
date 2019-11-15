#include "maxPlanarSubset.h"
#include <cassert>
#include <fstream>

using namespace std;


void MpsSolver::printLines(fstream& fout){
    for(LineMap::iterator iter = outLineMap.begin(); iter != outLineMap.end(); ++iter)
        fout << iter->first << " " << iter->second << endl;
}

void MpsSolver::fillArray(fstream& fin){
    int i,j;
    while (fin >> i >> j){
        linearLineMap[i] = j;
        linearLineMap[j] = i;
    }
}

void MpsSolver::buildArray(){
    MPSpyramid = new int *[verticeNum];
    MPSchoice = new int *[verticeNum];
    linearLineMap = new int [verticeNum];
    for(int i = 0; i <verticeNum; i++){
        MPSpyramid[i] = new int[verticeNum];
        for (int j=0; j<verticeNum; ++j) MPSpyramid[i][j]=-1;
        MPSchoice[i] = new int[verticeNum];
        for (int j=0; j<verticeNum; ++j) MPSchoice[i][j]=-1;
    }
}

void MpsSolver::setVerticeNum(int vertices){
    verticeNum = vertices;
    lineNum = vertices/2;
}

//search if i,j is a chord
int MpsSolver::searchLine(const int& i, const int& j){
    int i_paired = linearLineMap[i];
    if (i_paired==j) return 1;
    return 0;
}

//M(i, j): number of chords in the maximum planar subset (shaded region)
int MpsSolver::maxPlanarSubset(int i, int j){
    int k = linearLineMap[i];
    assert(k!=i);

    //if it has already fill in or it is a basic case
    if (MPSpyramid[i][j]!=-1){
        return MPSpyramid[i][j];
    }
    else if (i>j) { //may happen at maxPlanarSubset(i+1,k-1)
        return 0; 
    }
    else if (i==j) {
        MPSpyramid[i][j] = 0;
        MPSchoice[i][j] = -1;
    }
    else if (j==i+1) {
        MPSpyramid[i][j] = searchLine(i,j);
        MPSchoice[i][j] = (MPSpyramid[i][j]) ? -2 : -1 ;
    }

    //divide to subproblem, recursively solve
    else{
        if (k==j){
            MPSpyramid[i][j] = 1 + maxPlanarSubset(i+1,j-1);
            MPSchoice[i][j] = -4;
        }
        else if (k>j || k<i){
            MPSpyramid[i][j] = maxPlanarSubset(i+1,j);
            MPSchoice[i][j] = -3;
        }
        else{//k between i and j
            int takeit = 1+maxPlanarSubset(i+1,k-1)+maxPlanarSubset(k+1,j);
            int nottake = 0+maxPlanarSubset(i+1,j);
            if (takeit>nottake){
                MPSpyramid[i][j] = takeit;
                MPSchoice[i][j] = k;
            }
            else{
                MPSpyramid[i][j] = nottake;
                MPSchoice[i][j] = -3;
            }
        }
    }
    return MPSpyramid[i][j];
}

//trace back to find pairs
//none:-1, full-self:-2, i+1&jsubproblem:-3, succDown-and-self:-4, others: k
void MpsSolver::getPlanarSubset(int i, int j){
    int k = MPSchoice[i][j];
    if (i>j){
        return; //may happen at getPlanarSubset(i+1,k-1);
    }
    else if (k==-2) {
        outLineMap.insert(LinePair(i, j));
    }
    else if (k==-4){
        outLineMap.insert(LinePair(i, j));
        getPlanarSubset(i+1,j-1);
    }
    else if (k==-3){
        getPlanarSubset(i+1,j);
    }
    else if (k>=0){
        outLineMap.insert(LinePair(i, k));
        getPlanarSubset(i+1,k-1);
        getPlanarSubset(k+1,j);
    }
    else{/*k==-1*/}

    return;
}