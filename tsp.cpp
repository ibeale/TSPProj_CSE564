#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <climits>
#include "symmetric.hpp"
#include "asymmetric.hpp"

using namespace std;

enum FileType { FAIL, TSP, ATSP };



void readFile(string filePath);
FileType checkTSPType(ifstream& inputfile);

int main(int argc, char* argv[]){
    if(argc != 2){
        cout << "Invalid Usage: tsp.exe 'filename.(a)tsp'" << endl;
    }
    string arg = argv[1];
    readFile(arg);
    
}


// returns the type of TSP file we are dealing with.
FileType checkTSPType(ifstream& inputfile){
    string line;
    int counter = 0;
    while (getline(inputfile, line) && counter < 25 ){
        if (line.find("ATSP") != string::npos){
            return ATSP;
        }
        else if (line.find("TSP") != string::npos){
            return TSP;
        }
        counter++;
    }
    return FAIL;
}

void readFile(string filePath){
    string line;
    ifstream inputfile;
    inputfile.open(filePath);
    if (inputfile.good()){
       FileType TSPType = checkTSPType(inputfile);
       switch (TSPType){
           case FAIL:
                cout << "Failed" << endl;
                break;
           case TSP:{
                vector<city> cities = readSymFile(inputfile);
                calcSymTSP(cities);
                break;
           }
           case ATSP:
                vector<vector<int>> adjMatrix = readAsymFile(inputfile);
                calcAsymTSP(adjMatrix);
                break;
       }
    }
        else{
        cout << "Invalid file path" << endl;
    }
}








