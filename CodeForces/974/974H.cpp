#include <stdio.h>
#include <algorithm>
typedef long long int ll;

int getMax(int array[], int l, int r){
    int max = 0;
    int i;
    int maxindex = 0;
    for(i = l; i <= r; i++){
        if(array[i - 1] >= max){
            max = array[i - 1];
            maxindex = i - 1;
        }
    }
    array[maxindex] = -1;
    return max;
}


int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n, q;
        scanf("%d %d", &n, &q);
        int targets[n];
        for(int j = 0; j < n; j++){
            scanf("%d", &targets[j]);
        }
        for(int j = 0; j < q; j++){
            int l, r;
            scanf("%d %d", &l, &r);
            ll robin = 0; 
            ll sheriff = 0;

            std::sort(targets + l - 1, targets + r);
            for(int i = r; i >= l; i--){
                if((r - i) % 2 == 0){
                    robin += targets[i-1];
                    // printf("Robin")
                }
                else{
                    sheriff+= targets[i-1];
                }
            }

            if(sheriff >= robin){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
    }
}