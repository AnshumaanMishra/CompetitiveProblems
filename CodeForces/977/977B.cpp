#include <bits/stdc++.h>
using namespace std;

int* find(int arr[], int n, int x, int val, int* res){
    // int res[] = {-1, -1};
    for(int i = 0; i < n; i++){
        if(arr[i] == val){
            res[0] = i;
        }
        if(arr[i] + x == val){
            res[i] = i;
        }
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    while(t > 0){
        int n, x;
        cin >> n >> x;
        int array[n];
        for(int i = 0; i < n; i++){
            cin >> array[i];
        }
        int* res = new int[2];
        *res = -1;
        *(res+1) = -1;
        int i = 0;
        res = find(array, n, x, i, res);
        while((res[0] != -1) || (res[1] != -1)){
            i++;
            res = find(array, n, x, i, res);
        }
        cout << i << endl;
        t--;
    }
}