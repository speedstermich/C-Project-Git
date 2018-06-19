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
		//printf("\n");
		//printf("1= %d\n",n );
	}
	else
	{
		//printf("2 =%d\n", n);
		convert(n/10);
		//printf("3 = %d\n", n);
		putchar('0'+n%10);

	}
printf("\n");
}
