#include <bits/stdc++.h>
using namespace std;

int main(){
    int length = 5;
    int array[length] = {1, 0, 2, 3, 7};
    int sumM[length];
    int sum = 0;
    int modArr[length];
    for(int i = 0; i < length; i++){
        sum += array[i];
        sumM[i] = sum;
        modArr[i] = sum % length;
    }
    int found = -1;
    int size = 0;
    for(int i = 0; i < length - 1; i++){
        for(int j = i; j < length; j++){
            if(modArr[i] == modArr[j]){
                found = i;
                size = j - i;
            }
        }
        if(found >= 0){
            break;
        }
    }
    cout << found + 1 << endl << size << endl;
}