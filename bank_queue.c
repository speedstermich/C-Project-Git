#include <stdio.h>  
#include <stdlib.h>  
  
struct customer  
{  
    int num_seq;  
    int len_wait;  
    struct customer *next;  
};  
struct customer *cust_queue_front = NULL, *cust_queue_rear = NULL;  
int num_window = 3;  
int lenlist[1000];  
  
void enqueue(int seq)  
{  
    struct customer *new_rear = (struct customer *)malloc(sizeof(struct customer));  
    new_rear->len_wait = 0;  
    new_rear->num_seq = seq;  
    new_rear->next = NULL;  
    if (cust_queue_front == NULL)  
        cust_queue_front = new_rear;  
    else   
        cust_queue_rear->next = new_rear;  
    cust_queue_rear = new_rear;  
}  
  
void dequeue()  
{   
    if (cust_queue_front == NULL)  
    {  
        printf("ERROR: empty queue.");  
    }  
    else   
    {  
        struct customer *p = cust_queue_front;  
        cust_queue_front = cust_queue_front->next;  
        free(p);  
    }  
}  
  
void start_cycle(int num_newcust, int *num_seq)  
{  
    int i;  
    for (i = 0; i < num_newcust; i++)  
    {  
        enqueue(*num_seq);  
        (*num_seq)++;  
    }  

    int len_queue;  
    if (cust_queue_front != NULL) 
    	len_queue = cust_queue_rear->num_seq - cust_queue_front->num_seq + 1;  
    else 
    	len_queue = 0;  
    if (len_queue / num_window >= 7)  
    {  
        if (len_queue / (num_window + 1) < 7)  
        {  
            if(num_window <= 4) 
            	(num_window)++;  
        }  
        else   
        {  
            num_window = 5;  
        }  
    }  
}  
  
void finish_cycle()  
{
    int i;  
    for (i = 0; i < num_window; i++)  
    {  
        if (cust_queue_front != NULL)  
        {  
            lenlist[cust_queue_front->num_seq - 1] = cust_queue_front->len_wait;  
            dequeue();  
        }  
    }  
 
    struct customer *current = cust_queue_front;  
    if (cust_queue_front != NULL)  
    {  
        for (;;)  
        {  
            current->len_wait++;  
            if (current == cust_queue_rear) 
            	break;  
            else 
            	current = current->next;  
        }  
    }  

    int len_queue;  
    if (cust_queue_front != NULL) 
    	len_queue = cust_queue_rear->num_seq - cust_queue_front->num_seq + 1;  
    else 
    	len_queue = 0;  
    if ( len_queue / (num_window) < 7 && num_window > 3) 
    	num_window--;  
}  
  
int main()  
{  
    int num_cycle, num_newcust, num_seq = 1, num_cust = 0;  
    scanf("%d",&num_cycle);  
    for (;;)  
    {  
        scanf("%d",&num_newcust);  
        num_cust += num_newcust;  
        start_cycle(num_newcust, &num_seq);  
        finish_cycle();  
        num_cycle--;  
        if (num_cycle == 0)  
        {  
            while (cust_queue_front != NULL)  
                finish_cycle();  
            break;  
        }  
    }  
    int i;  
    for (i = 0; i < num_cust; i++)  
        printf("%d : %d\n",i+1,lenlist[i]);  
    return 0;  
}  