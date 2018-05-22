#include <stdio.h>
#include <stdlib.h>

void arrange(int *arr,int x,int y)
{
    int i;
    int tmp = arr[y];
    for(i = y; i > x; i--)
        arr[i] = arr[i-1];
    arr[x] = tmp;
}

void dearrange(int *arr,int x,int y)
{
    int i;
    int tmp = arr[x];
    for(i = x;i < y; i++)
        arr[i] = arr[i+1];
    arr[y] = tmp;
}

void perm(int *arr,int d,int N)
{
    int i;
    if (d > N)
    {
        for(i = 0; i <= N; i++)
            printf("%d ",arr[i]);
        printf("\n");
    }
    else
    {
        for(i = d; i <= N; i++)
        {
            arrange(arr,d,i);
            perm(arr,d + 1,N);
            dearrange(arr,d,i);
        }
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    int *arr = (int *)malloc(N*sizeof(int));
    int i;
    for(i = 0; i < N; i++)
        arr[i] = i+1;
    perm(arr,0,N-1);

    free(arr);
return 0;
}

