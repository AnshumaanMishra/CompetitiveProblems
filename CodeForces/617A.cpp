#include <stdio.h>

int main(){
    int a;
    scanf("%d", &a);
    int b = 0;
    while(a > 4){
        b++;
        a-=5;
    }
    if(a != 0){
        b++;
    }
    printf("%d", b);
}