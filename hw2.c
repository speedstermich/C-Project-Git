#include<stdio.h>
#include<string.h>
#define maxword 30
typedef struct node
{
 char danzi[20];
 int count;
}info;

int main()
{
   int total=0,i,j;
   FILE*fp;
   char temp[20];
   char filename[maxword];
   info infototal[1000]={"\0",0};
   
   scanf("%s",filename);
   fp = fopen(filename,"r");
   
   while(!feof(fp))
   {
      fscanf(fp,"%s",temp);
        total++;
        for(i=0;i<total;++i)
      
      if(strcmp(infototal[i].danzi,temp)==0)
      {
        infototal[i].count++;
        total--;
        break;
      }
      
      if(i>=total)
      {
        strcpy(infototal[total-1].danzi,temp);
        infototal[total-1].count++;
      }
   }
      for(i=0;i<total;i++)
      {
        printf("%s   ",infototal[i].danzi);
        for(j=0;j<infototal[i].count;++j)
        printf("j");
    printf("\n");
   }
   
}