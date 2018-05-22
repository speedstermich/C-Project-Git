#include <stdio.h>
int main()
{
    float n, m, high=0, sum=0, sum1, high1;
    int i;
    scanf("%f %f",&n,&m);
        sum1 = n;
        high1 = n/4;
        sum = sum1;
        high = high1;
    for(i=; i <= m; i++)
    {
        sum = sum  + 2*high;
        high = high/4;
    }
    printf("%.2f\n",sum);
    printf("%.2f",high);
return 0;
}
