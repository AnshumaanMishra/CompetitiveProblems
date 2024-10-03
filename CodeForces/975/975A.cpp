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

        if(length % 2 == 0){
            result = length / 2 + max;
        }
        else{
            if(maxIndex % 2 == 0){
                result = length / 2 + 1 + max;
            }
            else{
                result = length / 2 + max;
            }
        }

        // Maximsing the maxVal
        int flag = !(maxIndex % 2);
        for(int i = 0; i < length; i++){

        }

        cout << result << endl;

    }
}