#include <stdio.h>
int main()
{
    int A[50] = {0}; //B set
    int B[50] = {0}; //A set
    int m = 0, n = 0, a = 0, b, x, y;

        while (m < 50 && a == 0)
        {
            scanf("%d",&A[m]);
            if(A[m]==-1)
            a++;
            m++;
        }
        a=0;

        while (n<50&&a==0)
        {
            scanf("%d",&B[n]);
            if(B[n]==-1)
            a++;
            n++;
        }

        for(x=0;x<m-1;x++)
        {
            for(b=0,y=0;y<n-1;y++)
            {
                if(A[x]!=B[y])
                b++;
                if(b==n-1)
                printf("%d ",A[x]);
            }
        }
return 0;
}
