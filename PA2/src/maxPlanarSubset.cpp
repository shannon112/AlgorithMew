#include "maxPlanarSubset.h"
#include <cassert>
#include <iostream>
using namespace std;

extern int **MPSpyramid;
extern int **MPSchoice;
extern bool **lineMap;
extern LineMap in_lineMap;
extern LineMap out_lineMap;

//search if i,j is a chord
int searchLine(const int& i, const int& j){
    LineMap::const_iterator LineMapIter;
    LineMapIter = in_lineMap.find(i);
    if (LineMapIter != in_lineMap.end()){
        if(LineMapIter->second == j){
            return 1;
        }
    }
    return 0;
}

//M(i, j): number of chords in the maximum planar subset (shaded region)
int maxPlanarSubset(int i, int j){
    assert(j>=i);
    //cout<<"enter maxPlanarSubset"<<i<<" "<<j<<endl;
    if (MPSpyramid[i][j]!=-1)
        return MPSpyramid[i][j];

    else if (i==j) {
        MPSpyramid[i][j] = 0;
        MPSchoice[i][j] = -1;
    }
    else if (j==i+1) {
        //MPSpyramid[i][j] = searchLine(i,j);
        MPSpyramid[i][j] = int(lineMap[i][j]);
        MPSchoice[i][j] = (MPSpyramid[i][j]) ? -2 : -1 ;
    }
    else{
        int local_max;
        if(lineMap[i][j]){
            local_max = 1 + maxPlanarSubset(i+1,j-1);
            MPSchoice[i][j] = -4;
        }
        else{
            local_max = 0 + maxPlanarSubset(i+1,j-1);
            MPSchoice[i][j] = -3;
        }
        
        for (int k=i; k<j; k++){
            int temp = maxPlanarSubset(i,k) + maxPlanarSubset(k+1,j);
            //cout<<"temp="<<i<<k<<" "<<k+1<<j<<" "<<temp<<endl;
            if (temp>local_max){
                local_max = temp;
                MPSchoice[i][j] = k;
                //cout<<k<<endl;
            }
        }
        MPSpyramid[i][j] = local_max;
    }
    //cout<<"return"<<i<<" "<<j<<endl;
    return MPSpyramid[i][j];
}

//trace back to find pairs
void getPlanarSubset(int i, int j){
    int k = MPSchoice[i][j];
    //cout<<i<<","<<j<<" "<<k<<endl;
    if (k==-2) {
        //cout<<i<<" "<<j<<endl;
        out_lineMap.insert(LinePair(i, j));
    }
    else if (k==-4){
        //cout<<i<<" "<<j<<endl;
        out_lineMap.insert(LinePair(i, j));
        getPlanarSubset(i+1,j-1);
    }
    else if (k==-3) {
        getPlanarSubset(i+1,j-1);
    }
    else if (k>=0){
        getPlanarSubset(i,k);
        getPlanarSubset(k+1,j);
    }
    else{/*k==-1*/}

    return;
}