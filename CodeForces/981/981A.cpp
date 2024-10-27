#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t > 0){
        int n;
        cin >> n;
        if(n % 2 == 0){
            cout << "Sakurako" << endl;
        }
        else{
            cout << "Kousuke" << endl;
        }
        t--;
    }
    return 0;
}