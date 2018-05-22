#include "stdio.h"
int main()
{
int d;
int i,j;
printf("输入一个正整数:");
scanf("%d",&d);
i=2;
while(d>=i)
{
j=0;
while(d%i==0)
{
j++;
d=d/i;
}
if(j!=0)
printf("%d ",i);
i=i+1;
}
}
