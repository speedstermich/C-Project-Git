#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    freopen("fcopy.in","r",stdin);
    freopen("fcopy.out","w",stdout);
    char s,s1;
    s=getchar();

    while (s!=EOF)
    {
        if ((s==' ')||(s=='\t'))
        {
        if ((s1!=' ')&&(s1!='\t'))
            printf(" ");
        }
        else
            printf("%c",s);
            s1=s;
            s=getchar();
    }
exit(0);
}
