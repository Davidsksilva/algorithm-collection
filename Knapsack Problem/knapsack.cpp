#include <stdio.h>
#include <iostream>
#include<fstream>
#include <time.h>

using namespace std;

struct Knapsack{
  int n_;
  int M_;
  int* wt;
  int* val;
};

inline void getData(struct Knapsack* knapsack, std::string fileName) // Extrai os processos do arquivo. ( antigo )
{
  int aux=0;
  int line=0;
  int data;
  int n,m;
  std::ifstream f(fileName);
  f >> n;
  knapsack->n_=n;
  knapsack->wt= new int[n];
  knapsack->val= new int[n];
  f >> m;
  knapsack->M_= m;
  while(f >> data)
  {
      aux++;
      if((aux%2)==0)
      {
        knapsack->val[line]=data;
        line++;
      }
      else
      {
        knapsack->wt[line]=data;
      }
  }

}
typedef struct Table{
  int g;
  bool x;
}table;
// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b)? a : b; }

// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(const struct Knapsack* knapsack)
{
   int i, w;
   Table** K  = new Table*[knapsack->M_+1];
   for (int i = 0; i < knapsack->M_+1; ++i)
    K[i] = new Table[knapsack->n_+1];
  // Table K[knapsack->M_+1][knapsack->n_+1];
   // Build table K[][] in bottom up manner
   for (i = knapsack->n_; i >= 0 ; i--)
   {
       for (w = 0; w <=knapsack->M_ ; w++)
       {
           if (i==knapsack->n_|| w==0)
               K[w][i].g = 0;
           else if (knapsack->wt[i] <= w)
           {
             if(K[w][i+1].g > (knapsack->val[i] + K[w-knapsack->wt[i]][i+1].g))
             {
                K[w][i].g = K[w][i+1].g;
                K[w][i].x = false;
             }
             else
             {
               K[w][i].g = knapsack->val[i] + K[w-knapsack->wt[i]][i+1].g;
               K[w][i].x = true;
             }
           }
           else
           {
            K[w][i].g = K[w][i+1].g;
            K[w][i].x = false;
           }
       }
   }
   int bestValue = K[knapsack->M_][0].g;
   int b=0;
   int a=knapsack->M_;
   while(bestValue > 0)
   {
     if(!K[a][b].x)
     {
       b++;
     }
     else
     {
       cout<<"Product "<<b<<" used: "<<knapsack->wt[b]<<" "<<knapsack->val[b]<<endl;
       a=a - knapsack->wt[b];
       bestValue-= knapsack->val[b];
       b++;
     }
   }
   return K[knapsack->M_][0].g;
}

int main()
{
    struct Knapsack knapsack;
    getData(&knapsack,"input.txt");
    clock_t begin = clock();
    cout<<"Total profit with the knapsack: "<<knapSack(&knapsack)<<endl;
    clock_t end = clock();
	  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Time spent to solve knapsack problem: %f seconds\n",time_spent);
    return 0;
}
