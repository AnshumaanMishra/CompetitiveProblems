#include <bits/stdc++.h>
using namespace std;

void multiply(int matrix1[2][2], int matrix2[2][1], int answer[2][1]){
    answer[0][0] = matrix1[0][0] * matrix2[0][0] + matrix1[0][1] * matrix2[1][0];
    answer[1][0] = matrix1[1][0] * matrix2[0][0] + matrix1[1][1] * matrix2[1][0];
}



int main(){
    int array22[2][2] = {{1, 2}, {3, 4}};
    int array21[2][1] = {{1}, {2}};
    int answer[2][1];
    multiply(array22, array21, answer);
    cout << answer[0][0] << endl << answer[1][0] << endl;
}