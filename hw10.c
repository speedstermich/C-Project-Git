#include <stdio.h>

void convert(int  n);
int main()
{
	int num;

	printf("Input Number :");
	scanf("%d",&num);
	
	convert(num);

	return 0;
}

void convert(int n)
{
	if (n/10==0)
	{
		putchar('0'+n%10);
	}
	else
	{
		convert(n/10);
		putchar('0'+n%10);
		
	}
printf("\n");
}