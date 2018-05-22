#include <stdio.h>
int main ()
{
    int y10,y5,y2,y1,y;
    scanf("%d",&y);
    while (y<=100)
    {
        y10=y/10; /*10yuna*/
        y5=(y%10)/5; /*5yuan*/
        y2=(y%10%5)/2; /*2yuan*/
        y1=(y%10%5%2)/1; /*1yuan*/
        printf("%d %d %d %d", y10,y5,y2,y1);
	break;
	}
return 0;
}
