#include <stdio.h>
int main ()
{
    int a,year,month,date,days;
    int days_[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    days = 0;
    scanf("%d %d %d",&year,&month,&date);
        if( (year%4 == 0 && year%100 != 0) || year%400==0)
        {
            for(a=1;a < month;++a)
                if(a==2)
                 {
                    days += days_[a]+1; //leap year
                 }
        else
                 {
                    days += days_[a];
                 }

        }
        else
                {
            for(a=1;a < month;++a)
                    {
                    days += days_[a];
                    }
                }
                    days += date;

             printf("%d \n",days);

return 0;
}
