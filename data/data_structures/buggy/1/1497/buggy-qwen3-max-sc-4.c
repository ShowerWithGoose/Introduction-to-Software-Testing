#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int N;
int used[10]= {0};
int row; // @@ [row is declared as an integer, but it should be an array to store the current permutation]

void print_int_arrary(int a[])
{
  for (int i=0; i<N; i++)
  {
      printf("%d ",a[i]);
  }
  printf("\n");
}


void stand_in_asc_line(int j,int k)
{
    if (k==0) {
        print_int_arrary(row); // @@ [passing 'row' (an int) where an int array is expected; this causes type mismatch and undefined behavior]
        return;
    }
    for (int i=1; i<=N; i++)
        if (used[i] ==0) 
            {
               used[i] = 1;
               row[j] = i; // @@ [attempting to index 'row' as an array, but 'row' is declared as a scalar int]
               stand_in_asc_line(j+1,k-1);
               used[i] = 0;
            }
}

int main()
{
    scanf("%d",&N);
    stand_in_asc_line(0,N);
    return 0;
}