#include <stdio.h>
#include <stdlib.h>

struct student
{
	int number;
	char name[50];
	float score[3];
	float avg;
};

int main()
{
	void in(student stu[]);
	void print(student stu[]);
	printf("INPUT DATA \n");
	student stu[5]	;
	in(stu);
	print(stu);
	return 0;
}

void in(student stu[])
{
	int i,k;
	for (i = 0; i < 5; ++i)
	{
		printf("Input student ID   : ");
		scanf("%d",&stu[i].number);

		printf("Input Name         : ");
		scanf("%s",stu[i].name);
	
		for (k = 0; k < 3; ++k)
		{
			printf("Input score %d      : ",k+1);
			scanf("%f",&stu[i].score[k]);
		}

		stu[i].avg = (stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0;
		printf("\n");
	}
}

void print(student stu[])
{
	int i;
	for (i = 0; i < 5; ++i)
	{
		
		printf("ID      : %d\n",stu[i].number);
		printf("Name    : %s\n",stu[i].name);
		printf("Score 1 : %4.2f\n",stu[i].score[0]);
		printf("Score 2 : %4.2f\n",stu[i].score[1]);
		printf("Score 3 : %4.2f\n",stu[i].score[2]);
		printf("\n");
		printf("average Score  : %4.2f\n",stu[i].avg);
		printf("\n");
	}

}