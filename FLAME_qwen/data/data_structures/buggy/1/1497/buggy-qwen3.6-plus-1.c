#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int N;
int used[10]= {0};
int row; // @@ row is declared as a single integer but is used as an array in row[j] = i and passed to print_int_arrary. It should be declared as an array, e.g., int row[10];

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
        print_int_arrary(row);
        return;
    }
    for (int i=1; i<=N; i++)
        if (used[i] ==0) 
            {
               used[i] = 1;
               row[j] = i;
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