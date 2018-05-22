#include <stdio.h>

int main()
{
	int i = 0, j, k, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
	char *p;
	char s[100];
	
	printf("Input Character : \n");
	while((s[i] = getchar()) != '\n')
	{
		i++;
	}
	p = s;
	while(*p!=10)
	{

		if(*p>='A'&&*p<='Z')
			a++;

		else if(*p>='a'&&*p<='z')
			b++;
		
		else if(*p>='0'&&*p<='9')
			c++;

		else if(*p==' ')
			d++;

		else 
			f++;
			p++;
	}

printf("Uppercase : %d\n",a);
printf("Lowercase : %d\n",b);
printf("Number : %d\n",c);
printf("Others : %d\n",f);
printf("Space : %d\n",d);
return 0;
}