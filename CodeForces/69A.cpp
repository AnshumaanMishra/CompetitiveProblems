#include <stdio.h>

int main(){
    int rows;
    scanf("%d", &rows);

    int matrix[rows][3];
    for(int i = 0; i < rows; i++){
        scanf("%d %d %d", &matrix[i][0], &matrix[i][1], &matrix[i][2]);
    }

    int sumX = 0, sumY = 0, sumZ = 0;
    for(int i = 0; i < rows; i++){
        sumX += matrix[i][0];
        sumY += matrix[i][1];
        sumZ += matrix[i][2];
    }

    if(!sumX && !sumY && !sumZ){
        printf("YES");
    }
    else{
        printf("NO");
    }
}