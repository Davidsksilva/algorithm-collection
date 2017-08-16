#include <stdio.h>

void selectionSort(int arr[],int n)
{
	int i,a,j,temp;
	for(i = 0;i < n ;i++)
	{
		a=i;
		for(j=i+1;j < n;j++)
		{
			if(arr[j] < arr[a])
				a=j;
		}
		temp= arr[i];
		arr[i]= arr[a];
		arr[a]= temp;	
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
	selectionSort(array,5);
	printArray(array,5);
	
	
	return 0;
}
