#include <stdio.h>
#include <string.h>

struct person
{
    char name[20];
    char num[10];
}contact[9],tmp;

void byname(struct person contact[],int count)
{
    int i,j;
    struct person tmp;
    for( i = 0; i < count; i++)
    {
        for( j = count-1;j>i;j--)
        {
            if(strcmp(contact[j-1].name,contact[j].name)>0)
            {
                tmp=contact[j-1];
                contact[j-1]=contact[j];
                contact[j]=tmp;
            }
        }
    }
}

int main()
{
    int n,i,j;
    struct person contact[9];

    scanf("%d",&n);
    if(n <= 50)
    {
        for(i = 0; i < n; i++)
        {
            scanf("%s %s",contact[i].name,contact[i].num);
        }

        byname(contact,n);

        for(j = 0; j < n; j++)
        {
            printf("%12s%12s\n",contact[j].name,contact[j].num);
	}z`
    }
return 0;
}
