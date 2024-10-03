#include <stdio.h>

class HashTable{
    private:
        char _team1[11];
        char _team2[11];
        bool _team1Set = false;
        bool _team2Set = false;
        int _goals1 = 0;
        int _goals2 = 0;

    public:
        HashTable(){

        }

        void addItem(char teamName[]){
            bool team1Matched = compareStr(teamName, _team1);
            bool team2Matched = compareStr(teamName, _team2);
            // printf("%d, %d\n", team1Matched, team2Matched);
            if(team1Matched){
                _goals1++;
            }
            else if(team2Matched){
                _goals2++;
            }
            else if(!team1Matched && !team2Matched){
                if(_team1Set){
                    // printf("%s\n", teamName);
                    setStr(teamName, _team2);
                    _team2Set = true;
                    _goals2++;
                }
                else{
                    setStr(teamName, _team1);
                    // printf("%s\n", teamName);
                    _team1Set = true;
                    _goals1++;
                }
            }
        }

        void setStr(char str1[], char str2[]){
            int i = 0;
            while(str1[i] != '\0'){
                str2[i] = str1[i];
                i++;
                // printf("Setting; %s, %s\n", str1, str2);
            }
            str2[i] = '\0';
        }

        bool compareStr(char str1[], char str2[]){
            int i = 0;
            while(str1[i] != '\0'){
                if(str2[i] == '\0'){
                    return false;
                }
                if(str1[i] != str2[i]){
                    return false;
                }
                i++;
            }
            return true;
        }

        void printResult(){
            // printf("%d, %d\n", _goals1, _goals2);
            // printf("%s, %s\n", _team1, _team2);
            if(_goals1>_goals2){
                int i = 0;
                while(_team1[i] != '\0'){
                    printf("%c", _team1[i]);
                    i++;
                }
            }
            else{
                int i = 0;
                while(_team2[i] != '\0'){
                    printf("%c", _team2[i]);
                    i++;
                }
            }
        }

};

int main(){
    int n;
    scanf("%d", &n);
    char container;
    scanf("%c", &container);
    HashTable newTable = HashTable();
    for(int i = 0; i < n; i++){
        char temp[11];
        int size = 0;
        char c;
        do{
            scanf("%c", &c);
            temp[size] = c;
            size++;
        }while(c != '\n');
        temp[--size] = '\0';
        // int j = 0;
        // while(temp[i] != '\0'){
        //     printf("%c", temp[i]);
        //     i++;
        // }
        newTable.addItem(temp);
    }
    newTable.printResult();
}