#include <bits/stdc++.h>
#include <array>
#include <ctime>

void updateArray(std::array<int, 6> &arr, int i, int val){
    (arr)[i] = val;
}

void printArray(std::array<int, 6> &arr){
    for(int i = 0; i < arr.size(); i++){
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}

int main(){
    std::array<int, 6> arr = {1, 2, 3, 4, 5, 6};
    // float start = clock();
    updateArray(arr, 2, 7);
    printArray(arr);
    // std::cout << clock() - start << std::endl;
    std::sort(arr.begin(), arr.end());
    printArray(arr);
    // std::cout << clock() - start << std::endl;
    arr.fill(5);
    printArray(arr); 
}