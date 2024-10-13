#include <bits/stdc++.h>
// #include <algorithm>
using namespace std;

int main(){
    int length;
    cin >> length;
    vector<int> array(length, 0);
    for(int i = 0; i < length; i++){
        cin >> array[i];
    }
    sort(array.begin(), array.end());

    int t;
    cin >> t;
    int query;
    while(t > 0){
        cin >> query;
        int startIndex = 0, endIndex = length - 1;
        cout << (int)(upper_bound(array.begin(), array.end(), query) - array.begin()) << endl;
        // cout << (upperBound(array, startIndex, endIndex, query, length) + 1) << endl;
        t--;
    }
    // int array[] = {3, 6, 8, 10, 11};
    // cout << (upperBound(array, 0, 4, 1, 5)) << endl;
}