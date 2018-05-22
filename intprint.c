#include <stdio.h>
int main()
{
	unsigned int val,rev=0,rem;
	int temp ,count = 0;
	scanf("%d",&val);
    temp = val;
    while(temp != 0)   //count
    {

        temp = temp /10;
        ++count;
	}
        printf("%d\n", count);
        printf("%d\n",val);
	while(val != 0)   //reverse
    {
        rem = val%10;
        rev = rev*10 + rem;
        val /= 10;
    }

        printf("%d", rev);
return 0;
}


