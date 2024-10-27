#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t > 0){
        int n;
        cin >> n;
        lli array[n];
        for(int i = 0; i < n; i++){
            cin >> array[i];
        }

        lli sumsl[n];
        lli sumsr[n];
        lli tempsum = 0;
        for(int i = 0; i < n; i++){
            tempsum += array[i];
            sumsl[i] = tempsum;
        }
        for(int i = 0; i < n; i++){
            cout << sumsl[i] << " ";
        }
        cout << endl;
        tempsum = 0;
        for(int i = n - 1; i > -1; i--){
            tempsum += array[i];
            sumsr[i] = tempsum;
        }
        for(int i = 0; i < n; i++){
            cout << sumsr[i] << " ";
        }
        cout << endl;
        int l = 0;
        int r = 0;
        int currentl = 0;
        int currentr = n - 1;
        int i = 0;
        int current;
        while(i < n){
            current = sumsl[i];
            i++;
            while(i < n && sumsl[i] != current){
                i++;
                cout << sumsl[i] << " " << current << endl;
            }
            if(i < n)
                l++;
            i++;
        }
        cout << l << endl;
        i = 0;
        while(i < n){
            current = sumsr[n - i - 1];
            i++;
            while(i < n && sumsr[n - i - 1] != current){
                i++;
                cout << sumsr[i] << " " << current << endl;
            }
            if(i < n)
                r++;    
            i++;
        }
        // cout << r << endl;

        // i = 0;
        // for(i = 1; i < n; i++){
        //     if(sumsl[currentl] == sumsl[i]){
        //         l++;
        //         currentr = i + 1;
        //         i++;
        //     }
        // }

        int max = (r > l) ? r : l;
        cout << max << endl;


        t--;
    }
    return 0;
}