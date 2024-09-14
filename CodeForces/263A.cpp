#include <stdio.h>

int main(){
    int rows = 5, columns = 5;
    int temp;
    int xC, yC;
    for(int y = 0; y < rows; y++){
        for(int x = 0; x < columns; x++){
            scanf("%d", &temp);
            if(temp == 1){
                xC = x + 1;
                yC = y + 1;
            }
        }
    }
    int xDiff = ((xC - 3) > 0) ? (xC - 3) : (3 - xC);
    int yDiff = ((yC - 3) > 0) ? (yC - 3) : (3 - yC);
    printf("%d", xDiff + yDiff);

}