#include <stdio.h>

void insertionSort(int arr[],int n)
{
	int i,a,j,temp;
	for(i = 0;i < n ;i++)
	{
		j=i;
		while( (j > 0) && (arr[j] < arr[j-1])){
			temp = arr[j];
			arr[j]=arr[j-1];
			arr[j-1]=temp;
			j=j-1;
		}	
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
	printArray(array,5);
	insertionSort(array,5);
	printArray(array,5);
	
	
	return 0;
}
