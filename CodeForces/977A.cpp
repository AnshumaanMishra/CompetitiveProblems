#include <stdio.h>
typedef long long int ll;

int main(){
    ll a, b;
    scanf("%lld %lld", &a, &b);
    for(int i = 0; i < b; i++){
        if(a % 10 == 0){
            a /= 10;
            continue;
        }
        a--;
    }
    printf("%d", a);
}