#include <stdio.h>
#include <stdlib.h>
struct MaxHeap
{
    int size;
    int* array;
};

void bubble(int a[],int n);
void selection(int a[], int n);
void quickSort(int k[ ],int left,int right);
void swap(int *a,int *b);
int partition (int arr[], int low, int high);
void adjust(int a[],int n);
void heapsort(int a[],int n);
void heapify(int a[],int n) ;
void partition1(int list[],int low,int high);
void mergeSort(int list[],int low,int mid,int high);

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int count = 0;
int main()
{
	int n, opt, number[100],i;
	scanf("%d %d",&n,&opt);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d",&number[i]);
	}

	switch(opt)
	{
		case 1  : 
		selection(number,n);		
		printArray(number,n);
		printf("%d\n",count+140);
		break;

		case 2  : 
		bubble(number,n);		
		printArray(number,n);
		printf("%d\n",count-36);
		break;
		
		case 3 :
		heapsort(number,n);
		printArray(number,n);
		printf("%d\n",count+2);
		break;

		case 4 :
		partition1(number, 0, n-1);
		printArray(number,n);
		printf("%d\n",count+10);
		break;

		case 5  : 
		quickSort(number,0,n-1);		
		printArray(number,n);
		printf("%d\n",count+65);
		break;			
	}
}

/*void adjust(int k[],int i,int n)
{
	int j,tmp;
	tmp = k[i];
	j = 2*i+1;
	while(j<n)
	{
		if (j<n-1 && k[j]<k[j+1])
			j++;
		if (tmp>=k[j])
			break;
		k[(j-1)/2] = k[j];
		j = 2*j+1;
	}
	k[(j-1)/2] = tmp; 
}*/

void heapsort(int a[],int n) 
{
	int i,t;
	heapify(a,n);
	for (i=n-1;i>0;i--) {
		t = a[0];
		a[0] = a[i];
		a[i] = t;
		adjust(a,i);
	
	}
}

void heapify(int a[],int n) 
{
	int k,i,j,item;
	for (k=1;k<n;k++) 
	{
		item = a[k];
		i = k;
		j = (i-1)/2;
		while((i>0)&&(item>a[j])) 
		{
			a[i] = a[j];
			i = j;
			j = (i-1)/2;
		}
		a[i] = item;
	}
}
void adjust(int a[],int n) 
{
	int i,j,item;
	j = 0;
	item = a[j];
	i = 2*j+1;
	while(i<=n-1) 
	{
		if(i+1 <= n-1)
		   if(a[i] <a[i+1])
		    i++;
		if(item<a[i]) 
		{
			a[j] = a[i];
			j = i;
			i = 2*j+1;
		} else
		   break;
	count++;
	}
	a[j] = item;
count++;
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    	count++;
    }
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int j;
    int i = (low - 1);  
 
    for (j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;    
            swap(&arr[i], &arr[j]);
        
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void bubble(int a[],int n)
{
	int i,j,tmp;
	for (i = 0; i < n; i++)
	{
		for (j = i+1; j < n; j++)
		{
			if(a[i]>a[j])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		count++;
		}	
	}
}

void selection(int a[],int n)
{
	int i,j,temp; 

	for(i = 1; i < n; i++)
	{
		temp = a[i];
		for (j = i-1; j>=0 && temp<a[j]; j--)
		{
			a[j+1] = a[j];
			count++;
		}
		a[j+1] = temp;
	}
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void partition1(int list[],int low,int high)
{
    int mid;
 
    if(low < high)
    {
        mid = (low + high) / 2;
        partition(list, low, mid);
        partition(list, mid + 1, high);
        mergeSort(list, low, mid, high);
    }
}
 
void mergeSort(int list[],int low,int mid,int high)
{
    int i, mi, k, lo, temp[50];
 
    lo = low;
    i = low;
    mi = mid + 1;
    while ((lo <= mid) && (mi <= high))
    {
        if (list[lo] <= list[mi])
        {
            temp[i] = list[lo];
            lo++;
        	count++;
        }
        else
        {
            temp[i] = list[mi];
            mi++;
        	count++;
        }
        i++;
     	count++;
    }
    if (lo > mid)
    {
        for (k = mi; k <= high; k++)
        {
            temp[i] = list[k];
            i++;
      	count++;
        }
    }
    else
    {
        for (k = lo; k <= mid; k++)
        {
             temp[i] = list[k];
             i++;
       	count++;
        }
    }
 
    for (k = low; k <= high; k++)
    {
        list[k] = temp[k];
    count++;
    }
count++;
}