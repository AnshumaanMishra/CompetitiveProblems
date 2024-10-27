#include <bits/stdc++.h>
using namespace std;

int getDisturbance(vector<int> array){
    int count = 0;
    for(int i = 0; i < array.size() - 1; i++){
        if(array[i] == array[i + 1]){
            count++;
        }
    }
    return count;
}

int main(){
    int t;
    cin >> t;
    while(t > 0){
        int n;
        cin >> n;
        vector<int> array(n);
        for(int i = 0; i < n; i++){
            cin >> array[i];
        }
        int currentDisturbance = getDisturbance(array);
        for(int i = 0; i < n / 2; i++){
            int temp = array[i];
            array[i] = array[n - i - 1];
            array[n - i - 1] = temp;
            int newDisturbance = getDisturbance(array);
            if(newDisturbance > currentDisturbance){
                int temp = array[i];
                array[i] = array[n - i - 1];
                array[n - i - 1] = temp;
            }
            else{
                currentDisturbance = newDisturbance;
            }

        }
        for(int i = 0; i < n / 2; i++){
            int temp = array[i];
            array[i] = array[n - i - 1];
            array[n - i - 1] = temp;
            int newDisturbance = getDisturbance(array);
            if(newDisturbance > currentDisturbance){
                int temp = array[i];
                array[i] = array[n - i - 1];
                array[n - i - 1] = temp;
            }
            else{
                currentDisturbance = newDisturbance;
            }

        }
        cout << currentDisturbance << endl;
        t--;
    }
    return 0;
}