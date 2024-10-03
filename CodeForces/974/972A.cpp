#include <stdio.h>

int main(){
    int numOfTests;
    scanf("%d", &numOfTests);
    for(int i = 0; i < numOfTests; i++){
        int n, k;
        scanf("%d %d", &n, &k);
        int count = 0;
        int gold = 0;
        for(int i = 0; i < n; i++){
            int current; 
            scanf("%d", &current);
            if(current >= k){
                gold += current;
            }
            else if(current == 0 && gold > 0){
                gold--;
                count++;
            }
        }
        printf("%d\n", count);
    }   
    return 0;
}