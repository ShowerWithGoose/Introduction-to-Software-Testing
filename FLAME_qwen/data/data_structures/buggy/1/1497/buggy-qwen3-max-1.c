#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int N;
int used[10]= {0};
int row; // @@ [row is declared as an integer, but it is used as an array in print_int_arrary(row) and row[j] = i;. This causes a compilation error because you cannot index an integer like an array.]

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
        print_int_arrary(row); // @@ [row is an int, not an array, so passing it to a function expecting int[] causes a type mismatch error.]
        return;
    }
    for (int i=1; i<=N; i++)
        if (used[i] ==0) 
            {
               used[i] = 1;
               row[j] = i; // @@ [Attempting to assign to row[j] where row is an int, not an array, leads to a compilation error.]
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