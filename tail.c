#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFINES 10
#define MAXLEN 81

struct tail
 {
 	char *line;
 	struct tail *link;
 };

 int main(int argc, char  *argv[])
 {
 	char curline[MAXLEN], *filename;
 	int n = DEFINES;
 	int i;
 	struct tail *list, *ptr;
 	FILE *fp;

 	if(argc == 3 && argv[1][0] == '-')
 	{
 		n = atoi(argv[1]+1);
 		filename = argv[2]; 
 	}
 	else if(argc == 2)
 	{
 		filename = argv[1];
 	}
 	else
 	{
 		printf("Usage : tail [-n] filename \n");
		return(1);
 	}

 	if((fp = fopen(filename,"r")) == NULL)
 	{
 		printf("can't open file: %s !\n",filename);
 		return(-1);
 	}

 	list = ptr = (struct tail *)malloc(sizeof(struct tail));
 	ptr -> line = NULL;
 	for (i = 1; i < n; i++)
 	  {
 	  	ptr -> link = (struct tail *)malloc(sizeof(struct tail));
 	  	ptr = ptr -> link;
 	  	ptr -> line = NULL;
 	  }
 	ptr -> link = list;

 	ptr = list;
 	while(fgets(curline, MAXLEN, fp) != NULL)
 	{
 		if(ptr -> line != NULL)
 			free(ptr->line);
 		ptr->line = (char *)malloc(strlen(curline)+1);
 		strcpy(ptr->line,curline);
 		ptr=ptr->link;
 	}
 	for (i = 0; i < n; i++)
 	{
 		if (ptr -> line != NULL)
 		{
 			printf("%s",ptr -> line);
 			ptr = ptr -> link;
 		}
 	}

 	fclose(fp);
 	return 0;
 }
