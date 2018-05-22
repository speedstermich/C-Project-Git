#include <stdio.h>
int main()
{
    int A[10][10];
    int row,col,k,n;
    char ch;

    scanf("%d",&n);
    for (row=0;row<n;row++)
    for (col=0;col<n;col++)
        scanf("%d",&A[row][col]);

        while(1)
       {
        ch=getchar();
        ch=getchar();

            if (ch=='#')
            {
                for(row=0;row<n;row++)
                {
                for(col=0;col<n;col++)
                printf("%5d",A[row][col]);
                printf("\n");
                }
            return 0;
            }

        for(row=0;row<n;row++)
        for(col=0;col<n;col++)
        {
        scanf("%d",&k);
        if(ch=='+')
            A[row][col]+=k;
        else
            A[row][col]-=k;
        }
        }
}
