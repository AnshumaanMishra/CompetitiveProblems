#include <cstdio>

int* mergeSort(int passedArray[], int start, int end){
    int size = end-start+1;
    int returnArray[size];
    printf("%d, %d, %d \n", *passedArray, start, end);
    if(size == 2){
        if(*passedArray < *(passedArray+1)){
            *returnArray = *passedArray;
            *(returnArray+1) = *(passedArray+1);
            return returnArray;
        }
        else{
            *(returnArray+1) = *passedArray;
            *(returnArray) = *(passedArray+1);
            return returnArray;
        }
    }
    if(size == 1){
        return passedArray;
    }
    int* fH = mergeSort(passedArray, start, size/2-1);
    printf("%d\n", *fH);
    int* sH = mergeSort(passedArray, size/2, end);
    printf("%d\n", *sH);
    int i = 0;
    for(i = 0; i < size/2; i++){
        returnArray[i] = *(fH+i); 
    }
    for(; i < size; i++){
        returnArray[i] = *(sH+i-size/2); 
    }

    return returnArray;

}

int main(){
    int size;
    scanf("%d", &size);
    int array[size];
    for(int i = 0; i < size; i++){
        scanf("%d", array+i);
    }
    int* sorted = mergeSort(array, 0, size-1);
    for(int i = 0; i < size; i++){
        printf("%d, ", *(sorted+i));
    }
}