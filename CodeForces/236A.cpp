#include <stdio.h>

class HashMap{
    private:
        int* _mainArray;
        int _size = 36;

    public:
        HashMap(){
            _mainArray = new int[_size];
            for(int i = 0; i < _size; i++){
                _mainArray[i] = 0;
            }
        }
        
        int getIndex(char index){
            if(((int)index < 58) && ((int)index > 47)){
                return ((int)index - 48);
            }
            return ((int)index - 87);
            
        }

        int getKey(int index){
            if(index > -1 && index < 10){
                return '0' + (index);
            } 
            return 'a' + index - 10;
        }

        void iterate(char* iterString){
            int i = 0;
            char c = iterString[i];
            while(c != '\0'){
                // printf("c = %c, index = %d\n", c, getIndex(c));
                _mainArray[getIndex(c)]++;
                i++;
                c = iterString[i];
            }
        }

 
        int getSum(){
            int sum = 0;
            for(int i = 0; i < _size; i++){
                sum += (_mainArray[i] != 0);
                printf("%d, %d, %c\n", _mainArray[i], sum, getKey(i));
            }
            return sum;
        }
};

int main(){
    char input[1000];
    char c;
    int size = 0;
    do{
        scanf("%c", &c);
        input[size] = c;
        size++;
    }while(c != '\n');
    input[size] = '\0';
    HashMap newMap = HashMap();
    newMap.iterate(input);
    int sum = newMap.getSum();
    if(sum % 2 != 0){
        printf("IGNORE HIM!");
    }
    else{
        printf("CHAT WITH HER!");
    }
}