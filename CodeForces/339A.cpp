#include <stdio.h>

int main(){
    char string[100];
    int size = 0;
    char c;
    do{
        scanf("%c", &c);
        string[size] = c;
        size++;
    }while(c != '\n');
    size--;
    int array[100];
    for(int i = 0; i < size; i++){
        if(string[i] != '+'){
            array[i] = ((int)string[i]);
        }
    }

    
}