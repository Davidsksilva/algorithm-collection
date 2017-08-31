#include <stdio.h>

void createHeap(int arr[],int i, int h)
{
	int aux = arr[i];
	int j= i * 2 +1;
	
	while(j <= h) // Enquanto o indice do filho não passar do indice máximo
	{
		if(j < h) // Tem filho?
		{
			if(arr[j] < arr[j+1]) // Esse filho é o maior dos 2?
				j=j+1; // O outro filho é maior
		}
		if(aux < arr[j]) // Pai é menor que o maior filho?
		{
			arr[i] = arr[j]; // Filho vira pai
			i=j; // Analizar os filhos do novo pai, como alterou, ver se está balanceado tambem
			j=2*i+1;
		}
		else
			j=h+1; // Sair do while
	}
	arr[i]= aux; // Antigo pai ocupa lugar do ultimo filho analisado
}
void heapSort(int arr[],int n)
{
	int i,aux;
	for(i=(n-1)/2;i>=0;i--)
		createHeap(arr,i,n-1);
	for(i=n-1;i>=1;i--)
	{
		aux = arr[0];
		arr[0]= arr[i];
		arr[i]=aux;
		createHeap(arr,0,i-1);
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
	heapSort(array,5);
	printArray(array,5);
	
	
	return 0;
}
 
