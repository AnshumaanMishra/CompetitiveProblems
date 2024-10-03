#include <stdio.h>
typedef long long int ll;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n;
        scanf("%d", &n);
        int* wealth = new int[100001 * sizeof(int)];
        for(int k = 0; k < 100001; k++){wealth[k] = 0;}
        int sum = 0;
        int first, second;
        for(int j = 1; j < n + 1; j++){
            int inp;
            scanf("%d", &inp);
            wealth[inp]++;
            
            // printf("%d %d\n", inp, wealth[inp]);
            sum += inp;
            if(j == 1){
                first = inp;
            }
            if(j == 2){
                second = inp;
            }
        }
        if(n == 1){
            printf("%d\n", -1);
            continue;
        }
        if(n == 2){
            if((first+second)/4 > first || (first+second)/4 < first){
                printf("%d\n", -1);
                continue;
            }
        }
        int count = 0;
        for(int j = 1; j < 100001 + 1; j++){
            count += wealth[j];
        }
        int mid = 0;
        int sum1 = 0;
        for(int i = 1; i < 100001 + 1; i++){
            sum1 += wealth[i];
            if(sum1 >= count / 2 + 1){
                mid = i;
                break;
            }
        }
        int x = sum - mid * 2 * n;
        if(x >= 0){
            x = 0;
        }
        else{
            x = -x + 1;
        }
        printf("%d\n", x);
        // printf("count = %d, mid = %d, x = %d, sum = %d, n = %d\n", count, mid, x, sum, n);
    }
}