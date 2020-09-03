#ifndef __ASYMMETRIC__
#define __ASYMMETRIC

#include <fstream>
#include <vector>

using namespace std;

int checkDimensions(ifstream& inputfile);
vector<vector<int>> readAsymFile(ifstream& inputfile);
void calcAsymTSP(vector<vector<int>> adjMatrix);
int findClosestNotVisited(int curCity, vector<vector<int>> adjMatrix, int* visited);

#endif