#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node* head;
void insert(int x);
void Delete(int n);
void print();

int main()
{
	head = NULL;
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	print();
	int n;
	printf("Input Position\n");
	scanf("%d",&n);
	Delete(n);
	print();
return 0;
}

void Delete(int n)
{
	struct node* temp1 = head;
	if(n == 1)
	{
		head = temp1->next;
		free(temp1);
		return;
	}
	int i;
	for (int i = 0; i < n-2; ++i)
		temp1 = temp1 -> next;

	struct node* temp2 = temp1->next;
	temp1->next = temp2->next;
	free(temp2); 
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