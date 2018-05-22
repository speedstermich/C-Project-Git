#include <stdio.h>
int main()
{
    int num;
    int i;
    scanf("%d",&num);
    i=2;
    while(num>=i)
        {
            while(num%i==0)
            {
            printf("%d ",i);
            num=num/i;
            }
            i=i+1;
        }
return 0;
}
