#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<pair<int, int>> laptops(t, pair(0, 0));
    int i = 0;
    while(i < t){
        int price, performance;
        cin >> price >> performance;
        laptops[i] = pair(price, performance);
        i++;
    }
    bool found = 0;
    for(int i = 0; i < t; i++){
        pair<int, int> outerPair = laptops[i];
        for(int j = i; j < t; j++){
            pair<int, int> innerPair = laptops[j];
            if(((outerPair.first > innerPair.first) && (outerPair.second < outerPair.first)) || ((outerPair.first < innerPair.first) && (outerPair.second > outerPair.first))){
                found = 1;
                break;
            }
        }
        if(found){
            break;
        }
    }
    if(found){
        cout << "Happy Alex" << endl;
    }
    else{
        cout << "Poor Alex" << endl;
    }
}