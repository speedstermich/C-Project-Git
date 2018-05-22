#include <stdio.h>
int main()
{
    int num[100],n,i,max,min;
    scanf("%d",&n);
    for (i=0; i<n; i++)
        scanf("%d",&num[i]);

        max = num[0];
    for(i=0; i<n; i++) {
        if(max < num[i])
            max = num[i];
    }
    printf("%d",max);

        min = num[0];
    for(i=0;i<n;i++) {
        if(min > num[i])
            min = num[i];
    }
    printf(" %d",min);
return 0;
}
