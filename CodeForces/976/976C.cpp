#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    // printf("%d %d\n", (4 | 10), (4 & 2));
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        ll b, c, d;
        cin >> b >> c >> d;
        ll max;
        if(d >= b && d >= c){
            max = d;
        }
        else if(b >= c && b >= d){
            max = b;
        }
        else{
            max = c;
        }
        ll j;
        for(j = 0; j < max + 1; j++){
            // printf("%d %d %d\n", j, (j | b) - (j & c), d);
            if((j | b) - (j & c) == d){
                cout << j << endl;
                break;
            }
        }
        if(j > max)
            cout << "-1" << endl; 
    }
}