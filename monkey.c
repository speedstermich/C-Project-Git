#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef int ElemType; 

void count(int n,int m,int q);

typedef struct node
{
	ElemType data;
	struct node *link;
}LNode, *LinkList;



int main()
{
	int n,m,q;
	scanf("%d %d %d" ,&n,&m,&q);
	count(n, m, q);
	
	return 0;
}

void count(int n,int m,int q)
{
	LinkList p, r, list = NULL;
	int i;
	for ( i = 1; i <=  n; i++)
	{
		p  = (LinkList)malloc(sizeof(LNode));
		p -> data = i;
		if(list == NULL)
			list = p;
		else
			r->link = p;
		r = p;
	}

	p->link = list;
	p = list;

	for (i = 1; i < q; i++)
	{
		r = p;
		p = p->link;
	}

	while(p->link != p)
	{
		for (i = 1; i < m; i++)
		{
			r = p;
			p = p->link;
		}

		r->link = p->link;
		//printf("%3d\n",p->data);
		free(p);
		p = r->link;
	}
	printf("%d",p->data);
}

	