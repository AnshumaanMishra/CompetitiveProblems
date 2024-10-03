#include <iostream>
#include <string>
using namespace std;

bool checkOddEven(int num){
    return (num & 1);
}

bool getIthBit(int num, int i){
    return (num) & 1 << i;
}

bool clearBit(int num, int i){
    return num & ~(1 << i);
}

int setIthBit(int num, int i, int val){
    if(getIthBit(num, i)){
        return num & (val << i);    
    }
    return num | (val << i);
}

int clearIBits(int num, int i){
    return num & (~0 << i);
}

int clearBitsInRange(int num, int start, int end){
    int a = (~0) << (end+1);
    int b = (1 << start) - 1;
    int mask = a | b;
    return num & mask;
}

int replaceBits(int N, int M, int i, int j){
    clearBitsInRange(N, i, j);
    int mask = M << i;
    return N | mask;
}

bool checkPowerOfTwo(int num){
    return !(num & (num - 1));
}

int countSetBits(int num){
    if(num == 0){
        return 0;
    }
    return (num & 1) + countSetBits(num >> 1);
}

int countSetBitsAlt(int num){
    int count = 0;
    while(num > 0){
        num = num & (num - 1);
        count++;
    }
    return count;
}

// Very Important
int removeLastSetBit(int num){
    return num & (num - 1);
}

//Find last set bit
int findLastSetBit(int num){
    int i = 1;
    while(num){
        if(num & 1){
            return i; 
        }
        num = num >> 1;
        i++;
    }
    return 0;
}

// Two unique Numbers
void twoUniqueNumbers(int array[], int length){
    int net = 0;
    for(int i = 0; i < length; i++){
        net = net ^ array[i];
    }
    int index = findLastSetBit(net);
    int num1 = 0;
    for(int i = 0; i < length; i++){
        if(getIthBit(array[i], index)){
            num1 = num1 ^ array[i];
        }   
    }
    printf("Number 1 = %d\n", num1);
    num1 = 0;
    for(int i = 0; i < length; i++){
        if(!getIthBit(array[i], index)){
            num1 = num1 ^ array[i];
        }   
    }
    printf("Number 2 = %d\n", num1);

}



int main(){
    printf("%d\n", checkOddEven(4));
    printf("%d\n", getIthBit(4, 2));
    printf("%d\n", clearBit(4, 2));
    printf("%d\n", setIthBit(4, 0, 1));
    printf("%d\n", clearIBits(5, 1));
    printf("%d\n", replaceBits(512, 21, 2, 6));
    printf("%d\n", clearBitsInRange(31, 1, 3));
    printf("%d\n", replaceBits(15, 2, 1, 3));
    printf("%d\n", replaceBits(512, 21, 2, 6));
    printf("%d\n", checkPowerOfTwo(512));
    printf("%d\n", countSetBits(5));
    printf("%d\n", countSetBitsAlt(5));
    int passedArray[] = {1, 2, 3, 4, 5, 6, 4, 3, 2, 1};
    int length = sizeof(passedArray)/sizeof(int);
    twoUniqueNumbers(passedArray, length);
}