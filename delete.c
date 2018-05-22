#include<stdio.h>
#include<string.h>

int main()
{
    char num[245];
    int i,j,s,k,n;
    scanf("%s",num);
    scanf("%d",&s);
    n=strlen(num);

    for(i=1;i<=s;i++) //delete "s" order
        {
        for(j=0;j<=n-1;j++) //from head to tail scan
            {
            if(num[j]>num[j+1])
             {
             for(k=j;k<=n;k++)
                num[k]=num[k+1];
             break;
             }
            }
        }
    printf("%s",num);
return 0;
}
