#include <stdio.h>

void transpose(int matrix[][3]);
int main()
{
	int i,j,t;
	int a[3][3];

	printf("input number:");
	
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		scanf("%d",&a[i][j]);	

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		printf("%d\t",a[i][j]);
		printf("\n");
	}
	
	transpose(a);
	printf("\nTtranspose:\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		printf("%d\t",a[i][j] );
		printf("\n");
	}
	return 0;
}

void transpose(int matrix[][3])
{
	int i,j,tmp;
	for (i = 0; i < 3; i++)
	{
		for (j = i+1; j < 3; j++)
		{
			tmp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = tmp;
		}
	}
}