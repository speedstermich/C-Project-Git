#include <stdio.h>
#include <string.h>
int z[101];

int judge(char x[],char y[])
{
    int i;
    if(strlen(x)<strlen(y))
        return 0;
    if(strlen(x)>strlen(y))
        return 1;

    for(i=0;i<strlen(x);i++)
        if(x[i]<y[i])
            return 0;
    return 1;
}

void minus(char x[],char y[])
{
    int i,j;
    char k;
    for(i=0,j=strlen(x)-1;i<j;i++,j--)
    {
        k = x[i];
        x[i] = x[j];
        x[j] = k;
    }
    for(i=0,j=strlen(y)-1; i<j; i++,j--)
    {
        k = y[i];
        y[i] = y[j];
        y[j] = k;
    }
    for(i=0;i<strlen(x); i++)
    {
        if(i>=strlen(y))
            z[i] = x[i]-'0';
        else
            z[i] = x[i]-y[i];
    }
    for(i=0; i<strlen(x)-1; i++)
        if(z[i]<0)
        {
            z[i]+=10;
            z[i+1]-=1;
        }
}

int main()
{
int i,j,s=0,l;
char x[100],y[100];

    memset(z,0,sizeof(z));
    gets(x);
    gets(y);
    while(x[s]=='0')
        s++;
        l=strlen(x)-s;

    for(i=0;i<=l;i++)
        x[i]=x[i+s];
        s=0;
    while(y[s]=='0')
        s++;
        l=strlen(y)-s;
    for(j=0;j<=l;j++)
        y[j]=y[j+s];
    if(judge(x,y))
        minus(x,y);
    else
    {
        printf("-");
        minus(y,x);
    }
    i=100;
    while(z[i]==0&&i!=0)
        i--;
    for(j=i;j>=0;j--)
        printf("%d",z[i]);
}
