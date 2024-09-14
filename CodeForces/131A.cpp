#include <stdio.h>

bool checkUpper(char c){
    if(c >= 'A' && c <= 'Z'){
        return true;
    }
    return false;
}

int main(){
    char input[100];
    char c;
    int size = 0;
    do{
        scanf("%c", &c);
        input[size] = c;
        // printf("c = %c\n", c);
        size++;
    }while(c != '\n');
    input[--size] = '\0';

    bool flag = true;
    for(int i = 1; i < size; i++){
        // printf("%d, %c\n", i, input[i]);cAP
        if(!checkUpper(input[i])){
            // printf("Upper = False\n");
            flag = false;
        }
    }

    char output[size];
    if(flag){
        for(int i = 0; i < size; i++){
            if(i == 0 && !checkUpper(input[i])){
                output[i] = input[i] + 'A' - 'a';
            }
            else if(checkUpper(input[i])){
                output[i] = input[i] + 'a' - 'A';
            }
        }\
        for(int i = 0; i < size; i++){
            printf("%c", output[i]);
        }   
    }
    else{
        for(int i = 0; i < size; i++){
            printf("%c", input[i]);
        }   
    }


}