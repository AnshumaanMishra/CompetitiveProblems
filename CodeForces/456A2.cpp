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
    sort(laptops.begin(), laptops.end());
    bool found = false;
    // for(int i = 0; i < t; i++){
    //     // if
    // }
    return 0;
}