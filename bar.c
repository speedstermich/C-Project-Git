#include <stdio.h>
int main()
{
    char ch,a[50][26];
    int i,j,sample[26],index,line;

    for(i=0;i<26;i++)
    {
        sample[i]=0;
    }
    ch=getchar();
        while(ch!=EOF) //loop for read
        {
            if(('a'<=ch)&&(ch<='z'))
            {
                index=ch-'a';
                sample[index]=sample[index]+1;
            }
    	ch=getchar();
        }

    line=0;
        for(i=0;i<26;i++)
        {
            if (line<sample[i])
            line=sample[i];
        }

        for(i=0;i<line;i++) //convert to *
        {
            for(j=0;j<26;j++)
            {
                if (sample[j]>0)
                {
                    a[i][j]='*';
                    sample[j]=sample[j]-1;
                }
                else
                    a[i][j]=' ';
            }
        }

        for(i=line-1;i>=0;i--) //output
        {
            for(j=0;j<26;j++)
            {
                printf("%c",a[i][j]);
            }
            printf("\n");
        }
    printf("abcdefghijklmnopqrstuvwxyz");
return 0;
}
