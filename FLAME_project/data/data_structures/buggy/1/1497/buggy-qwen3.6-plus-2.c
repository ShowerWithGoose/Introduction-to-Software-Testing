#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int N;
int used[10]= {0};
int row; // @@ [Error: 'row' is declared as a single integer, but it is used as an array in 'stand_in_asc_line' and 'print_int_arrary'. It should be declared as an array, e.g., 'int row[10];']

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
        print_int_arrary(row); // @@ [Error: 'row' is an int, not an array/pointer. Passing it to 'print_int_arrary' which expects 'int*' causes a type mismatch. This will be fixed if 'row' is declared as an array.]
        return;
    }
    for (int i=1; i<=N; i++)
        if (used[i] ==0) 
            {
               used[i] = 1;
               row[j] = i; // @@ [Error: 'row' is an int, so 'row[j]' is invalid syntax. Subscript operator cannot be applied to a non-array/non-pointer type. This will be fixed if 'row' is declared as an array.]
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