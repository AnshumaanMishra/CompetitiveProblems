#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> newVector(n, 0);
    for(int i = 0; i < n; i++){
        newVector[i] = n - i;
    }

    auto start_time = clock();
    sort(newVector.begin(), newVector.end());
    auto end_time = clock();

    cout << end_time - start_time << endl;
    return 0;
}