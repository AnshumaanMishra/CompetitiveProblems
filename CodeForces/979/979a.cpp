#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t > 0){
        int l;
        cin >> l;
        int max = 0;
        int min = 100000;
        int a;
        for(int i = 0; i < l; i++){
            cin >> a;
            if(a > max){
                max = a;
            }
            if(a < min){
                min = a;
            }
        }

        cout << (l - 1) * (max - min) << endl;
        t--;
    }
}   