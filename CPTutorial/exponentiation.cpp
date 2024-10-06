#include <stdio.h>

int efficientExponentian(int a, int b){
    int product = 1;
    int i = 0;
    while(b > 0){
        int currentBit = (b & 1);
        if(currentBit){
            product *= a;
            printf("Multiplication\n");
        }
        a *= a;
        printf("Multiplication\n");
        b = b >> 1;
        i++;
    }
    return product;
}

int main(){
    int a = 2;
    int b = 10;

    printf("Output: %d \n", efficientExponentian(a, b));
}