#include <stdio.h>
int main()
{
int n=1;
double a,b,c,e,PI;
scanf("%lf",&e);
a=1,b=1,c=0,PI=1;
do{
n++;
a=a*(n-1);
b=b*(2*n-1);
c=a/b;
PI=PI+c;
}while(c>=e/2||n<2);
printf("%d %.7lf",n,2*PI);
return 0;
}
