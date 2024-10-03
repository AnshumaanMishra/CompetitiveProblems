#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int length;
        cin >> length;
        int array[length];
        int max = 0;
        int maxIndex = 0;
        int result;

        // Maximising the maxVal
        for(int j = 0; j < length; j++){
            int input;
            cin >> input;
            array[j] = input;
            if(input > max || (input == max && maxIndex % 2 != 0)){
                max = input;
                maxIndex = j;
            }
        }
        int min = 2000000000;
        int minIndex = 0;
        int max2 = 0;
        int maxIndex2 = 0;
        int min2 = 2000000000;
        int minIndex2 = 0;
        for(int i = (maxIndex % 2); i < length; i += 2){
            if(array[i] < min){
                min = array[i];
                minIndex = i;
            }
        }
        for(int k = !(maxIndex % 2); k < length; k += 2){
            if(array[k] > max2){
                max2 = array[k];
                maxIndex2 = k;
            }
            if(array[k] < min2){
                min2 = array[k];
                minIndex2 = k;
            }
        }
        // cout << min << " " << max << " " << min2  << " " << max2 << endl; 
        int result1, result2;

        if(length % 2 == 0){
            result1 = length / 2 + max + min;
            result2 = length / 2 + max2 + min2;
        }
        else{
            result1 = length / 2 + !(maxIndex % 2) + max + min;
            result2 = length / 2 + (maxIndex % 2) + max2 + min2;
        }
        
        // cout << result1 << " " << result2 << endl; 

        result = (result1 > result2) ? result1 : result2;
        cout << result << endl;

    }
}