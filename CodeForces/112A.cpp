#include <stdio.h>

int compareStr(int size, char* str1, char* str2){
    for(int i = 0; i < size; i++){
        if(str1[i] >= 'A' && str1[i] <= 'Z'){
            str1[i] = str1[i] - ('A' - 'a');
        }
        if(str2[i] >= 'A' && str2[i] <= 'Z'){
            str2[i] = str2[i] - ('A' - 'a');
        }
        int diff = str1[i] - str2[i];
        if(str1[i] < str2[i]){
            return -1;
        }
        else if(str1[i] > str2[i]){
            return 1;
        }
    }
    return 0;
}

int main(){
    char str1[100];
    char str2[100];
    int size = 0;
    char c;
    do{
        scanf("%c", &c);
        str1[size] = c;
        size++;
    }while(c != '\n');
    size = 0;
    do{
        scanf("%c", &c);
        str2[size] = c;
        size++;
    }while(c != '\n');

    printf("%d", compareStr(size, str1, str2));

}