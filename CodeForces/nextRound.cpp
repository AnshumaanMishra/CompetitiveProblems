#include <stdio.h>

int main(){
    int size, index;
    scanf("%d %d", &size, &index);
    int array[size];
    int i = 0;
    int passNum = 0;
    while(i < size){
        scanf("%d", &array[i]);
        i++;
    }
    i = 0;
    while(i < size){
        passNum += (array[i] >= array[index-1]) && (array[i] > 0); 
        i++;
    }
    printf("%d", passNum);
}