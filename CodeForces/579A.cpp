#include <stdio.h>

int main(){
    long long int a;
    scanf("%lld", &a);
    long long int count = 0;
    while(a){
        count += a & 1;
        a >>= 1;
    }
    printf("%lld", count);
}