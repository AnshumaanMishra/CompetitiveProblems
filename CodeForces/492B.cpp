#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n, l, a;
    cin >> n >> l;
    vector<int> road(0, 0);
    for(int i = 0; i < n; i++){
        cin >> a;
        road.push_back(a);
    }
    cout << endl;
    sort(road.begin(), road.end());

    double prev = -1, maxDiff = 0;
    double lDiff = 0, rDiff = 0;
    for(int i = 0; i < n; i++){
        if(prev == -1){
            prev = road[i];
            lDiff = road[i];
            continue;
        }
        // printf("Prev: %0.10lf, road[i]: %0.10lf, Difference: %0.10lf\n", prev, road[i], road[i] - prev);
        if(maxDiff < road[i] - prev){
            maxDiff = road[i] - prev;
        }
        prev = road[i];
    }
    rDiff = l-prev;
    maxDiff = (double)maxDiff/2;
    // cout << lDiff << " " << rDiff << " " << maxDiff << endl;
    // printf("rDiff: %0.10lf, lDiff: %0.10lf, maxDiff: %0.10lf\n", rDiff, lDiff, maxDiff);

    if(rDiff > maxDiff){
        maxDiff = rDiff;
    }
    if(lDiff > maxDiff){
        maxDiff = lDiff;
    }

    printf("%0.10lf\n", maxDiff);

    return 0;
}