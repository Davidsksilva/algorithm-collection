#include <stdio.h>
#include <string.h>
#include <time.h>


void readFile(int arr[]) // Lê a lista de inteiros do arquivo
{
	FILE *file = fopen("couting.txt", "r");
	int integers[101];	
	int i=0;
	int num;
	while(fscanf(file, "%d", &num) > 0) {
		
		integers[i] = num;
        	i++;
	}
	fclose(file);
	
	i=0;
	for(i=0;i<101;i++)
		arr[i]=integers[i];

}

void printArray(int arr[], int n) // Printa todos os elementos do array
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");	
}

int getMaxDigit(int arr [], int n) // Retorna o maior número do array
{
	int max = arr[0];
	int i;
	for(i=1;i<n;i++)
	{
		if(arr[i]> max)
			max=arr[i];
	}

	return max;

}

void countSort(int arr [], int n)
{
	int max;
	max = getMaxDigit(arr,n); // Pega o maior número do array
	
	max+=1; // Soma um para poder criar um array com índice max
	int count[max];
	int i,j;
	
	for(j=0;j<(max);j++) // Inicia o array com 0
		count[j]=0;

	for(i=0;i<n;i++) // Conta quantas vezes cada número aparece
	{
		count[arr[i]]++;
	}

	i=0;

	for(i=1;i<(max);i++) // Faz com que os índices guardarem as posições dos números
	{
		count[i]+=count[i-1];
	}

	i=0;
	
	int output[n];

	for(i=n-1;i>=0;i--) // Escreve no array de saída, ordenando pelos inteiros
	{
		output[count[arr[i]]-1] = arr[i];
		count[arr[i]]-=1;	
	}

	i=0;

	for(i=0;i<n;i++) // Copia o array de saída para o de entrada
		arr[i]=output[i];
}



int main()
{
	int data[101];
	readFile(data);
	

	printf("Array desordenado: \n");
	printArray(data,101);
	printf("Array ordenado: \n");
	clock_t begin = clock();
	countSort(data,101);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printArray(data,101);
	printf("Tempo gasto para ordenar: %f segundos\n",time_spent);

	return 0;
}
