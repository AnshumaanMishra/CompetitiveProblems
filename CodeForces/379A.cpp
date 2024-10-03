#include <stdio.h>

int main(){
    int a, b;
    int used = 0,fresh = 0, left = 0;
    scanf("%d %d", &a, &b);
    int retVal = 0;
    fresh += a;
    while(fresh >= 1){
        retVal += fresh;
        left += (fresh % b);
        fresh = left / b + (fresh / b);
        left = left % b;
        // printf("a: %d, b: %d, fresh: %d, retVal: %d, left: %d\n", a, b, fresh, retVal, left);
    }
    retVal += left / b;
    printf("%d", retVal);
}