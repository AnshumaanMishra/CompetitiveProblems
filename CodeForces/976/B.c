#include <stdio.h>
#include <math.h>

long long int logic(long long int x);

int main(void)
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        long long int k;
        scanf("%lli", &k);

        if (k < 3)
        {
            printf("%lli\n", k + 1);
            continue;
        }
        printf("%lli\n", k + 2 + logic(k));
    }
}

long long int logic(long long int x)
{
    long long int k = (sqrt((4 * x) - 1) - 3) / 2;
    return k;
}