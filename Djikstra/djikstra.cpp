#include <iostream>
#include<fstream>
#include <vector>
using namespace std;

int key[5]={4,5,6,2,1};

#define INF 214748364;

int getMatrixSize(const char* input)
{
  int n;
  ifstream f(input);
  f >> n;
  return n;
}

int** readMatrix( const int n, const char* input)
{
  int **arr;
  arr = new int*[n];
  for(int i = 0; i < n; i++)
    arr[i] = new int[n];
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      arr[i][j]=0;
  ifstream f(input);
  int data;
  f >> data;
  for(int i=0;i<n-1;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      f >> data;
      arr[i][j]=data;
      arr[j][i]=data;
    }
  }
  return arr;
}

struct vertex{
  int key;
  bool included;
  int parentID;
  int id;
};

void swap(struct vertex *x,struct vertex *y)
{
    int temp = x->key;
    x->key = x->key;
    y->key = temp;
}

void minHeapify(struct vertex * arr, int i,int heap_height)
{
  int l = 2*i+1;
  int r = 2*i+2;
  int min;

  if((l <= heap_height) && (arr[l].key < arr[i].key))
  {
    min=l;
  }
  else
    min=i;
  if((r<= heap_height)&&(arr[r].key<arr[min].key))
  {
    min=r;
  }
  if(min!= i)
    {
      swap(arr[i],arr[min]);
      minHeapify(arr,min,heap_height);
    }
}

void minHeap(struct vertex arr[],int n)
{
  for(int i=(n-1)/2;i>=0;i--)
		minHeapify(arr,i,n-1);
}

struct vertex extractMin(struct vertex arr[] , int* heap_height)
{
  struct vertex min = arr[0];
  arr[0] = arr[*heap_height-1];
  *heap_height-=1;
  minHeapify(arr,0,*heap_height);
  return min;
}
void decrease(struct vertex arr[] , int i, int key , int n , int idPai , int keyPai)
{
  for(int j=0;j<n;j++)
  {
    if(i == arr[j].id)
    {
      i=j;
      break;
    }
  }
  arr[i].key = key + keyPai;
  arr[i].parentID = idPai;
  while((i > 0) &&(arr[(i-1)/2].key > arr[i].key))
  {
    swap(arr[(i-1)/2], arr[i]);
    i = (i-1)/2;
  }
}
bool isInQueue(int id , struct vertex arr[] , int n )
{
  for(int i=0;i<n;i++)
  {
    if(id == arr[i].id)
      return true;
  }
  return false;
}
struct vertex returnVertex( int id, struct vertex arr[] , int n)
{
  for(int i=0;i<n;i++)
  {
    if(id == arr[i].id)
      return arr[i];
  }
   return arr[id];
}
void djikstra(int** arr , int n , int r)
{
  struct vertex V[n];

  for(int i=0;i<n;i++)
  {
    V[i].key = INF;
    V[i].parentID = -1;
    V[i].included = false;
    V[i].id = i;
  }
  V[r].key= 0;
  V[r].included = true;

  struct vertex Q[n];
  for(int i=0;i< n; i++)
    Q[i]=V[i];

  minHeap(Q, n);
  int nmatriz = n;
  while(n > 0) // while Q not empty
  {
    struct vertex u = extractMin(Q , &n );
    V[u.id]= u;
    for(int i=0;i<nmatriz; i++)
    {
      if(arr[u.id][i] != 0)
      {
        if( (isInQueue(i , Q , n)) && (arr[u.id][i]+ u.key < returnVertex(i , Q , n).key))
          {
            decrease(Q , i , arr[u.id][i] , n , u.id , u.key);
          }
      }
    }
  }
  int totalkeys=0;
  for(int i=0;i<nmatriz;i++)
  {
      cout<<"v: "<<V[i].id<<" pai: "<<V[i].parentID<<" key: "<<V[i].key<<endl;
      totalkeys+=V[i].key;
  }
  cout<<"Total keys: "<<totalkeys<<endl;

}
/*
FATHER(i) = i/2
LEFT(i) = 2i
RIGHT = 2i+1
*/
void printArray(int arr[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main()
{
  int n = getMatrixSize("teste.txt");
  int** arr;
  arr = readMatrix(n ,"teste.txt");
  djikstra(arr , n , 0);
  return 0;
}
