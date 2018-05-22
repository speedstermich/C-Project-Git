#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};
struct node* head;
void insert(int x);
void print();
int main()
{
	int n,i,x;
	head = NULL;
	printf("How many numbers\n");
	scanf("%d",&n);

	for (i = 0; i < n; i++)
	{
		printf("Enter Number \n");
		scanf("%d",&x);
		insert(x);
		print();
	}
}

void insert(int x)
{
	node* temp = (node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = head;
	head = temp;
	/*if (head != NULL)
	{
		temp -> next = head;
		head = temp;
	}*/
}

void print()
{
	struct node* temp = head;
	while(temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}