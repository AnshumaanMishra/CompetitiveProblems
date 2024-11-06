#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    vector<string> usernames;
    int i = 0;
    while(t--){
        string name;
        cin >> name;
        int count = 0;
        for(int i = 0; i < usernames.size(); i++){
            if(usernames[i] == name){
                count++;
            }
        }
    }
    return 0;
}