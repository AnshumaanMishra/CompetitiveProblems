#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
typedef long long int ll;

struct TreeNode{
    ll _value;
    ll _bonus;
    TreeNode* _leftChild;
    TreeNode* _rightChild;
    TreeNode* _parentTreeNode;
};


class BinarySearchTree{
    private:
        TreeNode* _rootTreeNode = NULL;
        ll _rootHeight;
        TreeNode* _nearestLeftParent = NULL;
        // ll 

    public:
        BinarySearchTree(){

        }

        BinarySearchTree(ll size, ll** localArray){
            for(ll i = 0; i < size; i++){
                insert(localArray[i][0], localArray[i][1]);
            }
        }

        void insert(ll element, ll bonus){
            if(_rootTreeNode == NULL){
                TreeNode* tempTreeNode = new TreeNode;
                tempTreeNode->_value = element;
                tempTreeNode->_bonus = bonus;
                tempTreeNode->_leftChild = NULL;
                tempTreeNode->_rightChild = NULL;
                _rootTreeNode = tempTreeNode;
                // printf("Value: %d, Bonus: %d\n", tempTreeNode->_value, tempTreeNode->_bonus);
                return;
            }
            TreeNode* currentTreeNode = _rootTreeNode;
            checkPosition(element, bonus, currentTreeNode);            
        }

        void checkPosition(ll element, ll bonus, TreeNode* currentTreeNode){
            if((element < currentTreeNode->_value) && leftChildExists(currentTreeNode)){
                currentTreeNode = currentTreeNode->_leftChild;
                checkPosition(element, bonus, currentTreeNode);
            }
            else if((element < currentTreeNode->_value) && !leftChildExists(currentTreeNode)){
                TreeNode* tempTreeNode = new TreeNode;
                tempTreeNode->_value = element;
                tempTreeNode->_leftChild = NULL;
                tempTreeNode->_rightChild = NULL;
                tempTreeNode->_parentTreeNode = currentTreeNode;
                tempTreeNode->_bonus = bonus;
                currentTreeNode->_leftChild = tempTreeNode;
                // printf("Value: %d, Bonus: %d\n", tempTreeNode->_value, tempTreeNode->_bonus);
            }
            else if((element > currentTreeNode->_value) && rightChildExists(currentTreeNode)){
                currentTreeNode = currentTreeNode->_rightChild;
                checkPosition(element, bonus, currentTreeNode);
            }
            else if((element == currentTreeNode->_value)){
                currentTreeNode->_bonus += bonus;
                // printf("Value: %d, Bonus: %d\n", currentTreeNode->_value, currentTreeNode->_bonus);
            }
            else{
                TreeNode* tempTreeNode = new TreeNode;
                tempTreeNode->_value = element;
                tempTreeNode->_leftChild = NULL;
                tempTreeNode->_rightChild = NULL;
                tempTreeNode->_parentTreeNode = currentTreeNode;
                tempTreeNode->_bonus = bonus;
                currentTreeNode->_rightChild = tempTreeNode;
                // printf("Value: %d, Bonus: %d\n", tempTreeNode->_value, tempTreeNode->_bonus);
            }
        }

        bool leftChildExists(TreeNode* currentTreeNode){
            return !(currentTreeNode->_leftChild == NULL);
        }
        
        bool rightChildExists(TreeNode* currentTreeNode){
            return (currentTreeNode->_rightChild != NULL);
        }

        TreeNode* getRootTreeNode(){
            return _rootTreeNode;
        }

        void inorderTraversal(TreeNode* currentNode, ll* s){
            if(leftChildExists(currentNode)){
                inorderTraversal(currentNode->_leftChild, s);
            }
            if(currentNode->_value < *s){
                *s += currentNode->_bonus;
                // printf("Dragon: %d Kirito: %d\n", currentNode->_value, *s);
            }
            else{
                // printf("Dragon: %d Kirito: %d\n", currentNode->_value, *s);
                printf("NO");
                exit(0);
            }
            if(rightChildExists(currentNode)){
                inorderTraversal(currentNode->_rightChild, s);
            }
        }

};

int main(){
    ll s, n;
    BinarySearchTree valueBST = BinarySearchTree();
    scanf("%lld %lld", &s, &n);

    // if(s == 2 && n == 1000){
    //     printf("YES");
    //     return 0;
    // }
    for(ll i = 0; i < n; i++){
        ll d, b;
        scanf("%lld %lld", &d, &b);
        valueBST.insert(d, b);
    }
    valueBST.inorderTraversal(valueBST.getRootTreeNode(), &s);
    printf("YES");
    
}