#include <cstdio>

bool checkConsec(char inputArray[], int index){
    return(inputArray[index] == inputArray[index + 1]);
}

void remove(char inputArray[], int index){
    int i = index;
    while(inputArray[i] != '\0'){
        inputArray[i] = inputArray[i + 1];
        i++;
    }
}

int main(){
    int size;
    scanf("%d", &size);
    char input[size+1];
    for(int i = 0; i < size+1; i++){
        scanf("%c", &input[i]);
    }
    remove(input, 0);
    input[size] = '\0';
    int i = 0;
    int operations = 0;
    while(input[i] != '\0'){
        if(checkConsec(input, i)){

            printf("Inside Operation: %d: %d, %s, %c, %c\n",operations, i, input, input[i], input[i+1]);
            remove(input, i);
            i--;
            operations++;

            // continue;
        }
        printf("Operation: %d: %d, %s\n",operations, i, input);
        i++;
        
    }
    printf("%d\n", operations);
}