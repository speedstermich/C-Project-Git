#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int op_priority(char op)
{
	enum operators {ADD = 1, SUB = 1, MUL = 2, DIV = 2};
	switch(op)
	{
		case '+': 
		return ADD;  
    	
    	case '-': 
    	return SUB;  
    	
    	case '*': 
    	return MUL;  
    	
    	case '/': 
    	return DIV;  
    	
    	default: 
    	return 0; 
	}
}

void number_reverse(char infix[], char reversenum[], int *iter_infix, int *iter_reversenum)
{
	while (infix[*iter_infix] != '\0' && !op_priority(infix[*iter_infix])  
        && infix[*iter_infix] != ')' && infix[*iter_infix] != ' ') 
    {
    	reversenum[(*iter_reversenum)++] = infix[(*iter_infix)++];
    }

    reversenum[(*iter_reversenum)++] = ' ';
    (*iter_infix)--;
}

int getnum(char reversenum[], int *iter_reversenum)  
{  
    int rst = 0;  
    while (reversenum[*iter_reversenum] != ' ')  
    {  
        rst = rst * 10 + reversenum[*iter_reversenum] - '0';  
        (*iter_reversenum)++;  
    }  
    return rst;  
}  

void infix_reverse(char infix[], char reversenum[])
{
	int len = strlen(infix);  
    char op_stack[220];  
    int iter_infix = 0, iter_reversenum = 0, iter_opstack = 0;
    for (; iter_infix < len; iter_infix++)  
    {  
        if (infix[iter_infix] == ' ') { continue; }  
        else if (infix[iter_infix] >= '0' && infix[iter_infix] <= '9') 
        {    
            number_reverse(infix, reversenum, &iter_infix, &iter_reversenum);  
        } 
        
        else if (infix[iter_infix] == '(')  
        {
            op_stack[iter_opstack++] = infix[iter_infix];  
        }  
        
        else if (op_priority(infix[iter_infix]))  
        {   
            iter_opstack--;  
            while (iter_opstack >= 0 && op_priority(op_stack[iter_opstack]) >= op_priority(infix[iter_infix]))  
            {  
                reversenum[iter_reversenum++] = op_stack[iter_opstack--];  
                reversenum[iter_reversenum++] = ' ';  
            }  
            iter_opstack++;  
            op_stack[iter_opstack++] = infix[iter_infix];  
        }   
        
        else if (infix[iter_infix] == ')')  
        {    
            iter_opstack--;  
            while (op_stack[iter_opstack] != '(')  
            {  
                reversenum[iter_reversenum++] = op_stack[iter_opstack--];  
                reversenum[iter_reversenum++] = ' ';  
            }  
        }
    }
    iter_opstack--;  
    while (op_stack[iter_opstack] != '(' && op_stack[iter_opstack] >= 0)  
    {  
        reversenum[iter_reversenum++] = op_stack[iter_opstack--];  
        reversenum[iter_reversenum++] = ' ';  
    }  
    reversenum[iter_reversenum] = '\0';  
    /*if (iter_opstack != -1)
    	printf("ERROR: leftover bracket(s)");*/   
}

struct symbol
{
	int num;
	char op;
	struct symbol *lchild, *rchild;
};

void reverse_exprtree(char reversenum[], struct symbol **exprtree)  
{  
    struct symbol *node_stack[220];  
    struct symbol *newnode;  
    int iter_reversenum = 0, iter_nstack = 0;

     while (reversenum[iter_reversenum] != '\0')  
    {  
        if (reversenum[iter_reversenum] >= '0'&& reversenum[iter_reversenum] <= '9')  
        {  
            newnode = (struct symbol *)malloc(sizeof(struct symbol));  
            newnode->num = getnum(reversenum, &iter_reversenum);  
            newnode->op = '\0';  
            newnode->lchild = NULL;  
            newnode->rchild = NULL;  
            node_stack[iter_nstack++] = newnode;  
        }

        else if (op_priority(reversenum[iter_reversenum]))  
        {  
            newnode = (struct symbol *)malloc(sizeof(struct symbol));  
            newnode->op = reversenum[iter_reversenum];  
  
            if ((--iter_nstack) >= 0) newnode->rchild = node_stack[iter_nstack];  
            else newnode->rchild = NULL;  
  
            if ((--iter_nstack) >= 0) newnode->lchild = node_stack[iter_nstack];  
            else newnode->lchild = NULL;  
  
            node_stack[iter_nstack++] = newnode;  
        }  
        iter_reversenum++;  
    }

    *exprtree = node_stack[0];
}  

int reverse_num(char reversenum[])  
{  
    int num_stack[220];  
    int iter_reversenum = 0, iter_nstack = 0;  
    int len = strlen(reversenum);  
    for (; iter_reversenum < len; iter_reversenum++)  
    {  
        if (reversenum[iter_reversenum] == ' ') { continue; }  
        else if (reversenum[iter_reversenum] >= '0' &&reversenum[iter_reversenum] <= '9')  
        {  
            num_stack[iter_nstack++] = getnum(reversenum, &iter_reversenum);  
        }  
        else  
        {  
            iter_nstack--;  
            if (reversenum[iter_reversenum] == '+')  
            {  
                num_stack[iter_nstack - 1] += num_stack[iter_nstack];  
            }  
            else if (reversenum[iter_reversenum] == '-')  
            {  
                num_stack[iter_nstack - 1] -= num_stack[iter_nstack];  
            }  
            else if (reversenum[iter_reversenum] == '*')  
            {  
                num_stack[iter_nstack - 1] *= num_stack[iter_nstack];  
            }  
            else if (reversenum[iter_reversenum] == '/')  
            {  
                if (num_stack[iter_nstack] == 0)  
                {  
                        
                    num_stack[iter_nstack - 1] = 0;  
                    continue;  
                }  
                num_stack[iter_nstack - 1] /= num_stack[iter_nstack];  
            }  
            iter_reversenum++;  
        }  
    }  
    if (iter_nstack == 1)  
        return num_stack[0];  
    else  
    {      
        return num_stack[iter_nstack - 1];  
    }  
} 

 int main()  
{  
    char infix[220], reversenum[220];  
    char tmp;  
    struct symbol *exprtree = NULL;  
    int i = 0;  
  
    while ((tmp = getchar()) != '=') infix[i++] = tmp;  
    infix[i] = '\0';  
  
    infix_reverse(infix, reversenum);  
    reverse_exprtree(reversenum, &exprtree);  
      
    tmp = exprtree->op;  
    printf("%c", tmp);  
  
    if (exprtree->lchild != NULL)  
    {  
        tmp = exprtree->lchild->op;  
        if (tmp == '\0') printf(" %d", exprtree->lchild->num);  
        else printf(" %c", tmp);  
    }  
  
    if (exprtree->rchild != NULL)  
    {  
        tmp = exprtree->rchild->op;  
        if (tmp == '\0') printf(" %d\n", exprtree->rchild->num);  
        else printf(" %c\n", tmp);  
    }  
    else printf("\n");  
  
    printf("%d", reverse_num(reversenum));  
    return 0;  
}  

//这次题我不太明白该怎么做，这个代码是我上网找的，也当成我的参考。谢谢老师的谅解