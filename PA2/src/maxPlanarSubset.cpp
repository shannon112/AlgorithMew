#include "maxPlanarSubset.h"
#include <cassert>

using namespace std;

extern int **MPSpyramid;
extern int **MPSchoice;
extern int *linearLineMap;
extern LineMap out_lineMap;

//search if i,j is a chord
int searchLine(const int& i, const int& j){
    int i_paired = linearLineMap[i];
    if (i_paired==j) return 1;
    return 0;
}

//M(i, j): number of chords in the maximum planar subset (shaded region)
int maxPlanarSubset(int i, int j){
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
void getPlanarSubset(int i, int j){
    int k = MPSchoice[i][j];
    if (i>j){
        return; //may happen at getPlanarSubset(i+1,k-1);
    }
    else if (k==-2) {
        out_lineMap.insert(LinePair(i, j));
    }
    else if (k==-4){
        out_lineMap.insert(LinePair(i, j));
        getPlanarSubset(i+1,j-1);
    }
    else if (k==-3){
        getPlanarSubset(i+1,j);
    }
    else if (k>=0){
        out_lineMap.insert(LinePair(i, k));
        getPlanarSubset(i+1,k-1);
        getPlanarSubset(k+1,j);
    }
    else{/*k==-1*/}

    return;
}