#include <stdio.h>

void swap(int* a, int *b)
{
	int temp = *a;
	*a=*b;
	*b= temp;
}

int organize(int arr[],int low, int high)
{
	int pivot= arr[high];
	int i= (low - 1);
	int j;

	for(j=low;j<=high-1;j++)
	{
		if(arr[j] <= pivot)
		{
			i++;
			swap(&arr[j],&arr[i]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return(i+1);
}

void quickSort(int arr[],int low, int high)
{
	if(low < high)
	{
		int p= organize(arr,low, high);

		quickSort(arr,low,p-1);
		quickSort(arr,p+1,high);
	}	
}

void printArray(int arr[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");	
}

int array[5]={1,3,2,7,5};

int main()
{
	printf("Array desordenado: \n");
	printArray(array,5);
	printf("Array ordenado: \n");
	quickSort(array,0,4);
	printArray(array,5);
	
	
	return 0;
}
 
