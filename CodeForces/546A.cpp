#include <stdio.h>

int main(){
    int k, n, w;
    scanf("%d %d %d", &k, &n, &w);
    printf("%d", (k*(w*(w+1)/2)-n < 0) ? 0 : k*(w*(w+1)/2)-n);
}