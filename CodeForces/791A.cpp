#include <stdio.h>
#include <math.h>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    int i = 0;
    while(a <= b){
        a *= 3;
        b *= 2;
        i++;
    }
    printf("%d", i);
}