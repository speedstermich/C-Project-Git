#include <stdio.h>

int main()
{
	int a[]={7,1,-1,8,6};
	int *p,i,j,t,n;
	p=a;
	/*scanf ("%d",&n);*/
	
	/*for (i=0;i<n;i++)	
	{
		scanf("%d",*(p+i));
	}*/
	
	for (p=a; i < 5; i++)
	{
		for (j = i+1; j < 5; j++)		
		{
				if (a[i]>a[j])
				{
					t = a[i];
					a[i]=a[j];
					a[j]=t;
				}
		}
	}
	for (p; p < (a+5); p++)
	{
		printf("%d",*p);
	}
return 0;	
}