#include <stdio.h>
#include <stdlib.h>

struct charpointer
{
	int count;
	unsigned int code;
	struct charpointer *lchild, *rchild, *next;
};

struct charpointer charnodes[128];

void insert(struct charpointer *newnode)
{
	struct charpointer *p = charnodes;  
    while (p->next->count <= newnode->count)   
    {  
        if(p->next->next!=NULL)  
            p = p->next;  
        else  
        {  
            p->next->next = newnode;  
            p = NULL;  
            break;  
        }  
    } 
    if (p != NULL)
     {
     	newnode -> next = p -> next;
     	p->next = newnode;   
     } 
}

struct charpointer *create(struct charpointer *node1) 
{
	struct charpointer *node2 = node1 -> next;  
    if (node2 != NULL)  
    {  
        struct charpointer *newnode = (struct charpointer *)malloc(sizeof(struct charpointer));  
        newnode->count = node1->count + node2->count;  
        newnode->code = 0;  
        newnode->lchild = node1;  
        newnode->rchild = node2;  
        newnode->next = NULL;  
		
		insert(newnode);
		return create(node2 -> next);
	}
	else
	{
		return node1;
	}
}

void link(struct charpointer *root)
{  
    int min = 0x3f3f3f3f;
    struct charpointer *p = NULL;   
    int i = 0;

    for (; i < 128; i++)  
    {  
        if (charnodes[i].count != 0 && charnodes[i].next == NULL && (charnodes + i) != root)
        {
        	if (charnodes[i].count < min)  
            {  
                p = &charnodes[i];  
                min = charnodes[i].count;  
            }  
            else if (charnodes[i].count == min)  
            {
            	if ( &charnodes[i] <= p)  
                {  
                    p = &charnodes[i];  
                }  
            }
        } 
    }
    root->next = p;  
    if (p != NULL)  
        link(p);  
}

void write(struct charpointer *root, int depth)  
{ 
    if (root != NULL)  
    {  
        int f_left = 1, f_right = 1;  
        if (root->lchild != NULL)  
        {  
            root->lchild->code |= (root->code) << 1;  
            f_left = 0;  
        }  
        if (root->rchild != NULL)  
        {  
            root->rchild->code |= ((root->code) << 1)|1;  
            f_right = 0;  
        }  
        if (f_left&&f_right)  
        { 
            root->code &= (1 << 16) - 1;  
            root->code |= depth << 16;  
        }  
        write(root->lchild, depth+1);  
        write(root->rchild, depth+1);  
    }  
}  

int main()  
{  
    FILE *fin, *fout;  
    
    fin = fopen("input.txt", "r");  
    if (fin == NULL) 
    	exit(1);  
    
    fout = fopen("output.txt", "w");  
    if (fout == NULL) 
    	exit(1);

    char probe;  
    struct charpointer *HFT;  
    int i = 0;  
    
    for (i = 0; i < 128; i++)  
    {  
        charnodes[i].count = 0;  
        charnodes[i].code = 0;  
        charnodes[i].next = NULL;  
    }  
    while ((probe = fgetc(fin)) != EOF)  
    {  
        if (probe != '\n')  
        {  
            charnodes[probe].count++;  
        }  
    }  
    charnodes[0].count = 1;  
    link(charnodes);  
    HFT = create(charnodes);  
    write(HFT, 0);  
  
    rewind(fin); 

    char writein = 0;  
    int bits = 0, depth = 0;  
    for (;;)  
    {
    	probe = fgetc(fin);  
        if (probe != EOF && probe != '\n')  
        { 
        	depth = (charnodes[probe].code) >> 16;
        	for (i = depth - 1; i >= 0; i--)  
            {//count bits  
                char code = ((charnodes[probe].code) & (1 << i)) >> i;  
                writein |= code << (7 - bits);  
                bits++;  
                if (bits == 8)  
                {  
                    fputc(writein, fout);  
                    printf("%hhx", writein);  
                    bits = 0;  
                    writein = 0;  
                }  
            }  
        }
        else if (probe == EOF)
        {
        	depth = (charnodes[0].code) >> 16;  
            for (i = depth - 1; i >= 0; i--)  
            {  
                char code = ((charnodes[0].code) & (1 << i)) >> i;  
                writein |= code << (7 - bits);  
                bits++;  
                
                if (bits == 8)  
                {  
                    fputc(writein, fout);  
                    printf("%hhx", writein);  
                    bits = 0;  
                    writein = 0;  
                }  
            }  
            
            if (bits != 0)  
            {  
                printf("%hhx", writein);  
                fputc(writein, fout);  
            }  
            break;  
        } 
    }

    fclose(fin);
    fclose(fout);
    return 0;
 }  

//这次题我不太明白该怎么做，这个代码是我上网找的，也当成我的参考。谢谢老师的谅解