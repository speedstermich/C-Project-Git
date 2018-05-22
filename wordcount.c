#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define maxword 32
#define maxsize 1024
struct node
{
	char word[maxword];
	int count;
	struct node *link;
};

struct node *Wordlist = NULL;

int getWord(FILE *bfp, char *w);
int searchWord(struct node list[],char *w);
int insertWord(struct node list[],int pos,char *w);

int main()
{
	struct node Wordlist[maxsize];
	int i;
	char filename[maxword],word[maxword];
	FILE *bfp;
	
	scanf("%s",filename);
	if ((bfp = fopen(bname,"r") == NULL)
	{
		fprintf(stderr, "%s can't open\n",filename);
		return -1;
	}
	while(getWord(bfp,word) != EOF)
		if (searchWord(word) = -1)
		{
			fprintf(stderr, "Memory is fulln");
			return -1;
		}
	for (i = 0; i <= N-1; i++)
	{
		printf("%s %d\n",Wordlist[i].word,Wordlist[i].count);
	}
return 0;
} 