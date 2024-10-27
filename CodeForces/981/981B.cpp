#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t > 0){
        int n;
        cin >> n;
        int grid[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> grid[i][j];
            }
        }
        // left
        int count = 0;
        int min = 0;
        for(int i = 0; i < n; i++){
            // printf("%d, %d: %d\n", i, i, grid[i][i]);
            if(min > grid[i][i]){

                min = grid[i][i];
            }
        }

        // cout << min << endl;
        count += min;

        for(int i = 1; i < n; i++){
            min = 0;
            for(int j = 0; j < n - i; j++){
                // cout << grid[i + j][j] << endl;
                // printf("%d, %d: %d\n", j, i+j, grid[j][i+j]);

                if(min > grid[i + j][j]){
                    min = grid[i + j][j];
                }
            }
            // cout << min << endl;
            count += min;
        }
        // Down
        for(int i = 1; i < n; i++){
            min = 0;
            for(int j = 0; j < n - i; j++){
                // cout << grid[i + j][j] << endl;
                // printf("%d, %d: %d\n", i+j, j, grid[i+j][j]);
                if(min > grid[j][i + j]){
                    min = grid[j][i + j];
                }
            }
            // cout << min << endl;
            count += min;
        }
        count *= -1;
        cout << count << endl;
        t--;
    }
    return 0;
}