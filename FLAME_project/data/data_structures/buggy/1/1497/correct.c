#include <stdio.h>
#include <time.h>

int N;
int used[10]= {0, 0, 0, 0, 0,0,0,0,0,0};
int row[10];

//print line from row 
void print_int_arrary(int a[])
{
  for (int i=0; i<N; i++)
  {
      printf("%d ",a[i]);
  }
  printf("\n");
}

//
void stand_in_asc_line(int j,int k)
{
    if (k==0) {
        print_int_arrary(row);
        return;
    }
    for (int i=1; i<N+1; i++)
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
    clock_t start, end;
    start = clock();
    scanf("%d",&N);
    stand_in_asc_line(0,N);
    end = clock();
    double time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    // printf("time used = %f\n", time_used);    
    return 0;
}



