#include <stdio.h>
#include <string.h>
int main()
{
	char place[100][100],t[100];
	int i,n,j;
	scanf("%d",&n);
	if (n>=1 && n <=100)
	{	
		for (i = 0; i < n; i++)
		{
			scanf("%s",place[i]);
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 1; j < n; j++)
		{
			if(strcmp(place[j-1],place[j])>0)
			{
				strcpy(t,place[j-1]);
				strcpy(place[j-1],place[j]);
				strcpy(place[j],t);
			}	
		}
	}
for (i = 0; i < n; i++)
	{
		printf("%s",place[i]);
	}	
return 0;	
}