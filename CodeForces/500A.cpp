#include <stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    m--;
    int x = 0;
    for(int i = 0; i < n - 1; i++){
        // printf("Iteration: %d %d %d\n", i, m, x);
        if(x == m){
            printf("YES");
            return 0;
        }
        int temp;
        scanf("%d", &temp);
        x = (x <= i) ? (i + temp) : x;
        // printf("Iteration: %d %d %d\n", i, m, x);
        if((x >= n - 1) && (x != m)){
            // printf("Iteration: %d %d %d\n", i, m, x);

            printf("NO");
            return 0;
        }
    }
    if(x == m){
        printf("YES");
        return 0;
    }
    printf("NO");
    return 0;
}