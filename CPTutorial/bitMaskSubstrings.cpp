#include <bits/stdc++.h>
#include <math.h>
using namespace std;

class HashTable{
    private:
        vector<vector<char>> storage;
        int table[26];

    public:
        HashTable(char passedString[]){
            for(int i = 0; i < 26; i++){
                table[i] = 0;
            }
            assign(passedString);
        }

        int getIndex(char key){
            return key - 'a';
        }

        int getKey(int index){
            return (int)(index + 'a');
        }

        void assign(char passedString[]){
            int i = 0;
            while(passedString[i] != '\0'){
                table[getIndex(passedString[i])] += 1;
                i++;
            }
        }

        void printCombination(int num){
            int i = 0;
            vector<char> newV;
            newV.push_back(' ');
            storage.push_back(newV);
            while(num > 0){
                if(num & 1){
                    printf("%c", getKey(i));
                    storage.back().push_back(getKey(i));
                }
                i++;
                num = num >> 1;
            }
        }

        void printStorage(){
            sort(storage.begin(), storage.end());
            for(int i = 0; i < storage.size(); i++){
                for(int j = 0; j < storage[i].size(); j++){
                    printf("%c", storage[i][j]);
                }
                printf(",");
            }
        }
        
};

int main(){
    char parameterString[] = "abc";
    int length = sizeof(parameterString)/sizeof(char);
    int combinations = pow(2, length - 1);
    HashTable table1 = HashTable(parameterString);
    for(int i = 1; i < combinations; i++){
        table1.printCombination(i);
        printf(", ");
    }
    printf("\n");
    table1.printStorage();
}