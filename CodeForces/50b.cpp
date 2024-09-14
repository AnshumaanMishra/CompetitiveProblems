#include <stdio.h>

int main(){
    char input[100000];
    int size = 0;
    char c;
    do{
        scanf("%c", &c);
        input[size] = c;
        size++;
    }while(c != '\n');
    size--;
    int num = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            num += (input[i] == input[j]);
        }    
    }
    printf("%d", num);
}