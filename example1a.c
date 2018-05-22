#include<stdio.h>
int main()
{
    int n = 1;
    double e,a,b,c,PI;
    a = 1,b = 1,c = 0,PI = 1;
    scanf("%lf",&e);

    do
    {
        n++;
        b = b*(2*n-1);
        a = a*(n-1);
        c = a/b;
        PI = PI+c;
    }
    while(c >= e/2 || n < 2);

    printf("%d %.7lf\n",(int)n,PI*2);
return 0;
}
