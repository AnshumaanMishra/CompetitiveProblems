#include <bits/stdc++.h>
#include <math.h>
using namespace std;

void getValues(vector<float>& array, float* answer){
    float min = 0; 
    float max = 0;
    float secmax = 0;
    for(float i = 0; i < array.size(); i++){
        if(array[i] < array[min]){
            min = i;
        }
        if(array[i] > array[max]){
            max = i;
        }
    }
    for(float i = 0; i < array.size(); i++){
        if((array[i] >= array[secmax]) && (array[i] <= array[max])){
            if(array[i] <= array[max] && i != max){
                secmax = i;
            }
            else if(array[i] < array[max]){
                secmax = i;
            }
        }
    }
    // float answer[] = {min, max, secmax};
    *answer = min;
    *(answer + 1) = max;
    *(answer + 2) = secmax;
}



int main(){
    float t;
    cin >> t;
    while(t > 0){
        float n;
        cin >> n;
        vector<float> array(n, 0);
        for(float i = 0; i < n; i++){
            cin >> array[i];
        }      
        while(array.size() > 1){
            float* answer = new float[3];
            getValues(array, answer);
            float minIndex = *answer;
            float maxIndex = *(answer + 1);
            float secMaxIndex = *(answer + 2);
            if(minIndex == secMaxIndex){
                secMaxIndex = maxIndex;
            }
            // cout << minIndex << " " << secMaxIndex << " " << maxIndex << " " << endl;
            array[minIndex] = floor((array[minIndex] + array[secMaxIndex]) / 2);
            array.erase(array.begin() + secMaxIndex);

            // for(float j = 0; j < array.size(); j++){
            //     cout << array[j] << " ";
            // }
            // cout << endl;
        }
        cout << (int)array[0] << endl;
        t--;
    }
}