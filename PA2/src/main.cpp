#include <iostream>
#include <fstream>
#include "maxPlanarSubset.h"

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

    MpsSolver *mpss = new MpsSolver();

    //////////// read the input file /////////////
    fstream fin;
    fstream fout;
    fin.open(argv[1],ios::in); //read
    if (!fin) return 1;
    fout.open(argv[2],ios::out); //write
    if (!fout) return 1;

    //get size
    int vertices;
    fin>>vertices;
    mpss->setVerticeNum(vertices);

    //get blank arrays
    mpss->buildArray();

    //fill in value to array
    mpss->fillArray(fin);
    fin.close();

    //////////// the MPS value ////////////////
    int MPSans = mpss->maxPlanarSubset(0, vertices-1);
    fout << MPSans <<endl;

    //////////// the MPS path ////////////////
    mpss->getPlanarSubset(0, vertices-1);
    mpss->printLines(fout);
    fout.close();

    delete mpss;
    return 0;
}