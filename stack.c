#include <stdio.h>
#define M 100

void push(int num[]);
int pop();
int top = -1;
int stack[M];

int main()
{
	int a[M],i;

	for (i = 0; i < M; i++)
	{
		scanf("%d",&a[i]);
		if (a[i]== -1)
			break;
	}

	for (i = 1; i < M; i++)
	{
		if (a[i-1] == 1 && a[i] != -1 && a[i] != 0)
		{

			if(top == M-1)
			{
				printf("Stack is full\n");
			}

			stack[++top]=a[i];
		}

		if (a[i] == 0 )
		{
			pop();

		}
		if (a[i]== -1)
			break;
	}

return 0;
}


int pop()
{
	if (top == -1)
	{
		printf("error ");
	}
if(stack[top]!=0)
printf("%d ",stack[top]);
top--;
return 0;	
}
