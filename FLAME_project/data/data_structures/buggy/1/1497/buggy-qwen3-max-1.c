#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int N;
int used[10]= {0};
int row; // @@ [row is declared as an integer, but it should be an array to store the current permutation. This causes errors when trying to index it like an array (e.g., row[j] = i) and when passing it to print_int_arrary which expects an int*.]

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
        print_int_arrary(row); // @@ [passing 'row' which is an int, not an int array. This causes a type mismatch error because print_int_arrary expects a pointer to int.]
        return;
    }
    for (int i=1; i<=N; i++)
        if (used[i] ==0) 
            {
               used[i] = 1;
               row[j] = i; // @@ [attempting to use 'row' as an array, but it's declared as a single integer, leading to a compilation error: subscripted value is neither array nor pointer.]
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