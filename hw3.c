#include <stdio.h>
int main()
{

int year,month,day,a;
int day_[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int day1_[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
day=0;

    printf("Input Year(yyyy) Month(mm) : ");
    scanf("%d %d",&year,&month);

    if ((year%4==0&&year%100!=0)||year%400==0)
    {
        printf("%d year is Leap Year",year);
    }
    else
    {
        printf("%d year is not Leap Year",year);
    }

    if ((year%4==0&&year%100!=0)||year%400==0)
    {
        for(a=1;a <=month;++a)
        {
            if (a==2)
            {
                day = day1_[a];
            }
            else
            {
                day = day_[a];
            }
        }
    }
    else
    {
        for(a=1;a <= month;++a)
        {
            day = day_[a];
        }
    }
    printf("\n%d days",day);

    if (month==1||month<=3)
    {
    printf("\n%d month of %d is spring", month,year);
    }
    else if (month==4||month<=6)
    {
    printf("\n%d month of %d is summer", month,year);
    }
    else if (month==7||month<=9)
    {
    printf("\n%d month of %d is autumn", month,year);
    }
    else if (month==10||month<=12)
    {
    printf("\n%d month of %d is winter", month,year);
    }
return 0;
}
