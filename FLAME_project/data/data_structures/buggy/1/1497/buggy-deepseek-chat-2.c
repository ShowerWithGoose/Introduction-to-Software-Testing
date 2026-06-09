#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int N;
int used[10]= {0};
int row; // @@ [Error: 'row' is declared as an int, but it should be an array to store the permutation. The code later uses 'row[j]' which requires 'row' to be an array or pointer.]

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
        print_int_arrary(row); // @@ [Error: 'row' is an int, not an array. Passing an int to a function expecting an int* causes a type mismatch and a warning/error.]
        return;
    }
    for (int i=1; i<=N; i++)
        if (used[i] ==0) 
            {
               used[i] = 1;
               row[j] = i; // @@ [Error: 'row' is an int, not an array or pointer. Subscripting an int is invalid and causes a compilation error.]
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