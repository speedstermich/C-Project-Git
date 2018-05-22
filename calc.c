#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXZISE 100
struct operatorStruct
{
        char name;
        int priority;
        int opnum;

};
typedef struct operatorStruct OPERATOR;
OPERATOR opStack[MAXZISE];
int FTop=-1;
int numStack[MAXZISE];
int NTop=-1;
int getPriority(char name)
{
    if (name=='('||name==')')
    {
        return 0;
    }
    if (name=='*'||name=='/')
    {
        return 2;
    }
    if (name=='+'||name=='-')
    {
        return 1;
    }
}
int getOpNum(char name)
{
    if (name=='*'||name=='/'||name=='+'||name=='-')
    {
        return 2;
    }
    if (name=='('||name==')')
    {
        return 0;
    }
}
void pushOp(OPERATOR op)
{
    if (FTop<MAXZISE-1)
    {
        opStack[++FTop] = op;
    }
}
OPERATOR popOp()//operator exit stack
{
    if (FTop>= 0){
        return opStack[FTop--];
    }
}
void pushNum(int num)
{
    if (NTop<MAXZISE-1){
        numStack[++NTop] = num;
    }
}
int popNum()//number exit stack
{
    if (NTop >= 0){
        return numStack[NTop--];
    }
}
int change(char *s, int *i)
{ 
    int j = 0;
    char numstr[MAXZISE];
    while ((*s) >= '0' && *s <= '9')
    {
        numstr[j++] = (*s);
        s++;
    }
    (*i) = (*i) + j;
    numstr[j] = '\0';
    return atoi(numstr);
}
int opertateNum(OPERATOR op)
{
    int num2=popNum();
    int num1=popNum();
    if (op.name=='+')
    {
        return num1 + num2;
    }
    if (op.name=='-')
    {
        return num1 - num2;
    }
    if (op.name=='*')
    {
        return num1 * num2;
    }
    if (op.name=='/')
    {
        return num1 / num2;
    }
}
int main()
{
    char S[MAXZISE];
    int i,j;
    OPERATOR op, topOp;
    topOp.name = '#';
    topOp.priority = 0;
    topOp.opnum = 0;
    pushOp(topOp);
    scanf("%s", S);
    for(i=0;i<strlen(S);i++)
    {
     if(S[i]!=' ') 
        S[j++]=S[i]; 
    }
    S[j]='\0'; 
    
    for (i = 0; S[i] != '\0' && S[i] != '=';)
    {
        if (S[i] >= '0' && S[i] <= '9')
        {
            pushNum(change(&S[i], &i));
        }
        else{
            op.name = S[i];
            op.priority = getPriority(S[i]);
            op.opnum = getOpNum(S[i]);
            topOp = popOp();
            if (op.name == '(')
            {
                pushOp(topOp);
                pushOp(op);
            }
            else if (op.name == ')')
            {
                while (topOp.name != '(')
                {
                    pushNum(opertateNum(topOp));
                    topOp = popOp();
                }
            }
            else{
                if (topOp.name !='#'&& op.priority<= topOp.priority)
                {
                    pushNum(opertateNum(topOp));
                }
                else
                {
                    
                    pushOp(topOp);
                }
                pushOp(op);
            }
            i++;
        }
    }
    while ((topOp = popOp()).name!='#')
    {
        pushNum(opertateNum(topOp));
    }
    printf("%d\n", popNum());
    return 0;
}