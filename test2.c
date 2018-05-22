#include<stdio.h>
int main()
{
int x,n,m=1,max,min;
scanf("%d %d",&n,&x);
max=x;
min=x;
    while(m<n)
{
    scanf("%d",&x);
    if(x>max)

    max=x;
    if(x<min)
    min=x;
    m++;

}
printf("%d %d",max,min);
return 0;
}
