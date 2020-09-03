#ifndef __SYMMETRIC__
#define __SYMMETRIC__

#include <math.h>
#include <vector>
#include <fstream>
#include <string>
#include <climits>
#include <iostream>

using namespace std;


struct city{
    int num;
    float x_coord;
    float y_coord;
    bool visited;
};

float calcDist(city c1, city c2);

vector<city> readSymFile(ifstream& inputfile);

void stringSplit(string line, vector<string> *wordArray);

int firstCharIDX(string s);

int getClosestSym(vector<city> cities, int curIdx);

void calcSymTSP(vector<city> cities);

bool areAllVisited(vector<city> cities);

#endif