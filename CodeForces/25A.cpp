#include <bits/stdc++.h>
using namespace std;

int main(){
    int len;
    cin >> len;
    vector<int> numbers;
    int check = -1;
    int lastdiff = 0;
    int fnum, snum, tnum;
    cin >> fnum;
    cin >> snum;
    cin >> tnum;
    fnum %= 2;
    snum %= 2;
    tnum %= 2;
    if((fnum && tnum && snum) || (!fnum && !snum && !tnum)){
        check = (fnum && snum && tnum);
    }
    else if((fnum && snum && !tnum) || (!fnum && !snum && tnum)){
        cout << 3 << endl;
        return 0;
    }
    else if((fnum && tnum && !snum) || (!fnum && !tnum && snum)){
        cout << 2 << endl;
        return 0;
    }
    else if((snum && tnum && !fnum) || (!snum && !tnum && fnum)){
        cout << 1 << endl;
        return 0;
    }
    for(int i = 3; i < len; i++){
        int n;
        cin >> n;
        numbers.push_back(n);
        if(check == -1){
            check = n % 2;
        }
        if(check == !(n % 2)){
            cout << i + 1 << endl;
            return 0;
        }
    }
    return 0;
}