#include<stdio.h>
#include<string.h>
typedef struct
{
   short number[384];
   int length;
} BigNumber;
void ADD(BigNumber * a,BigNumber * b,BigNumber * c)
{
   int i,aa,bb,cc=0;
   for(i=0;i<a->length||i<b->length||cc!=0;++i) {
      aa=i<a->length?a->number[i]:0;
      bb=i<b->length?b->number[i]:0;
      cc+=aa-bb;
      c->number[i]=cc%10;
      cc/=10;
   }
   c->length=i;
}
void init(BigNumber * b,char * a)
{
   int i,length=strlen(a);
   for(i=length-1;i>=0;--i) b->number[i]=a[length-i-1]-'0';
   b->length=length;
}
void print(BigNumber * a)
{
   int i=a->length==0?0:a->length-1;
   for(;i>=0;--i) printf("%d",a->number[i]);
   printf("\n");
}
int main()
{
   char tmp[125];
   BigNumber a,b,c;
   scanf("%s",tmp); init(&a,tmp);
   scanf("%s",tmp); init(&b,tmp);
   ADD(&a,&b,&c);
   print(&c);
   return 0;
}
