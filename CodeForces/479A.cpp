#include <stdio.h>

int getMax(int a, int b, int c, int d){
    if(a>=b && a>=c && a>=d){
        return a;
    }
    if(b>=a && b>=c && b>=d){
        return b;
    }
    if(c>=b && c>=a && c>=d){
        return c;
    }
    if(d>=b && d>=c && d>=a){
        return d;
    }
}

int main(){
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    int val1, val2, val3, val4, val5, val6;
    val1 = a*b*c;
    val2 = a*b+c;
    val3 = a+b*c;
    val4 = a+b+c;
    val5 = a*(b+c);
    val6 = (a+b)*c;
    int max = getMax(val1, val2, val3, val4);
    max = getMax(val5, val6, max, val2);
    printf("%d", max);
}