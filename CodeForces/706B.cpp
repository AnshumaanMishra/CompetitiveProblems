#include <bits/stdc++.h>
using namespace std;

int main(){
    int length;
    cin >> length;
    vector<int> array(length, 0);
    int max = -1;
    for(int i = 0; i < length; i++){
        cin >> array[i];
        if(max < array[i]){
            max = array[i];
        }
    }
    sort(array.begin(), array.end());
    int n;
    vector<int> map(max + 1, length);
    int arrayPointer = length - 1;
    int insertPointer = max;
    while(insertPointer > 0){
        map[insertPointer] = arrayPointer + 1;
        if(array[arrayPointer] == insertPointer){
            arrayPointer--;
        }
        // else if()
        insertPointer--;
    }
    cin >> n;
    while(n > 0){
        int query;
        cin >> query;
        if(query >= max){
            cout << length << endl;    
            n--;
            continue;

        }
        cout << map[query] << endl;
        // cout << i << endl;
        n--;
    }
}