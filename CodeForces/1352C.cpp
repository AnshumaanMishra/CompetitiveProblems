#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin  >> t;
    while(t > 0){
        long long int n, k;
        cin >> n >> k;
        int answer = (k * n) / (n - 1) - ((n * k) % (n - 1) == 0);
        cout << answer << endl; 
        t--;
    }
    return 0;
}