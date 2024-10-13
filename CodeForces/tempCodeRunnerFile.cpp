#include <bits/stdc++.h>
using namespace std;

bool canBeRepresented(int n, int k, int subVal){
    if((n % 2 == 0) && (k % 2 != 0)){
        return false;
    }
    if((n % 2 != 0) && (k % 2 == 0)){
        return false;
    }
    else{
        if((n - subVal == 0) || ((k == 2) && ((n - subVal) % 2 == 1))){
            return true;
        }
        return canBeRepresented(n - subVal, k - 1, subVal - 2);
    }
}

int main(){
    cout << canBeRepresented(10, 2, 1) << endl;
    return 0;
}