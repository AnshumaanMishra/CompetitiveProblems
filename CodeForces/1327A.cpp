#include <bits/stdc++.h>
using namespace std;

bool canBeRepresented(int n, int k, int subVal){
    if((n % 2 == 0) && (k % 2 != 0)){
        return false;
    }
    if((n % 2 != 0) && (k % 2 == 0)){
        return false;
    }
    if(n < 0 && k > 0){
        return false;
    }
    else{
        // cout << n << " " << subVal << " " << k << endl;
        if(k == 1){
            return true;
        }
        if(((n - subVal == 0) && (k == 1)) || ((k == 2) && ((n - subVal) % 2 == 1)) ){
            return true;
        }
        return canBeRepresented(n - subVal, k - 1, subVal + 2);
    }
}

int main(){
    int t;
    cin >> t;
    while(t > 0){
        int n, k;
        cin >> n >> k;
        int answer = canBeRepresented(n, k, 1);
        if(answer){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        t--;
    }
    return 0;
}