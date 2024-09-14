#include <stdio.h>

int main(){
    int s, n;
    scanf("%d %d", &s, &n);
    for(int i = 0; i < n; i++){
        int d, b;
        scanf("%d %d", &d, &b);
        if(s < d){
            // printf("%d %d\n", d, s);
            printf("NO");
            return 0;
        }
        else{
            s += b;
        }
    }
    printf("YES");
    return 0;
}