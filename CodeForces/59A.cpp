#include <stdio.h>

int main(){
    char input[101];
    int size = 0;
    char c;
    do{
        scanf("%c", &c);
        input[size] = c;
        size++;
    }while(c != '\n');

    // printf("c: %c", input[0]);
    input[size-1] = '\0';
    int uc = 0;
    int lc = 0;
    int i = 0;
    while(input[i] != '\0'){

        // printf("%c", input[i]);
        if(input[i] >= 'A' && input[i] <= 'Z' ){
            uc++;
        }
        else{
            lc++;
        }
        i++;
    }

    // printf("%d, %d\n", uc, lc);
    i = 0;
    if(uc > lc){
        while(input[i] != '\0'){

        // printf("%c", input[i]);
            if(input[i] >= 'a' && input[i] <= 'z' ){
                input[i] += 'A' - 'a';
            }
            i++;
        }
    }
    else{
        while(input[i] != '\0'){

        // printf("%c", input[i]);
            if(input[i] >= 'A' && input[i] <= 'Z' ){
                input[i] += 'a' - 'A';
            }
            i++;
        }
    }
    i = 0;
    while(input[i] != '\0'){
        printf("%c", input[i]);
        i++;
    }
}