/*calculator.c 张金原*/
#include <stdio.h>
int main ()
{
    int data1,data2;
    char op;
    scanf("%d %d %c",&data1 , &data2 , &op);
    if (op == '+')                            /*plus*/
    {
        int res = data1 + data2;
        printf("%d", res);
    }
    else if (op == '-')                       /*minus*/
    {
        int res = data1 - data2;
        printf("%d", res);
    }
    else if (op == '*')                       /*multi*/
    {
        int res = data1 * data2;
        printf("%d", res);
    }
    else while (op == '/')                    /*divide*/
    {
        float res = (float) data1 / data2;
        if (data1 % data2 != 0) {
        printf("%.2f", res);
    }
    else
    {
        printf("%.0f", res);
    }
    break;
}
return 0;
}
