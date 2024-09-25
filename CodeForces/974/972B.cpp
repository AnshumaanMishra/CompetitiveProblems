#include <stdio.h>
#include <cmath>
typedef long long int ll;

int main(){
    ll t;
    scanf("%d", &t);
    for(ll i = 0; i < t; i++){
        ll n, k;
        scanf("%d %d", &n, &k);
        if(n % 2 == 0 && k % 2 == 0){//Even Left
            if((k/2)%2==0){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
        else if(n % 2 == 0 && k % 2 != 0){//Odd left
            if((k/2)%2==0){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
        else if(n % 2 != 0 && k % 2 == 0){//Even Left
            if((k/2)%2==0){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
        else if(n % 2 != 0 && k % 2 != 0){//Odd left
            if((k/2)%2==0){
                printf("NO\n");
            }
            else{
                printf("YES\n");
            }
        }
    }
    return 0;
}