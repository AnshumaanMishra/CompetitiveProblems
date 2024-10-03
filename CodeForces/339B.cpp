#include <stdio.h>
typedef long long int ll;

int main(){
    ll n, m;
    scanf("%lld %lld", &n, &m);
    ll array[m];
    for(int i = 0; i < m; i++){
        scanf("%lld", &array[i]);
    }

    ll location = 1;
    ll time = 0;
    for(int i = 0; i < m; i++){

        printf("i = %2d, time = time(%4lld) + location(%3lld) - target(%3lld)\n", i, time, location, array[i]);
        if(array[i] >= location){
            time += array[i] - location;
            location = array[i];
        }
        else{
            time += n + array[i] - location;
            location = array[i];
        }
    }
    printf("%lld", time);
}