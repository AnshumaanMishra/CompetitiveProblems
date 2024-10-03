#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int getMaxPower(int n, int k){
    int i = 0;
    while(pow(k, i) <= n){
        // cout << "POW " << pow(k, i) << " N " << n << endl; 
        if(pow(k, i) == n){
            return -1;
        }
        i++;
    }
    return i - 1;
}


int getMinimumOps(int n, int k){
    if(n < k || k == 1){
        return n;
    }
    int a = getMaxPower(n, k);
    if(a == -1 || a == 0){
        return 1;
    }
    // cout << a << endl;
    int pow1 = getMinimumOps(n - pow(k, a), k);
    // cout << pow1 << endl;
    return 1 + pow1;

}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n, k;
        cin >> n >> k;
        cout << getMinimumOps(n, k) << endl;
    }
}