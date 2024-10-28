#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t > 0){
        lli n, m, r, c;
        cin >> n >> m >> r >> c;
        lli sum = (m)*(n-r) + (m - c) + (m - 1) * (n - r);
        cout << sum << endl;
        t--;
    }
    return 0;
}