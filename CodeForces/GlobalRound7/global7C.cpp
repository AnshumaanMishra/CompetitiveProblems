#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

struct Node{
    int _val;
    Node* next;
};

class LinkedList{
    private:
        Node* firstNode = NULL;
        Node* lastNode = firstNode;
        int length;

    public:
        LinkedList(){
            lastNode = firstNode;
        }

        void addLeft(int value){
            Node* newNode = new Node;
            newNode->_val = value;
            newNode->next = firstNode;
            firstNode = newNode;
            if(lastNode == NULL){
                lastNode = newNode;
            }
        }

        void addRight(int value){
            Node* newNode = new Node;
            newNode->_val = value;
            newNode->next = NULL;
            if(lastNode == NULL){
                lastNode = newNode;
            }
            else{
                lastNode->next = newNode;
                lastNode = newNode;
            }
            if(firstNode == NULL){
                firstNode = newNode;
            }
        }

        void print(){
            Node* currentNode = firstNode;
            while(currentNode != NULL){
                cout << currentNode->_val << " ";
                currentNode = currentNode->next;
            }
            cout << endl;
        }
};

int main(){
    int t;
    cin >> t;
    while(t > 0){
        lli n, k = 0;
        cin >> n;
        LinkedList List1 = LinkedList();
        if((n - 1) && (!((n - 1) & ((n - 1) - 1)))){
            cout << n << endl;
            cout << 2 << " " << 1 << " ";
            for(int i = 3; i <= n; i++){
                cout << i << " ";
            }
            cout << endl;
            t--;
            continue;
        }
        for(int i = 1; i <= 4; i++){
            List1.addRight(i);
        }
        int i = 5;
        while(i <= n){
            if(((i + 1) / 2) % 2 == 1){
                List1.addLeft(i);
            }
            else{
                List1.addRight(i);
            }
            i++;
        }
        int factor = 4;
        for(int i = 2; i <= 18; i++){
            if(n < factor){
                cout << factor - 1 << endl;
                break;
            }
            factor*=2;
        }
        // cout << List1.getK() << endl;
        List1.print();
        t--;
    }
}