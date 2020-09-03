#include "asymmetric.hpp"
#include "symmetric.hpp"

int checkDimensions(ifstream& inputfile){
    int counter = 0;
    string line;
    vector<string> dimensionString(2);
    while(getline(inputfile, line)){
        if(line.find("DIMENSION") != string::npos){
            stringSplit(line, &dimensionString);
            return atoi(dimensionString[1].c_str());
        }
    }
    return -1;
}

int findClosestNotVisited(int curCity, vector<vector<int>> adjMatrix, int* visited){
    int min = INT_MAX;
    int minIdx = -1;
    int i = 0;
    for(i; i < adjMatrix.size(); i++){
        if(adjMatrix[curCity][i] < min && i != curCity && !visited[i]){
            min = adjMatrix[curCity][i];
            minIdx = i;
        }
    }
    return minIdx;
}

vector<vector<int>> readAsymFile(ifstream& inputfile){
    int dimensions = checkDimensions(inputfile);
    vector<vector<int>> adjMatrix;
    string word, line;
    streampos position;
    int counter = 0;
    while(getline(inputfile, line)){
        int idx = firstCharIDX(line);
        if(isdigit(line[idx]) && idx != -1){
            inputfile.seekg(position);
            break;
        }
        position = inputfile.tellg();
    }

    for(int i = 0; i < dimensions; i++){
        vector<int> newRow;
        adjMatrix.push_back(newRow);
        for(int j = 0; j < dimensions; j++){
            inputfile >> word;
            adjMatrix[i].push_back(atoi(word.c_str()));
        }
    }
    return adjMatrix;

}

void calcAsymTSP(vector<vector<int>> adjMatrix){
    int num_cities = adjMatrix.size();
    int visited[num_cities] = {0};
    int curCity = 0;
    visited[0] = 1;
    int totalDistance = 0;
    for(int i = 0; i < adjMatrix.size(); i++){
        cout << curCity + 1 << endl;
        int closest = findClosestNotVisited(curCity,adjMatrix,visited);
        if(closest == -1){
            break;
        }
        visited[closest] = 1;
        totalDistance += adjMatrix[curCity][closest];
        curCity = closest;
    }
    cout << "Total Distance: " << totalDistance << endl;
}