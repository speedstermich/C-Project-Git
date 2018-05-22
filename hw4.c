#include <stdio.h>
#include <math.h>
int main()
{
double a,b,c,d,x1,x2,real,imaginary;

printf("a= b= c=  \n ");
scanf("%lf %lf %lf",&a,&b,&c);

d = b*b-4*a*c;
    if (d>0)
    {
        x1 = (-b+sqrt(d))/(2*a);
        x1 = (-b-sqrt(d))/(2*a);

        printf("X1 = %.2lf , X2 = %.2lf",x1,x2);
    }
    else if (d==0)
    {
        x1 = x2 = -b/(2*a);
        printf("X1 = X2 = %.2lf",x1);
    }

    else
    {
        real= -b/(2*a);
        imaginary = sqrt(-d)/(2*a);
        printf("X1 = %.2lf + %.2lfi , X2 = %.2lf - %.2lfi",real,imaginary,real,imaginary);
    }
return 0;
}
