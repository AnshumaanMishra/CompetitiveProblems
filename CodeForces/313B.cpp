#include <bits/stdc++.h>
// #include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int map[s.length()];
    map[0] = 0;
    for(int i = 0; i < s.length() - 1; i++){
        int prev = map[i];
        map[i + 1] = prev + (s[i] == s[i + 1]);
        // cout << map[i] << endl;
    }
    int t;
    cin >> t;
    while(t > 0){
        int l, r;
        cin >> l >> r;
        int sum = 0;
        // cout << map[l - 2] << " " << map[r - 2] << endl;
        sum = map[r - 1] - map[l - 1];
        cout << sum << endl;
        t--;
    }
}