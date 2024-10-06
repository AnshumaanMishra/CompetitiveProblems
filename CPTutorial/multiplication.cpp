#include <bits/stdc++.h>
#define int long long int
// #define d lld
using namespace std;


int efficientExponentian(int a, int b, int mod){
    int product = 0;
    int i = 0;
    while(b > 0){
        int currentBit = (b & 1);
        if(currentBit){
            product += a;
            product %= mod;
        }
        a += a;
        a %= mod;
        // printf("Multiplication\n");
        // printf("Product = %d\n", product);

        b = b >> 1;
        i++;
    }
    return product;
}

int32_t main(){
    int a = 2;
    int b = 100;

    cout << efficientExponentian(a, b, 11) << endl;
}