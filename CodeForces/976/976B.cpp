#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long double ld;
typedef long long int ll;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        ll k;
        cin >> k;
        ld floor1 = floor(sqrt(k));
        ld ceil1 = ceil(sqrt(k));
        if((floor1 * floor1 + ceil1 * ceil1) / 2 > k){
            ll answer = k + (ll)floor1;
            cout << (ll)answer << endl;
            continue;
        }
        ll answer = k + (ll)ceil1;
        cout << (ll)answer << endl;
    }
}