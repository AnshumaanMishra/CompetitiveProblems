#include <stdio.h>
#include <string>

bool checkConsonant(char c){

    if((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') || (c == 'y') || (c == 'A') || (c == 'E') || (c == 'O') || (c == 'I') || (c == 'U') || (c == 'Y')){
        return 1;
    }
    return 0;
}

char toLower(char c){
    if(c >= 'A' && c <= 'Z'){
        return c + ('a' - 'A');
    }
    return c;
}

int countConsonants(char string[]){
    int consonants = 0;
    int i = 0;
    while(string[i] != '\0'){
        if(!checkConsonant(string[i])){
            consonants++;
        }
        i++;
    }
    return consonants;
}

int main(){
    char inputString[100];
    int size = 0;
    char c;
    do{
        scanf("%c", &c);
        inputString[size] = c;
        size++;
    }while(c != '\n');
    inputString[size] = '\0';
    int outputSize = 2 * countConsonants(inputString);
    char outputString[outputSize];
    int j = 0;
    for(int i = 0; i < size-1; i++){
        if(!checkConsonant(inputString[i])){
            outputString[j] = '.';
            j++;
            outputString[j] = toLower(inputString[i]);

            for(int i = 0; i < j; i++){
                printf("%c", outputString[i]);
            }
            printf("\n");
            j++;
        }
    }
    outputString[j] = '\0';

    for(int i = 0; i < outputSize-2; i++){
        printf("%c", outputString[i]);
    }
    printf("\n");
}