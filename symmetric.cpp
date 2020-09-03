#include "symmetric.hpp"


float calcDist(city c1, city c2){
    return sqrt(pow((c2.x_coord - c1.x_coord), 2) + pow((c2.y_coord - c1.y_coord), 2));
}

int firstCharIDX(string s){
    for(int i = 0; i < s.length(); i++){
        if(s[i] != ' '){
            return i;
        }
    }
    return -1;
}

vector<city> readSymFile(ifstream& inputfile){
    string line;
    vector<city> cities;
    city curCity;
    while (getline(inputfile, line)){
        int idx = firstCharIDX(line);
        if (isdigit(line[idx]) && idx != -1){
            vector<string> wordArray(3);
            stringSplit(line, &wordArray);
            curCity.num = atoi(wordArray[0].c_str());
            curCity.x_coord = atof(wordArray[1].c_str());
            curCity.y_coord = atof(wordArray[2].c_str());
            curCity.visited = false;
            cities.push_back(curCity);
        }
    }
    return cities;
}

void stringSplit(string line, vector<string> *wordArray){
    int counter = 0;
    bool foundWord = false;
    for(int i=0;i<line.length();i++){
        if(line[i] == ' ' && foundWord == true){
            foundWord = false;
            counter++;
        }
        else{
            foundWord = true;
            (*wordArray)[counter] += line[i];
        }
    }
}


bool areAllVisited(vector<city> cities){
    for(int i = 0; i < cities.size(); i++){
        if(!cities[i].visited){
            return false;
        }
    }
    return true;
}

int getClosestSym(vector<city> cities, int curIdx){
    float dist;
    int idx;
    float minDist = INT_MAX;
    for(int i = 0; i < cities.size(); i++){
        if(i != curIdx && !cities[i].visited){
            dist = calcDist(cities[curIdx], cities[i]);
            if(dist < minDist){
                minDist = dist;
                idx = i;
            }
        }
    }
    return idx;
}

void calcSymTSP(vector<city> cities){
    int curIdx = 0;
    int closestCityIdx = -5;
    float totalDistance = 0;
    while(!areAllVisited(cities)){
        cities[curIdx].visited = true;
        cout << curIdx + 1 << endl;
        closestCityIdx = getClosestSym(cities, curIdx);
        totalDistance += calcDist(cities[curIdx], cities[closestCityIdx]);
        cities[closestCityIdx].visited = true;
        curIdx = closestCityIdx;
    }
    totalDistance += calcDist(cities[curIdx], cities[0]);
    cout << 1 << endl;
    cout << "Total Distance: " << totalDistance << endl;
}