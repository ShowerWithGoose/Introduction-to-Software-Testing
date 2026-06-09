#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int N;
int used[10]= {0};
int row; // @@ [Error: 'row' is declared as a single integer, but it is used as an array in 'stand_in_asc_line' and passed to 'print_int_arrary'. It should be declared as an array, e.g., 'int row[10];']

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
        print_int_arrary(row); // @@ [Error: 'row' is an int, but 'print_int_arrary' expects an int array (pointer). This will cause a compilation error or undefined behavior. If 'row' is fixed to be an array, this line is correct.]
        return;
    }
    for (int i=1; i<=N; i++)
        if (used[i] ==0) 
            {
               used[i] = 1;
               row[j] = i; // @@ [Error: 'row' is declared as an int, so it cannot be subscripted with '[j]'. This causes the compilation error "subscripted value is neither array nor pointer nor vector".]
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