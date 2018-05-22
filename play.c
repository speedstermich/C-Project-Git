#include<stdio.h>  
#include<string.h>  
char a[5][5];  
char s1[25],s2[25];  
int l;  
bool judge(char ch)//判断该字符是否在密钥字符串中  
{  
    int sum=0;  
    for(int i=0; i<l; i++)  
    {  
        if(ch!=s1[i])  
            sum++;  
    }  
    if(sum==l)  
        return 1;  
    return 0;  
}  
bool judge2(char ch)//判断该字符是否在密钥矩阵中  
{  
    int i,j;
    int sum=0;  
    for(i=0; i<5; i++)  
    {  
        for(j=0; j<5; j++)  
        {  
            if(ch!=a[i][j])  
                sum++;  
        }  
    }  
    if(sum==25)  
        return 1;  
    return 0;  
}  
void posi(char ch,int &x,int &y)//该字符在密钥矩阵中对应的坐标  
{  
    int i,j;
    for(i=0; i<5; i++)  
    {  
        for(j=0; j<5; j++)  
        {  
            if(a[i][j]==ch)  
            {  
                x=i;  
                y=j;  
            }  
        }  
    }  
}  
bool posijudge(char c1,char c2)//判断两字符是否在同一行或同一列  
{  
    int x1,x2,y1,y2;  
    posi(c1,x1,y1);  
    posi(c2,x2,y2);  
    if(x1==x2||y1==y2)  
        return 1;  
    return 0;  
}  
int main()  
{  
    int i,j;
    scanf("%s%s",s1,s2);  
    l=strlen(s1);  
    int pos=0;  
    char ch='a';  
    for(int i=0; i<5; i++)//将密钥字符串变为密钥矩阵  
    {  
        for(j=0; j<5; j++)  
        {  
            if(s1[pos]!='\0')  
            {  
                a[i][j]=s1[pos];  
                pos++;  
            }  
            else  
            {  
                while(!judge(ch))  
                {  
                    ch++;  
                }  
                a[i][j]=ch;  
                ch++;  
            }  
        }  
    }  
    int n=strlen(s2);  
    char t1,t2;  
    char ans[25];  
    for(i=0; i<n; i+=2)  
    {  
        t1=s2[i];  
        t2=s2[i+1];  
        if(t1==t2||t2=='\0')//情况1、2(对应规定1、2)  
        {  
            ans[i]=t1;  
            ans[i+1]=t2;  
        }  
        else if(judge2(t1)||judge2(t2))//情况3(对应规定3)  
        {  
            ans[i]=t1;  
            ans[i+1]=t2;  
        }  
        else if(posijudge(t1,t2))//情况4(对应规定4)  
        {  
            ans[i]=t2;  
            ans[i+1]=t1;  
        }  
        else//其它正常情况  
        {  
            int x1,x2,y1,y2;  
            posi(t1,x1,y1);  
            posi(t2,x2,y2);  
            ans[i]=a[x1][y2];  
            ans[i+1]=a[x2][y1];  
        }  
    }  
    printf("%s\n",ans);  
    return 0;  
}  