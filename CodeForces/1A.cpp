#include <stdio.h>
typedef long long int ll;
int main(){
    ll n, m, a;
    scanf("%lld %lld %lld", &m, &n, &a);
    printf("%lld\n", ((n % a != 0) ? (n / a) + 1 : (n / a)) * ((m % a != 0) ? (m / a) + 1 : (m / a)));
}