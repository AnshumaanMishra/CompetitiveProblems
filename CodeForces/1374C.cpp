#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int m;
        char container;
        scanf("%d", &m);
        int count = 0;
        scanf("%c", &container);
        for(int j = 0; j < m; j++){
            char c;
            scanf("%c", &c);
            if((c == '(')){
                count++;
            }
            else if((c == ')') && count){
                count--;
            }
        }
        scanf("%c", &container);
        printf("%d\n", count);
    }

}