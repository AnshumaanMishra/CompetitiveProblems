#include <stdio.h>

class HashMap{
    private:
        long long* _mainArray;
        int _size = 40;

    public:
        HashMap(){
            _mainArray = new long long[_size];
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

 
        long long getSum(){
            long long sum = 0;
            for(int i = 0; i < _size; i++){
                long temp = _mainArray[i];
                sum += temp*temp;
            }
            return sum;
        }
};

int main(){
    HashMap newMap = HashMap();
    char input[100001];
    char c;
    int i = 0;
    do{
        scanf("%c", &c);
        input[i] = c;
        i++;
    }while(c != '\n');
    
    input[100000] = '\0';
    newMap.iterate(input);
    // newMap.printArray();
    printf("%lld", newMap.getSum());
    return 0;
}