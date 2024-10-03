#include <bits/stdc++.h>


void merge(int leftArray[], int leftSize, int rightArray[], int rightSize, int array[]){
    int i = 0, l = 0, r = 0;
    while((l < leftSize) && (r < rightSize)){
        if(leftArray[l] < rightArray[r]){
            array[i] = leftArray[l];
            i++;
            l++;
        }
        else{
            array[i] = rightArray[i];
            r++;
            i++;
        }
        while(l < leftSize){
            array[i] = leftArray[l];
            i++;
            l++;
        }
        
        while(r < rightSize){
            array[i] = rightArray[l];
            i++;
            l++;
        }
    }
}

void mergeSort(int passedArray[], int length){
    if(length <= 1){
        return;
    }
    int middle = length / 2;
    int leftArray[middle];
    int rightArray[length - middle];
    for(int i = 0; i < middle; i++){
        leftArray[i] = passedArray[i];
    }
    for(int i = middle; i < length; i++){
        rightArray[i] = passedArray[i];
    }
    mergeSort(leftArray, middle);
    mergeSort(rightArray, length - middle);
    merge(leftArray, middle, rightArray, length - middle, passedArray);
}


int main(){

    // int lengthOfList;
    // std::cin >> lengthOfList;
    // int coins[lengthOfList];
    // for(int i = 0; i < lengthOfList; i++){
    //     std::cin >> coins[i];
    // }
    int sampleArray[] = {7, 6, 5, 4, 3, 2, 1};    
    mergeSort(sampleArray, 7);
    std::cout << sampleArray[0];
    return 0;

}