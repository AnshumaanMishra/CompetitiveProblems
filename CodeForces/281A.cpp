#include <stdio.h>

int main(){
    char input[1000];
    char c;
    int size = 0;
    do{
        scanf("%c", &c);
        input[size] = c;
        size++;
    }while(c != '\n');
    if('a' <= input[0] && input[size] <= 'z'){
        input[0] += 'A' - 'a';
    }
    for(int i = 0; i < size; i++){
        printf("%c", input[i]);
    }
}