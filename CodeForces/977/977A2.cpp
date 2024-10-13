#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main(){
    float t;
    cin >> t;
    while(t > 0){
        float n;
        cin >> n;
        vector<int> array(n, 0);
        float sum = 0;
        bool allSame = 1;
        for(float i = 0; i < n; i++){
            cin >> array[i];
            sum += (float)array[i];
            if(i > 0 && array[i] != array[i - 1]){
                allSame = 0;
            }
        }      
        cout << sum << endl;
        if(allSame){
            cout << array[0] << endl;
            t--;
            continue;
        }
        int ans = 0;
        float avg = sum / n;
        if(avg - floor(avg) > floor(t / 2)){
            ans = floor(avg) + 2;
        }
        else{
            ans = floor(avg) + 1;
        }
        cout << ans << endl;
        t--;
    }
    return 0;
}