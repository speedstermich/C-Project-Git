#include<stdio.h>
#include<string.h>

int main()
{
	char str1[50],str2[50];
	int i,j;

	//for (i = 0; i < 5; i++)
	//{
	scanf("%s",str1);
		
	//}
	//for (i = 0; i < 5; i++)
	//printf("%s",str1);
	
	//for (j = 0; j < 50 ; j++)
	
	scanf("%s",str2);
		
	//}
	//strcpy(str1,"Welcome To");
	//strcpy(str2," Beihang");
	
	strcat(str1,str2);
	
	printf("%s",str1);
	return 0;
}