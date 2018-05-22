#include<iostream>
#include<cstring>
#define PERSON 3
using namespace std;
struct UserType
{
char num[10];
char name[20];
};

void Sort(UserType list[],int count)//词典排序函数
{
for(int i=0;i<count;i++)
for(int j=count-1;j>i;j--)
if(strcmp(list[j-1].name,list[j].name)>0)
{
UserType tmp;
tmp=list[j-1];
list[j-1]=list[j];
list[j]=tmp;
}
}
int main()
{
UserType list[PERSON];
cout<<"请输入用户的姓名、电话号码："<<endl;
for(int i=0;i<PERSON;i++)
{
cin>>list[i].name>>list[i].num;
}
Sort(list,PERSON);//调用词典排序函数
cout<<"姓名 电话号码"<<endl;
for(int j=0;j<PERSON;j++)
{
cout<<list[j].name<<"\t"<<list[j].num<<endl;
}
return 0;
}
