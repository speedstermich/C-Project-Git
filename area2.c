#include <stdio.h>
#include <math.h>

int main()
{
    int x1,y1,x2,y2,x3,y3,x4,y4;
    int max_ax,min_ax,max_bx,min_bx,max_ay,min_ay,max_by,min_by;
    int Max,Min,overlap;
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    scanf("%d %d %d %d",&x3,&y3,&x4,&y4);
        if((x1>=0 || x2>=0 || y1>=0 || y2>=0 || x3>=0 || x4>=0 || y3>=0 || y4>=0) &&
        (x1<=1000 || x2<=1000 || y1<=1000 || y2<=1000 || x3<=1000 || x4<=1000 || y3<=1000 || y4<=1000) )
{
max_ax = (x1>x2) ? x1 : x2;
min_ax = (x1<x2) ? x1 : x2;
max_bx = (x3>x4) ? x3 : x4;
min_bx = (x3<x4) ? x3 : x4;
max_ay = (y1>y2) ? y1 : y2;
min_ay = (y1<y2) ? y1 : y2;
max_by = (y3>y4) ? y3 : y4;
min_by = (y3<y4) ? y3 : y4;
}
Min= (max_ax<max_bx) ? max_ax : max_bx;
Max= (min_ax>min_bx) ? min_ax : min_bx;
overlap = Min-Max;

printf("%d",overlap);
return 0;
}
