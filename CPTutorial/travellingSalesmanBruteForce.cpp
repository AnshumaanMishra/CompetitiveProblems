#include <bits/stdc++.h>
using namespace std;

// Hamiltonian Cycle

//Brute Force
int getSum(vector<int>& vec1){
    int sum = 0;
    for(int i = 0; i < vec1.size(); i++){
        sum += vec1[i];
    }
    return sum;
}

int getMinPath(vector<int> pathMap){
    int min = 1000000000;
    for(auto x: pathMap){
        if(x < min){
            min = x;
        }
    }
    return min;
}

void printMap(vector<int> map){
    for(int i = 0; i < map.size(); i++){
        printf("%d, ", map[i]);
    }
    printf("\n");
}


int getShortestRoute(vector<vector <int>> paths, int start,  vector<int>* TraversedMap){
    vector<int> pathLength; // Local Vector to store lengths of differnet paths

    // Exit condition: All Traversed
    if(getSum(*TraversedMap) == 4){
        // printf("Exit Condition Satisfied, Start: %d\n", start);
        // printMap(*TraversedMap);
        return 0;
    }

    (*TraversedMap)[start] = 1; // Set current Node to traversed
    // printf("Start: %d\n", start);
    // printMap(*TraversedMap);
    vector<int> tempMap = *TraversedMap;
    for(int i = 0; i < 4; i++){
        // printf("i: %d, Start: %d Paths:%d \n", i, start, paths[start][i]);
        // printMap(*TraversedMap);        
        if(!((*TraversedMap)[i])){
            // printf("ShortestRoute: %d \n", getShortestRoute(paths, i, TraversedMap));
            // Append to path_lengths currentDistance+shortest distance of following path
            pathLength.push_back(paths[start][i] + getShortestRoute(paths, i, TraversedMap));
        }
        *TraversedMap = tempMap;
    }
    // printMap(pathLength);
    if(getSum(*TraversedMap) == 4){
        pathLength.push_back(paths[start][0] + getShortestRoute(paths, 0, TraversedMap));
    }
    return getMinPath(pathLength);

}


int main(){

    // Variable Creation
    vector<int> TraversedMap(4, 0);
    vector<vector<int>> paths;
    paths.push_back(vector<int> {0, 20, 42, 25});
    paths.push_back(vector<int> {20, 0, 30, 34});
    paths.push_back(vector<int> {42, 30, 0, 10});
    paths.push_back(vector<int> {25, 34, 10, 0}); 

    // printMap(paths[1]);

    printf("%d\n", getShortestRoute(paths, 0, &TraversedMap));

}