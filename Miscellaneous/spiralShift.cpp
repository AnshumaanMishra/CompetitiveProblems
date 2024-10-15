#include <bits/stdc++.h>
#include <cmath>
using namespace std;

void printArray(int n, int* array[]){
    
}

int main(){
    int dim = 3;
    int array[dim][dim];
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            array[i][j] = dim * i + j + 1;
        }
    }


    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            if(array[i][j] < 10){
                cout << 0;
            }
            cout <<  array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int innerx = dim / 2;
    int innery = dim / 2 - !(dim % 2);
    // cout << innerx << " " << innery << endl;
    int innermost = array[innerx][innery];

    int x = innerx;
    int y = innery;
    int ydir;
    int xdir;
    int i;
    
    int steps = 1;
    while(x > 0 || y > 0){
        
        i = 0;

        if(steps % 2 != 0 && dim % 2 == 0){
            xdir = 0;
            ydir = 1;
        }
        else if(steps % 2 == 0 && dim % 2 == 0){
            xdir = 0;
            ydir = -1;
        }
        else if(steps % 2 != 0 && dim % 2 != 0){
            xdir = 0;
            ydir = -1;
        }
        else if(steps % 2 == 0 && dim % 2 != 0){
            xdir = 0;
            ydir = 1;
        } 


        while(i < steps){
            if(x == 0 && y == 0){
                break;
            }
            // cout << "x = " << x << ", " << "y = " << y << endl;
            // cout << array[x][y] << " " << array[x + xdir][y + ydir] << endl;
            // cout << xdir << " " << ydir << endl;
            array[x][y] = array[x + xdir][y + ydir];
            x += xdir;
            y += ydir;
            i++;
        }

        if(steps % 2 != 0 && dim % 2 == 0){
            xdir = -1;
            ydir = 0;
        }
        else if(steps % 2 == 0 && dim % 2 == 0){
            xdir = 1;
            ydir = 0;
        }
        else if(steps % 2 != 0 && dim % 2 != 0){
            xdir = 1;
            ydir = 0;
        }
        else if(steps % 2 == 0 && dim % 2 != 0){
            xdir = -1;
            ydir = 0;
        } 
        if(x + xdir < 0 || y + ydir < 0 || x < 0 || y < 0 || (x == 0 && y == 0)){
            break;
        }
        i = 0;
        while(i < steps){
            // cout << "x = " << x << ", " << "y = " << y << endl;
            // cout << array[x][y] << " " << array[x + xdir][y + ydir] << endl; 
            // cout << xdir << " " << ydir << endl;
            array[x][y] = array[x + xdir][y + ydir];
            x += xdir;
            y += ydir;
            i++;
        }


        
        steps++;

    }
    array[0][0] = innermost;


    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            if(array[i][j] < 10){
                cout << 0;
            }
            cout <<  array[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}