#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    bool better = b / m < a;
    int money = 0;
    if(better){
        money = (n / m) * b;
        // cout << money << " " << (n / m) * b << endl;
        n = n % m;
        money += ((n * a) < b) ? (n * a) : (b);
        // cout << money << " " << (n * a) << " " << b << endl;
    }
    else{
        money = n * a;
    }

    cout << money << endl;
    return 0;
}