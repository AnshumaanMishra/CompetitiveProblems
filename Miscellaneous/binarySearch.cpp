#include <bits/stdc++.h>
using namespace std;

int binarySearch(int array[], int l, int r, int query){
    if((query > array[r]) || (query < array[l])){
        return -1;
    }
    int mid = (r + l)/2;
    if(query == array[mid]){
        return mid;
    }
    else if(query > array[mid]){
        return binarySearch(array, mid + 1, r, query);
    }
    return binarySearch(array, l, mid, query);

}

int main(){
    int nums[] = {8, 9, 10, 2, 5, 6};
    int length = 6;
    int l = 0; 
    int r = length - 1;

    while(1){
        int mid = (l + r)/2;
        if(nums[mid] < nums[l]){
            r = mid - 1;
        }
        if(nums[mid] > nums[l]){
            l = mid;
        }
        if(l == r){
            break;
        }


    }
    return 0;
}