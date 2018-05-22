#include <stdio.h>
#include <string.h>
#define LENGHT 81
void addLint(char s1[],char s2[]);
void reverse(char s[]);
int main()
{
char intstr1[LENGHT],intstr2[LENGHT];

    scanf("%s %s",intstr1,intstr2);
    addLint(intstr1,intstr2);
    printf("%s",intstr1);

return 0;
}
void reverse(char s[])
{
    int i,j,c;
    for(i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}

void addLint(char s1[],char s2[])
{
    int i=0,tmp,c=0;
    char s[LENGHT];
    if(strlen(s1)<strlen(s2))
    {
        strcpy(s,s1);
        strcpy(s1,s2);
        strcpy(s2,s);
    }
    reverse(s1);
    reverse(s2);
    while(s2[i]!='\0')
    {
        tmp = s1[i]-'0'+ s2[i]-'0'+c;
        s1[i] = tmp%10 + '0';
        c = tmp/10;
        i++;
    }
    while(s1[i] != '\0' && c)
    {
        tmp = s1[i]-'0' + c;
        s1[i] = tmp%10 + '0';
        c = tmp/10;
        i++;
    }
    if(c)
        s1[i++] = c + '0';

    s1[i] = '\0';
    reverse(s1);
}




